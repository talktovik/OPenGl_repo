#include "Camera.h"

Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed,GLfloat startTurnSpeed) {
	position = startPosition;
	up = startUp;
	yaw = startYaw;
	pitch = startPitch;

	//just guessing this value. . .
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	
	movespeed = startMoveSpeed;
	turnspeed = startTurnSpeed;

	update();

}
void Camera::update() {
	//STACKOVERFLOW
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);
}
