#ifndef __SHADER_H__
#define __SHADER_H__

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <cstdint>
#include <string>

namespace kt {

class Shader {
public:
  ~Shader();
  void CreateShader(const std::string &vertexShaderSource,
                    const std::string &fragmentShaderSource);

  void Bind();
  void UnBind();
  void SetUniform(const std::string &name, uint32_t value);
  void SetUniform(const std::string &name, const glm::vec3 &value);
  void SetUniform(const std::string &name, const glm::mat4 &value);
  void SetUniform(const std::string &name, const uint32_t *value,
                  size_t length);
  template <typename T, size_t length>
  void SetUniformBuffer(uint32_t bufferId, const T *buffer) {
    glBindBuffer(GL_UNIFORM_BUFFER, bufferId);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, length * sizeof(T), buffer);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
  }
  template <typename T, size_t length>
  void createUniformBuffer(const std::string &name, uint32_t bindingPoint,
                           uint32_t &bufferId) {
    glGenBuffers(1, &bufferId);
    glBindBuffer(GL_UNIFORM_BUFFER, bufferId);
    glBufferData(GL_UNIFORM_BUFFER, length * sizeof(T), nullptr,
                 GL_DYNAMIC_DRAW);
    const auto index = glGetUniformBlockIndex(shaderProgram, name.c_str());
    glUniformBlockBinding(shaderProgram, index, bindingPoint);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    glBindBufferRange(GL_UNIFORM_BUFFER, bindingPoint, bufferId, 0,
                      length * sizeof(T));
  }

private:
  uint32_t shaderProgram{};
};

}; // namespace kt

#endif // !_SHADER_H__
