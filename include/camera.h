#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include "scene_object.h"
#include "image_sensor.h"


namespace scene {
    class t_camera: public t_scene_object {
    public:
        glm::vec3 direction, up;
        t_camera(unsigned int width, unsigned int height, t_object *p_object, glm::mat4 intrinsics, glm::mat4 extrinsics);
        t_image_sensor *get_image_sensor();
        int get_width();
        int get_height();
        int get_channels();
        float *get_data();
        void rotate(float angle, glm::vec3 axis);
        glm::mat4 *get_projection();
        void translate(glm::vec3 translation);

    private:
        glm::mat4 intrinsics, extrinsics, projection;
        t_image_sensor *p_image_sensor;
    };
}

#endif // CAMERA_H

