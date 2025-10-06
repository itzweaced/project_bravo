#include "camera.h"

Camera::Camera(  int width, int height, glm::vec3 position)
{
    window_width = width;
    window_height = height;

    camera_position = position;
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt( camera_position, camera_position + camera_front, camera_up);
}

void Camera::processMouseInput( float xoffset, float yoffset)
{
    float sensitivity = 0.5f;

    xoffset *= sensitivity;
    yoffset *= sensitivity;

    camera_yaw += xoffset;
    camera_pitch += yoffset;

    if(camera_pitch > 89.0f)
    {
        camera_pitch = 89.0f;
    }
    if(camera_pitch < -89.0f)
    {
        camera_pitch = -89.0f;
    }

    glm::vec3 direction;

    direction.x = cos(glm::radians(camera_yaw)) * cos(glm::radians(camera_pitch));
    direction.y = sin(glm::radians(camera_pitch));
    direction.z = sin(glm::radians(camera_yaw)) * cos(glm::radians(camera_pitch));

    camera_front = glm::normalize(direction);
}

void Camera::processMouseScroll(float yoffset)
{
    camera_fov -= (float)yoffset;

    if(camera_fov < 1.0f)
    {
        camera_fov = 1.0f;
    }
    if(camera_fov > 45.0f)
    {
        camera_fov = 45.0f;
    }
}

void Camera::setCameraPosition(glm::vec3 setPosition)
{
    camera_position = setPosition;
};


glm::vec3 Camera::returnCameraPosition()
{
    return camera_position;
};