#version 460 core

layout(location = 0) in uint TextureIndex;
layout(location = 1) in vec4 Color;
layout(location = 2) in vec3 Normal;
layout(location = 3) in vec3 Position;
layout(location = 4) in vec2 TextureCoordinate;

layout(location = 0) flat out uint OutputTextureIndex;
layout(location = 1) out vec4 OutputColor;
layout(location = 2) out vec3 OutputNormal;
layout(location = 3) out vec3 OutputPosition;
layout(location = 4) out vec2 OutputTextureCoordinate;

uniform mat4 ViewProjection;

void main()
{
  vec4 WordPostion = ViewProjection * vec4(Position, 1.0f);
	OutputColor = Color;
	OutputNormal = Normal;
	OutputPosition = WordPostion.xyz;
	OutputTextureIndex = TextureIndex;
	OutputTextureCoordinate = TextureCoordinate;
	gl_Position = WordPostion;
}
