#include "../include/camera.h"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace scene {
    t_camera::t_camera(std::string name, unsigned int width, unsigned int height, t_object *p_object, glm::mat4 intrinsics, glm::mat4 extrinsics) : t_scene_object(p_object) {
        this->name = name;
        this->intrinsics = intrinsics;
        this->extrinsics = extrinsics;
        this->projection = this->intrinsics * this->extrinsics;
        this->direction = glm::vec3(0.0f, 0.0f, -1.0f);
        this->up = glm::vec3(0.0f, 1.0f, 0.0f);
        this->p_image_sensor = new t_image_sensor(width, height, 4); // TODO: how to make this general for the amounts of channels?
        /*
         * TODO: for now the intrinsics resembles the projection matrix and will be adapted later to be fully controllable manually by parameters
        this->intrinsics[0][0] = 1.0;
        this->intrinsics[1][1] = 1.0;
        this->intrinsics[0][2] = 256.0;
        this->intrinsics[1][2] = 256.0;
        */
        this->intrinsics= glm::perspective(glm::radians(45.0f), (float) width / height, 0.1f, 100.0f);
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
    
    void t_camera::translate(glm::vec3 translation) {
        //translation.z *= -1.0;
        // TODO: i just have to translate relatively to the camera space not to world space, IF i actually want to.
        this->position += translation;
    }

    glm::mat4 *t_camera::get_projection() {
        // TODO: something wrong!!!
        glm::mat4 view = glm::lookAt(this->position, this->position + this->direction, this->up);
        this->projection = this->intrinsics * view;
        return &this->projection;
    }
}

