#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "renderer/shader.h"
#include "renderer/texture.h"
#include "renderer/vertex_types.h"

#include <cstdint>
#include <glm/glm.hpp>

#define MAX_TEXTURES 32
#define MAX_QUADS 30000
#define MAX_INDICES MAX_QUADS * 6
#define MAX_VERTICES MAX_QUADS * 4

namespace kt {

class Renderer {
private:
  Shader quadShader{};
  uint32_t quadIndexCount{};
  uint32_t quadVertexCount{};
  uint32_t quadVertexArray{};
  uint32_t quadIndexBuffer{};
  uint32_t quadVertexBuffer{};
  uint32_t quadIndices[MAX_INDICES];
  uint32_t quadTextures[MAX_TEXTURES];
  QuadVertex quadVertices[MAX_VERTICES];

  Texture whiteTexture{};

  glm::mat4 ViewProjection{1.0f};

  const glm::vec4 quadVertexPositions[4] = {
      {-0.5f, -0.5f, 0.0f, 1.0f},
      {0.5f, -0.5f, 0.0f, 1.0f},
      {0.5f, 0.5f, 0.0f, 1.0f},
      {-0.5f, 0.5f, 0.0f, 1.0f},
  };

  uint32_t textures[MAX_TEXTURES];

public:
  void Init();
  void Clear();
  void ClearBatch();
  void DrawQuad(const glm::vec3 &position, const glm::vec2 &scale,
                const glm::vec4 &color);
};

} // namespace kt

#endif // !__RENDERER_H__
