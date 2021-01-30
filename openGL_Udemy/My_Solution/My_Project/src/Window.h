#pragma once
#include<GL/glew.h>
#include<stdio.h>
#include<iostream>
#include<GLFW\glfw3.h>



class Window
{
public:
	Window();
	Window(GLint windowWidth, GLint windowHeight);

	int Initialise();

	GLfloat getBufferWidth() { return bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }

	bool getShouldClose() { return glfwWindowShouldClose(window);}

	void swapBuffers() { return glfwSwapBuffers(window); }

	~Window();
	GLFWwindow* window;

	GLint width, height;
	GLint bufferWidth, bufferHeight;

};

