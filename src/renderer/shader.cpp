#include "renderer/shader.h"

#include <glm/gtc/type_ptr.hpp>

#include <iostream>

namespace kt {

Shader::~Shader() { glDeleteProgram(shaderProgram); }

void Shader::Bind() { glUseProgram(shaderProgram); }

void Shader::UnBind() { glUseProgram(0); }

void Shader::CreateShader(const std::string &vertexShaderSource,
                          const std::string &fragmentShaderSource) {
  const auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
  const auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const auto vertexShaderSourcePtr = vertexShaderSource.c_str();
  const auto fragmentShaderSourcePtr = fragmentShaderSource.c_str();
  glShaderSource(vertexShader, 1, &vertexShaderSourcePtr, nullptr);
  glShaderSource(fragmentShader, 1, &fragmentShaderSourcePtr, nullptr);
  int success{};
  char logs[512]{};
  glCompileShader(vertexShader);
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, nullptr, logs);
    std::cerr << logs << std::endl;
    return;
  }
  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, nullptr, logs);
    std::cerr << logs << std::endl;
    return;
  }
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, nullptr, logs);
    std::cerr << logs << std::endl;
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shader::SetUniform(const std::string &name, uint32_t value) {
  const auto location = glGetUniformLocation(shaderProgram, name.c_str());
  glUniform1ui(location, value);
}

void Shader::SetUniform(const std::string &name, const glm::vec3 &value) {
  const auto location = glGetUniformLocation(shaderProgram, name.c_str());
  glUniform3fv(location, 1, glm::value_ptr(value));
}

void Shader::SetUniform(const std::string &name, const glm::mat4 &value) {
  const auto location = glGetUniformLocation(shaderProgram, name.c_str());
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetUniform(const std::string &name, const uint32_t *value,
                        size_t length) {
  const auto location = glGetUniformLocation(shaderProgram, name.c_str());
  glUniform1iv(location, length, reinterpret_cast<const int *>(value));
}

} // namespace kt
