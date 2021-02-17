//**************************************************************//
//  Effect File exported by RenderMonkey 1.6
//
//  - Although many improvements were made to RenderMonkey FX  
//    file export, there are still situations that may cause   
//    compilation problems once the file is exported, such as  
//    occasional naming conflicts for methods, since FX format 
//    does not support any notions of name spaces. You need to 
//    try to create workspaces in such a way as to minimize    
//    potential naming conflicts on export.                    
//    
//  - Note that to minimize resulting name collisions in the FX 
//    file, RenderMonkey will mangle names for passes, shaders  
//    and function names as necessary to reduce name conflicts. 
//**************************************************************//

//--------------------------------------------------------------//
// Nebula
//--------------------------------------------------------------//
//--------------------------------------------------------------//
// Pass 0
//--------------------------------------------------------------//
string Nebula_Pass_0_Model : ModelData = ".\\Sphere.x";

float4x4 WorldITXf : WorldInverseTranspose;
float4x4 WvpXf : WorldViewProjection;
float4x4 WorldXf : World;
float4x4 ViewITXf : ViewInverseTranspose;
float4x4 ViewIXf;
float4x4 WorldViewXf;

float Scale
<
   string UIName = "Scale";
   string UIWidget = "Numeric";
   bool UIVisible =  false;
   float UIMin = 0.00;
   float UIMax = 2.00;
> = float( 0.00 );
float4x4 NebXf
<
   string UIName = "NebXf";
   string UIWidget = "Numeric";
   bool UIVisible =  false;
> = float4x4( 2.00, -2.00, -2.00, 0.00, -2.00, -2.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 1.00 );
struct VS_INPUT 
{
    float3 Position    : POSITION;
    float4 UV        : TEXCOORD0;
    float4 Normal    : NORMAL;
    float4 Tangent    : TANGENT0;
    float4 Binormal    : BINORMAL0;
   
};

struct VS_OUTPUT 
{
    float4 HPosition    : POSITION;
    float2 UV    : TEXCOORD0;
    float3 WorldNormal    : TEXCOORD1;
    float3 WorldEyeVec    : TEXCOORD2;
    float3 WorldTangent    : TEXCOORD3;
    float3 WorldBinorm    : TEXCOORD4;
    float4 NebCoords    : TEXCOORD5;
   
};

VS_OUTPUT Nebula_Pass_0_Vertex_Shader_vs_main( VS_INPUT Input )
{
   VS_OUTPUT OUT = (VS_OUTPUT)0;
    OUT.WorldNormal = mul(Input.Normal,WorldITXf).xyz;
    OUT.WorldTangent = mul(Input.Tangent,WorldITXf).xyz;
    OUT.WorldBinorm = mul(Input.Binormal,WorldITXf).xyz;
    float4 Po = float4(Input.Position.xyz,1.0);
    float4 Pw = mul(Po,WorldXf);
    float4 Pu = mul(Pw,NebXf);   // P in "user coords"
    // OUT.LightVec = (LightPos - Pw.xyz);
    OUT.UV = Input.UV.xy;
    OUT.WorldEyeVec = normalize(ViewITXf[3].xyz - Pw.xyz);
    OUT.HPosition = mul(Po,WvpXf);
    OUT.NebCoords = float4((Scale*Pu.xyz)+float3(0.5,0.5,0.5),1.0);
    return OUT;
   
}




texture nebTexture_Tex
<
   string ResourceName = ".\\NebulaLight\\textures\\NebX.dds";
>;
sampler2D nebSamp = sampler_state
{
   Texture = (nebTexture_Tex);
};

struct PS_INPUT 
{
    float4 HPosition    : POSITION;
    float2 UV    : TEXCOORD0;
    float3 WorldNormal    : TEXCOORD1;
    float3 WorldEyeVec    : TEXCOORD2;
    float3 WorldTangent    : TEXCOORD3;
    float3 WorldBinorm    : TEXCOORD4;
    float4 NebCoords    : TEXCOORD5;
   
};

float4 Nebula_Pass_0_Pixel_Shader_ps_main(PS_INPUT Input) : COLOR0
{   
   float4 nc = tex2D(nebSamp,Input.NebCoords.xy);
   float4 na = tex2D(nebSamp,Input.NebCoords.xz);
   float4 result = nc * na.w;
   return float4(result.rgb,1.0);
}




//--------------------------------------------------------------//
// Technique Section for Nebula
//--------------------------------------------------------------//
technique Nebula
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 Nebula_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 Nebula_Pass_0_Pixel_Shader_ps_main();
   }

}

