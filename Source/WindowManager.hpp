class WindowManager {
  public:
    WindowManager();
    ~WindowManager();
  private:
    void RenderEvent(), InputEvent();
    GLFWwindow* window;
};

void ResizeEvent(GLFWwindow* window, int width, int height);