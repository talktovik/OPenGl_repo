// Open a window with GLFW, check default OpenGL version, set background color red
// Register callback functions for GLFW errors, key pressed and window resized events
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>

// Define a few callback functions:
void window_resized(GLFWwindow* window, int width, int height);
void key_pressed(GLFWwindow* window, int key, int scancode, int action, int mods);
void show_glfw_error(int error, const char* description);


int main() {
	// Register the GLFW error callback function
	glfwSetErrorCallback(show_glfw_error);

	// Initialize GLFW
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW! I'm out!" << '\n';
		exit(-1);
	}

	// Open a window and attach an OpenGL context to the window surface
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL 102", NULL, NULL);
	if (!window)
	{
		std::cerr << "Failed to open a window! I'm out!" << '\n';
		glfwTerminate();
		exit(-1);
	}

	// Set the window context current
	glfwMakeContextCurrent(window);

	// Register the GLFW  window resized callback function
	glfwSetWindowSizeCallback(window, window_resized);// seems like a important function..

	// Register the GLFW  window key pressed callback function
	glfwSetKeyCallback(window, key_pressed);


	// Set the swap interval, 1 will use your screen refresh rate (vsync)
	glfwSwapInterval(1);

	// Optionally, setup an OpenGL extension loader library
	// ...

	// from here you can write the opengl functions.
	// ==================================================================



	// Use red to clear the screen
	glClearColor(1, 0, 0, 1);

	// Create a rendering loop that runs until the window is closed
	while (!glfwWindowShouldClose(window)) {
		// Clear the screen (window background)
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw
		// ...

		// Swap front and back buffers for the current window
		glfwSwapBuffers(window);

		// Poll for events
		glfwPollEvents();
	}

	// Destroy the window and its context
	glfwDestroyWindow(window);

	// Terminate GLFW
	glfwTerminate();
	return 0;
}



//The defination of error is defined here.
void show_glfw_error(int error, const char* description) {
	std::cerr << "Error: " << description << '\n';
}


//window size change which is reflected over here as well. 
//if you resize the window then you can see the output that how much you are changing at prompt.
void window_resized(GLFWwindow* window, int width, int height) {
	std::cout << "Window resized, new window size: " << width << " x " << height << '\n';
}


//user interaction
void key_pressed(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == 'Q' && action == GLFW_PRESS) { //key terminatation logic.
		glfwTerminate();
		exit(0);
	}
}