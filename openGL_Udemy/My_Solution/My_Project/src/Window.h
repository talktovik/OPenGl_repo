#pragma once

#include<stdio.h>
#include<GL/glew.h>
#include<GLFW\glfw3.h>



class Window
{
public:
	Window();
	Window(GLint windowWidth, GLint windowHeight);

	int Initialise();

	GLfloat getBufferWidth() { return bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }

	bool getShouldClose() { return glfwWindowShouldClose(mainWindow);}

	bool* getKeys() { return keys; }
	GLfloat getXchange();
	GLfloat getYchange();
	

	void swapBuffers() { return glfwSwapBuffers(mainWindow); }

	~Window();

private:
	GLFWwindow* mainWindow;

	GLint width, height;
	GLint bufferWidth, bufferHeight;


	bool keys[1024];
	GLfloat lastX, lastY, xChange, yChange;
	bool mouseFirstMoved;


	//for the camera
	void createCallbacks();

	static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
	static void handleMouse(GLFWwindow* window, double xpos, double ypos);
};

