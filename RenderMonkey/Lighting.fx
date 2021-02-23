string LIghting_Pass_0_Model : ModelData = "..\\..\\..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Models\\Sphere.3ds";

float4x4 gWorldMatrix : World;
float4x4 gViewMatrix : View;
float4x4 gProjectionMatrix : Projection;
float4   gWorldLightPosition
<
   string UIName = "gWorldLightPosition";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 500.00, 500.00, -500.00, 1.00 );
float4   gWorldCameraPosition : ViewPosition;

struct VS_INPUT 
{
   float4 mPosition : POSITION0;
   float3 mNormal : NORMAL;
};

struct VS_OUTPUT 
{
   float4 mPosition : POSITION0;
   float3 mDiffuse : TEXCOORD1;
   float3 mViewDir : TEXCOORD2;
   float3 mReflection : TEXCOORD3;
};

VS_OUTPUT LIghting_Pass_0_Vertex_Shader_vs_main( VS_INPUT Input )
{
   VS_OUTPUT Output;

   Output.mPosition = mul( Input.mPosition, gWorldMatrix );
   float3 lightDir = Output.mPosition.xyz - gWorldLightPosition.xyz;
   lightDir = normalize(lightDir);
   
   float3 viewDir = normalize(Output.mPosition.xyz - gWorldCameraPosition.xyz );
   Output.mViewDir = viewDir;
   
   Output.mPosition = mul( Output.mPosition, gViewMatrix );
   Output.mPosition = mul( Output.mPosition, gProjectionMatrix );
   
   float3 worldNormal = mul(Input.mNormal , (float3x3) gWorldMatrix);
   worldNormal = normalize(worldNormal);
   Output.mDiffuse = dot(-lightDir, worldNormal);
   Output.mReflection = reflect(lightDir, worldNormal);
   return( Output );
   
}




struct PS_INPUT
{
   float3 mDiffuse : TEXCOORD1;
   float3 mViewDir : TEXCOORD2;
   float3 mReflection : TEXCOORD3;
};

float4 LIghting_Pass_0_Pixel_Shader_ps_main(PS_INPUT Input) : COLOR0
{   
   float3 diffuse = saturate(Input.mDiffuse);
   float3 reflection = normalize(Input.mReflection);
   float3 viewDir = normalize(Input.mViewDir);
   float3 specular = 0;
   if(diffuse.x > 0)
   {
      specular = saturate(dot(reflection, -viewDir));
      specular = pow(specular, 2.0f);
   }
   float3 ambient = float3(0.1f, 0.1f, 0.1f);
   
   return( float4( ambient + diffuse + specular, 1.0f ) );
   
}




//--------------------------------------------------------------//
// Technique Section for LIghting
//--------------------------------------------------------------//
technique LIghting
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 LIghting_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 LIghting_Pass_0_Pixel_Shader_ps_main();
   }

}
