struct LightDesc 
{
    float4 Ambient;
    float4 Specular;
    float3 Direction;
    float Padding;
    float3 Position;
    // 16byte ������ �����ؼ� padding�� �߰��Ǿ� ����� ���� ��. 
    // LightDesc�� �迭 ���·� ���ٸ� position �ڿ� padding2�� �ʿ�������.
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