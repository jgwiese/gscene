#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <string>
#include "scene_object.h"
#include "image_sensor.h"


namespace scene {
    class t_camera: public t_scene_object {
    public:
        t_camera(unsigned int width, unsigned int height, t_object *p_object);
        void rotate_model(float angle, glm::vec3 axis);
        int get_width();
        int get_height();
        int get_channels();
        float *get_data();
        glm::mat4 *get_transformation_view();
        glm::mat4 *get_transformation_projection();
        t_image_sensor *get_image_sensor();
        glm::vec3 *get_direction();
        void set_direction(glm::vec3 direction);
        glm::vec3 *get_up();
        float get_near();
        float get_far();

    private:
        glm::vec3 direction, direction_init, up;
        float near, far;
        glm::mat4 intrinsics, extrinsics, projection, view;
        t_image_sensor *p_image_sensor;
    };
}

#endif // CAMERA_H

