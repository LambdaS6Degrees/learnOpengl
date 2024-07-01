#include "Camera.h"

Camera::Camera(const glm::vec3& iPos, const glm::vec3& iFront, const glm::vec3& iUp):Position(iPos),
Front(iFront),
Pitch(0.0f),
Yaw(-90.0f),
Zoom(45.0f),
MovementSpeed(2.5f),
MouseSensitivity(0.5f)
{

}

void Camera::ProcessKeyboardInput(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
        Position += Front * velocity;
    if (direction == BACKWARD)
        Position -= Front * velocity;
    if (direction == LEFT)
        Position -= Right * velocity;
    if (direction == RIGHT)
        Position += Right * velocity;
}

void Camera::ProcessMouseInput(float xoffset, float yoffset, bool constraintPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constraintPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    UpdateCameraFront();
}

void Camera::ProcessMouseScroll(float yoffset)
{
    Zoom -= (float)yoffset;
    if (Zoom < 1.0f)
        Zoom = 1.0f;
    if (Zoom > 45.0f)
        Zoom = 45.0f;
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(Position, Position + Front, Up);
}

void Camera::UpdateCameraFront()
{
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
}