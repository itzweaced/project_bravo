bool Mouse::cursor_active = false;
- Description: 

bool Mouse::scroll_active = false;
- Description: 

Mouse::Mouse(Graphics* setGraphics, float WINDOW_WIDTH, float WINDOW_HEIGHT)
- Description: 

void Mouse::mouse_callback(GLFWwindow *window, double xPos, double yPos)
- Description: 

void Mouse::scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
- Description: 