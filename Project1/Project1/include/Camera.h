#ifndef Camera_H
#define Camera_H
#include <glad/glad.h>
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera
{
public:
    Camera(const glm::vec3& iPos, const glm::vec3& iFront, const glm::vec3& iUp = glm::vec3(0.0f, 1.0f, 0.0f));
	void ProcessKeyboardInput(Camera_Movement dir, float deltaTime);
    void ProcessMouseInput(float xoffset, float yoffset, bool constraintPitch = true);
    void ProcessMouseScroll(float yoffset);
    glm::mat4 GetViewMatrix();
    float Zoom;
private:
    void UpdateCameraFront();
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    // euler Angles
    float Yaw;
    float Pitch;
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
};
#endif // !Camera_H
