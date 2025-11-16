#version 460 core

layout(location = 0) flat in uint TextureIndex;
layout(location = 1) in vec4 InputColor;
layout(location = 2) in vec3 Normal;
layout(location = 3) in vec3 Position;
layout(location = 4) in vec2 TextureCoordinate;

layout(location = 0) out vec4 Color;

#define MAX_TEXTURES  32

uniform sampler2D Textures[MAX_TEXTURES];

void main()
{
	if (InputColor.a == 0.0)
		discard;

  vec4 FinalColor = vec4(0.0f);
	
	switch(TextureIndex)
	{
		case  0: FinalColor *= texture(Textures[ 0], TextureCoordinate); break;
		case  1: FinalColor *= texture(Textures[ 1], TextureCoordinate); break;
		case  2: FinalColor *= texture(Textures[ 2], TextureCoordinate); break;
		case  3: FinalColor *= texture(Textures[ 3], TextureCoordinate); break;
		case  4: FinalColor *= texture(Textures[ 4], TextureCoordinate); break;
		case  5: FinalColor *= texture(Textures[ 5], TextureCoordinate); break;
		case  6: FinalColor *= texture(Textures[ 6], TextureCoordinate); break;
		case  7: FinalColor *= texture(Textures[ 7], TextureCoordinate); break;
		case  8: FinalColor *= texture(Textures[ 8], TextureCoordinate); break;
		case  9: FinalColor *= texture(Textures[ 9], TextureCoordinate); break;
		case 10: FinalColor *= texture(Textures[10], TextureCoordinate); break;
		case 11: FinalColor *= texture(Textures[11], TextureCoordinate); break;
		case 12: FinalColor *= texture(Textures[12], TextureCoordinate); break;
		case 13: FinalColor *= texture(Textures[13], TextureCoordinate); break;
		case 14: FinalColor *= texture(Textures[14], TextureCoordinate); break;
		case 15: FinalColor *= texture(Textures[15], TextureCoordinate); break;
		case 16: FinalColor *= texture(Textures[16], TextureCoordinate); break;
		case 17: FinalColor *= texture(Textures[17], TextureCoordinate); break;
		case 18: FinalColor *= texture(Textures[18], TextureCoordinate); break;
		case 19: FinalColor *= texture(Textures[19], TextureCoordinate); break;
		case 20: FinalColor *= texture(Textures[20], TextureCoordinate); break;
		case 21: FinalColor *= texture(Textures[21], TextureCoordinate); break;
		case 22: FinalColor *= texture(Textures[22], TextureCoordinate); break;
		case 23: FinalColor *= texture(Textures[23], TextureCoordinate); break;
		case 24: FinalColor *= texture(Textures[24], TextureCoordinate); break;
		case 25: FinalColor *= texture(Textures[25], TextureCoordinate); break;
		case 26: FinalColor *= texture(Textures[26], TextureCoordinate); break;
		case 27: FinalColor *= texture(Textures[27], TextureCoordinate); break;
		case 28: FinalColor *= texture(Textures[28], TextureCoordinate); break;
		case 29: FinalColor *= texture(Textures[29], TextureCoordinate); break;
		case 30: FinalColor *= texture(Textures[30], TextureCoordinate); break;
		case 31: FinalColor *= texture(Textures[31], TextureCoordinate); break;
    }

	Color = vec4(FinalColor.rgb, InputColor.a);
}

