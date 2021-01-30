#include "Window.h"




Window::Window() {
	width = 800;
	height = 600;
}

Window::Window(GLint windowWidth, GLint windowHeight) {
	width = windowWidth;
	height = windowHeight;
}

int Window::Initialise() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "GLFW linking Failed" << std::endl;
        glfwTerminate();
        return -1;
    }
    //Setting GLFW windows Property, OPenGL Versions 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //Core profile = No Backward Compactibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //Window is pointer to GLFWwindow. (Variable)
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    if (!window)
    {
        std::cout << "GLFW WINDOW CREATION FAILED" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Get Buffer Size Information
    int bufferwidth, bufferheight;
    glfwGetFramebufferSize(window, &bufferwidth, &bufferheight);
    // set context for GLEW to use.
    // Means if you have multiple windows the you can choose the....  
    //....working window like that
    glfwMakeContextCurrent(window);

    //Allow modern extension the features
    //This glewExperimental unleashes the power to use more exiciting things
    //.... to use in opengl.
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        printf("the linking failed of Glew");
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }
    glEnable(GL_DEPTH_TEST); //Depth test enable
    //Set Viewport
    glViewport(0, 0, bufferwidth, bufferheight);

}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();

}