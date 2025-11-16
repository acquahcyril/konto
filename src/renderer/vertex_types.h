#ifndef __QUAD_H__
#define __QUAD_H__

#include <cstdint>
#include <glm/glm.hpp>

namespace kt {

struct QuadVertex {
  uint32_t textureIndex{0};
  glm::vec4 color{1.0f};
  glm::vec3 position{};
  glm::vec2 textureCoordinate{};
};

} // namespace kt

#endif // !__QUAD_H__
