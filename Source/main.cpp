#include <iostream>
#include <GLFW/glfw3.h>

/*
 * This is the start of NMC.
 *
 * @return Process error code.
 */
int main() {
  std::cout << "Initializing NMC..." << std::endl;
  if (!glfwInit()) {
    std::cout << "Could not initialize OpenGL!";
    return -1;
  }
  GLFWwindow* window = glfwCreateWindow(854, 480, "(NOT) Minecraft 1.18.1", NULL, NULL);
  if (!window) {
    glfwTerminate();
    std::cout << "Could not create window, exitting!";
    return -2;
  }
  glfwMakeContextCurrent(window);
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}