#include "Window.h"

Window::Window()
{
	width = 1080;
	height = 720;
	for (size_t i = 0; i < 1024; i++) {
		keys[i] = 0;
	}
	//Just to remove the garbage value from the xchnage and ychange
	xChange = 0.0f;
	yChange = 0.0f;
}

Window::Window(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;
	for (size_t i = 0; i < 1024; i++) {
		keys[i] = 0;
	}
}

int Window::Initialise()
{
	if (!glfwInit())
	{
		printf("Error Initialising GLFW");
		glfwTerminate();
		return 1;
	}

	// Setup GLFW Windows Properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core Profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow forward compatiblity
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create the window
	mainWindow = glfwCreateWindow(width, height, "Test Window", NULL, NULL);
	if (!mainWindow)
	{
		printf("Error creating GLFW window!");
		glfwTerminate();
		return 1;
	}

	// Get buffer size information
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set the current context
	glfwMakeContextCurrent(mainWindow);

	//Handle Key+ mouse Inputs
	createCallbacks();
	//glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Allow modern extension access
	glewExperimental = GL_TRUE;

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		printf("Error: %s", glewGetErrorString(error));
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST);

	// Create Viewport
	glViewport(0, 0, bufferWidth, bufferHeight);

	//camera
	//this is for glfw callback
	glfwSetWindowUserPointer(mainWindow, this);
}


//keys handling here...
void Window::createCallbacks() {
	glfwSetKeyCallback(mainWindow,handleKeys);
	glfwSetCursorPosCallback(mainWindow, handleMouse);

}

GLfloat Window::getXchange() {
	GLfloat thechange = xChange;
	xChange = 0.0f;
	return thechange;
}

GLfloat Window::getYchange() {
	GLfloat thechange = yChange;
	yChange = 0.0f;
	return thechange;
}

void Window::handleKeys(GLFWwindow* window, int key, int code, int action, int mode) {

	Window* thewindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	if (key >= 0 && key < 1024) {
		if (action == GLFW_PRESS) {
			thewindow->keys[key] = true;
			//printf("pressed: %d\n", key);
		}
		else if (action == GLFW_RELEASE) {
			thewindow->keys[key] = false;
			//printf("Released: %d\n", key);

		}
	}
}
void Window::handleMouse(GLFWwindow* window, double xpos, double ypos) {
	Window* thewindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (thewindow->mouseFirstMoved) {
		thewindow->lastX = xpos;
		thewindow->lastY = ypos;
		thewindow->mouseFirstMoved = false;

	}
	thewindow->xChange = xpos - thewindow->lastX;
	thewindow->yChange = thewindow->lastY - ypos;


	thewindow->lastX = xpos;
	thewindow->lastY = ypos;

	//printf("x:%6f, y:%6f\n",thewindow->xChange,thewindow->yChange);



}

Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}
