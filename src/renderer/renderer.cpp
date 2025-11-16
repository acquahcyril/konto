#include "renderer/renderer.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#define DEBUG

#ifdef DEBUG
void HandleOpenGLDebugCallback(GLenum source, GLenum type, GLuint id,
                               GLenum severity, GLsizei length,
                               const GLchar *message, const void *useParam) {
  if (type == GL_DEBUG_TYPE_ERROR) {
    std::cerr << "[ERROR] => (OpenGL) :: " << message << std::endl;
  } else {
    std::cout << "[DEBUG] -> (OpenGL) :: " << message << std::endl;
  }
}
#endif // DEBUG

namespace kt {

void Renderer::Init() {
  uint32_t offset = 0;
  for (uint32_t i = 0; i < MAX_INDICES; i += 6) {
    quadIndices[i + 0] = offset + 0;
    quadIndices[i + 1] = offset + 1;
    quadIndices[i + 2] = offset + 2;
    quadIndices[i + 3] = offset + 2;
    quadIndices[i + 4] = offset + 3;
    quadIndices[i + 5] = offset + 0;
    offset += 4;
  }
#ifdef DEBUG
  glEnable(GL_DEBUG_OUTPUT);
  glDebugMessageCallback(HandleOpenGLDebugCallback, 0);
#endif // DEBUG
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_LINE_SMOOTH);
  glClearDepth(1.0f);
  glGenVertexArrays(1, &quadVertexArray);
  glGenBuffers(1, &quadVertexBuffer);
  glGenBuffers(1, &quadIndexBuffer);
  glBindVertexArray(quadVertexArray);
  glBindBuffer(GL_ARRAY_BUFFER, quadVertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices,
               GL_DYNAMIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quadIndexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadIndices), quadIndices,
               GL_STATIC_DRAW);
  glVertexAttribIPointer(
      0, 1, GL_UNSIGNED_INT, sizeof(QuadVertex),
      reinterpret_cast<void *>(offsetof(QuadVertex, textureIndex)));
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(QuadVertex),
                        reinterpret_cast<void *>(offsetof(QuadVertex, color)));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(
      2, 3, GL_FLOAT, GL_FALSE, sizeof(QuadVertex),
      reinterpret_cast<void *>(offsetof(QuadVertex, position)));
  glEnableVertexAttribArray(2);
  glVertexAttribPointer(
      3, 2, GL_FLOAT, GL_FALSE, sizeof(QuadVertex),
      reinterpret_cast<void *>(offsetof(QuadVertex, textureCoordinate)));
  glEnableVertexAttribArray(3);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
  quadShader.CreateShader(
      R"(
#version 460 core

layout(location = 0) in uint TextureIndex;
layout(location = 1) in vec4 Color;
layout(location = 2) in vec3 Position;
layout(location = 3) in vec2 TextureCoordinate;

layout(location = 0) flat out uint OutputTextureIndex;
layout(location = 1) out vec4 OutputColor;
layout(location = 2) out vec2 OutputTextureCoordinate;

void main()
{
  vec4 WordPostion = vec4(Position, 1.0f);
	OutputColor = Color;
	OutputTextureIndex = TextureIndex;
	OutputTextureCoordinate = TextureCoordinate;
	gl_Position = WordPostion;
}
)",
      R"(
#version 460 core

layout(location = 0) flat in uint TextureIndex;
layout(location = 1) in vec4 InputColor;
layout(location = 2) in vec2 TextureCoordinate;

layout(location = 0) out vec4 Color;

#define MAX_TEXTURES  32

uniform sampler2D Textures[MAX_TEXTURES];

void main()
{
	if (InputColor.a == 0.0)
		discard;

  vec4 FinalColor = InputColor;
	
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
)");
  uint32_t whiteTextureData = 0xffffffff;
  whiteTexture.CreateTexture(&whiteTextureData, 1, 1, 3);
  for (int i = 0; i < 32; i++) {
    whiteTexture.Bind(i);
    textures[i] = whiteTexture.GetId();
  }
  quadShader.Bind();
}

void Renderer::Clear() {
  glClearColor(0.1f, 0.1f, 0.1f, 0.9f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::ClearBatch() {
  if (quadVertexCount && quadIndexCount) {
    whiteTexture.Bind(0);
    quadShader.Bind();
    glBindVertexArray(quadVertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, quadVertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(QuadVertex) * quadVertexCount,
                 quadVertices, GL_DYNAMIC_DRAW);
    glDrawElements(GL_TRIANGLES, quadIndexCount, GL_UNSIGNED_INT, nullptr);
  }
  quadIndexCount = 0;
  quadVertexCount = 0;
}

void Renderer::DrawQuad(const glm::vec3 &position, const glm::vec2 &scale,
                        const glm::vec4 &color) {
  constexpr glm::vec2 textureCoords[] = {
      {0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f}};

  if (quadIndexCount >= MAX_INDICES)
    ClearBatch();
  glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) *
                        glm::scale(glm::mat4(1.0f), {scale.x, scale.y, 1.0f});
  for (int i = 0; i < 4; i++) {
    auto currentQuadVertexPosition = quadVertexCount + i;
    auto currentPosition = transform * quadVertexPositions[i];
    quadVertices[currentQuadVertexPosition].position = {
        currentPosition.x, currentPosition.y, currentPosition.z};
    quadVertices[currentQuadVertexPosition].color = color;
    quadVertices[currentQuadVertexPosition].textureIndex = 0;
    quadVertices[currentQuadVertexPosition].textureCoordinate =
        textureCoords[i];
  }

  quadIndexCount += 6;
  quadVertexCount += 4;
}

} // namespace kt
