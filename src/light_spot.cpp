#include "../include/light_spot.h"


namespace scene {
t_light_spot::t_light_spot(t_object *p_object, glm::vec3 color, glm::vec3 direction, float angle) : t_light_directional(p_object, color, direction), angle(angle) {

}

t_light_spot::~t_light_spot() {

}

float t_light_spot::get_angle() {
    return this->angle;
}

float t_light_spot::get_angle_cos() {
    return glm::cos(glm::radians(this->angle));
}

float t_light_spot::get_outer_angle_cos() {
    return glm::cos(glm::radians(this->angle + 1));
}
}

