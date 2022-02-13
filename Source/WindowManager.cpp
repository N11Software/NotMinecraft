#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "WindowManager.hpp"

/*
 * Create window and initialize OpenGL.
 */
WindowManager::WindowManager() {
  if (!glfwInit()) {
    std::cout << "Could not initialize OpenGL!";
    exit(-1);
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  window = glfwCreateWindow(854, 480, "(NOT) Minecraft 1.18.1", NULL, NULL);
  if (!window) {
    std::cout << "Could not create window, exiting!";
    this->~WindowManager();
    exit(-2);
  }
  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cout << "Could not initialize GLAD!" << std::endl;
    exit(-3);
  }
  glViewport(0, 0, 854, 480);
  glfwSetFramebufferSizeCallback(window, ResizeEvent);
  while (!glfwWindowShouldClose(window)) RenderEvent();
  this->~WindowManager();
}

/*
 * Destroy window.
 */
WindowManager::~WindowManager() {
  std::cout << "Shutting down..." << std::endl;
  glfwSetWindowShouldClose(window, true);
  glfwTerminate();
  exit(0);
}

/*
 * Render event:
 * This is called every frame.
 */
void WindowManager::RenderEvent() {
  InputEvent();
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glfwPollEvents();
  glfwSwapBuffers(window);
}

/*
 * InputEvent:
 * This is called when the user presses a key or moves the mouse.
 */
void WindowManager::InputEvent() {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) this->~WindowManager();
}

/*
 * Resize event:
 * This is called when the window is resized.
 */
void ResizeEvent(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}