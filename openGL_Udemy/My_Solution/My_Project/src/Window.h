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

	void swapBuffers() { return glfwSwapBuffers(mainWindow); }

	~Window();
	GLFWwindow* mainWindow;

	GLint width, height;
	GLint bufferWidth, bufferHeight;

};

