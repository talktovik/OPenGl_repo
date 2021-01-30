#pragma once

#include<stdio.h>
#include <iostream>
#include<string>
#include<fstream>
#include <GL/glew.h>

class Shader
{
public:
	Shader();

	void CreateFromString(const char * vertexCode, const char* fragmentCode);

	GLuint GetProjectionLocation();
	GLuint GetModelLocation();

	void UseShader();
	void ClearShader();

	~Shader();


private:
	GLuint shaderID, uniformProjection, uniformModel;

	void CompileShader(const char* vertexCode, const char * fragmentCode);
	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);

};

