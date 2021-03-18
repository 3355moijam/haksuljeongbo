struct LightDesc 
{
    float4 Ambient;
    float4 Specular;
    float3 Direction;
    float Padding;
    float3 Position;
    // 16byte 단위로 가야해서 padding이 추가되어 사이즈를 맞춘 것. 
    // LightDesc를 배열 형태로 쓴다면 position 뒤에 padding2가 필요해진다.
};

cbuffer CB_Light
{
    LightDesc GlobalLight;
};

struct MaterialDesc
{
    float4 Ambient;
    float4 Diffuse;
    float4 Specular;
};

cbuffer CB_Material
{
    MaterialDesc Material;
};