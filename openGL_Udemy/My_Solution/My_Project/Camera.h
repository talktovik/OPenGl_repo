#pragma once

#include<GL/glew.h>
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>

class Camera
{
public:
	Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);


	~Camera();


private:
	//position|front|up|right|is for the camera and holdings
	glm::vec3 position; //initial position 
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	// Look this is theory lessons
	GLfloat yaw;
	GLfloat pitch;

	GLfloat movespeed;
	GLfloat turnspeed;

	void update();



};

