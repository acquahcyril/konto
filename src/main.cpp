#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <cstdlib>

#define PROJECT "konto"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGTH 450

void framebuffer_resize(GLFWwindow *window, int width, int height);

int main(const int argc, const char *argv[]) {
  glfwInit();
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
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  return EXIT_SUCCESS;
}

void framebuffer_resize(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}
