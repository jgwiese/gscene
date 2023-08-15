#include "../include/camera.h"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace scene {
    t_camera::t_camera(std::string name, unsigned int width, unsigned int height, t_object *p_object) : t_scene_object(p_object) {
        this->name = name;
        // TODO implement intrinsics and extrinsics mechanics
        this->direction = glm::vec3(0.0, 0.0, -1.0);
        this->up = glm::vec3(0.0, 1.0, 0.0);
        this->p_image_sensor = new t_image_sensor(width, height, 4); // TODO: how to make this general for the amounts of channels?
        this->view = glm::mat4(1.0);
        this->projection = glm::perspective(glm::radians(45.0f), (float) width / height, 0.1f, 100.0f);
    }

    t_image_sensor *t_camera::get_image_sensor() {
        return this->p_image_sensor;
    }

    std::string t_camera::get_name() {
        return this->name;
    }

    int t_camera::get_width() {
        return this->p_image_sensor->get_width();
    }

    int t_camera::get_height() {
        return this->p_image_sensor->get_height();
    }

    int t_camera::get_channels() {
        return this->p_image_sensor->get_channels();
    }

    float *t_camera::get_data() {
        return this->p_image_sensor->get_data();
    }
    
    glm::mat4 *t_camera::get_transformation_view() {
        this->view = glm::lookAt(this->position_model, this->position_model + this->direction, this->up);
        return &this->view;
    }
    glm::mat4 *t_camera::get_transformation_projection() {
        return &this->projection;
    }

    glm::vec3 *t_camera::get_direction() {
        return &this->direction;
    }
    glm::vec3 *t_camera::get_up() {
        return &this->up;
    }
}
