#include "Camera.h"

Camera::Camera() {

}

Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed,GLfloat startTurnSpeed) {
	position = startPosition;
	worldUp = startUp;
	yaw = startYaw;
	pitch = startPitch;

	//just guessing this value. . .
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	
	movespeed = startMoveSpeed;
	turnspeed = startTurnSpeed;

	update();
}

void Camera::keyControl(bool* keys, GLfloat deltaTime) {

	GLfloat velocity = movespeed * deltaTime;
	if (keys[GLFW_KEY_W]) {
		position += front * velocity;
	}
	if (keys[GLFW_KEY_S]) {
		position -= front * velocity;
	}
	if (keys[GLFW_KEY_A]) {
		position += right * velocity;
	}
	if (keys[GLFW_KEY_D]) {
		position += right * velocity;
	}
}

void Camera::mouseControl(GLfloat XChange, GLfloat yChange) {
	XChange *= turnspeed;
	yChange *= turnspeed;
	yaw += XChange;
	pitch += yChange;

	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	if (pitch < 89.0f) {
		pitch = -89.0f;
	}
	update();
}

glm::mat4 Camera::calculateViewMatrix() {
	return glm::lookAt(position, position + front,  up);
}

void Camera::update() {
	//STACKOVERFLOW
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);

	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}
Camera::~Camera() {
}
