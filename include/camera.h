#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <string>
#include "scene_object.h"
#include "image_sensor.h"


namespace scene {
    class t_camera: public t_scene_object {
    public:
        glm::vec3 direction, up;
        t_camera(std::string name, unsigned int width, unsigned int height, t_object *p_object, glm::mat4 intrinsics, glm::mat4 extrinsics);
        std::string get_name();
        int get_width();
        int get_height();
        int get_channels();
        float *get_data();
        glm::mat4 *get_projection();
        t_image_sensor *get_image_sensor();
        void rotate(float angle, glm::vec3 axis);
        void translate(glm::vec3 translation);

    private:
        std::string name;
        glm::mat4 intrinsics, extrinsics, projection;
        t_image_sensor *p_image_sensor;
    };
}

#endif // CAMERA_H

