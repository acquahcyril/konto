#include "renderer/renderer.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <cstdlib>

#define PROJECT "konto"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGTH 450

void framebuffer_resize(GLFWwindow *window, int width, int height);

int main(const int argc, const char *argv[]) {
  glfwInit();
  glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  GLFWwindow *window =
      glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGTH, PROJECT, nullptr, nullptr);
  if (window == nullptr) {
    glfwTerminate();
    return EXIT_FAILURE;
  }
  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    glfwDestroyWindow(window);
    return EXIT_FAILURE;
  }
  glfwSetWindowSizeCallback(window, framebuffer_resize);
  glfwSetFramebufferSizeCallback(window, framebuffer_resize);

  kt::Renderer renderer;

  renderer.Init();
  while (!glfwWindowShouldClose(window)) {
    renderer.Clear();
    renderer.DrawQuad(glm::vec3{0.0f, 1.0f, 1.0f}, glm::vec2{0.5f},
                      glm::vec4{1.0f, 0.0f, 0.0f, 1.0f});
    renderer.DrawQuad(glm::vec3{0.0f, 1.0f, -1.0f}, glm::vec2{1.5f},
                      glm::vec4{1.0f, 0.0f, 0.0f, 1.0f});
    renderer.DrawQuad(glm::vec3{0.0f, -1.0f, -1.0f}, glm::vec2{0.75f},
                      glm::vec4{1.0f, 0.0f, 0.0f, 1.0f});
    renderer.DrawQuad(glm::vec3{-1.0f, 0.0f, 1.0f}, glm::vec2{1.0f},
                      glm::vec4{1.0f, 0.0f, 1.0f, 1.0f});
    renderer.DrawQuad(glm::vec3{0.0f, -2.0f, -10.0f}, glm::vec2{1.0f},
                      glm::vec4{.0f, 0.0f, 0.0f, 1.0f});
    renderer.DrawQuad(glm::vec3{-10.0f, -10.0f, 0.0f}, glm::vec2{1.0f},
                      glm::vec4{1.0f, 0.0f, 0.0f, 1.0f});
    renderer.DrawQuad(glm::vec3{0.0f, 0.0f, 10.0f}, glm::vec2{1.0f},
                      glm::vec4{1.0f, 0.0f, 0.0f, 1.0f});
    renderer.ClearBatch();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  return EXIT_SUCCESS;
}

void framebuffer_resize(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}
