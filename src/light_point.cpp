#include "../include/light_point.h"


namespace scene {
t_light_point::t_light_point(t_object *p_object, glm::vec3 color) : t_light(p_object, color) {
    this->constant = 1.0;
    this->linear = 0.09;
    this->quadratic = 0.032;
}

t_light_point::t_light_point(t_object *p_object, glm::vec3 color, float constant, float linear, float quadratic) : t_light(p_object, color), constant(constant), linear(linear), quadratic(quadratic) {

}

t_light_point::~t_light_point() {

}

float t_light_point::get_constant() {
    return this->constant;
}

float t_light_point::get_linear() {
    return this->linear;
}

float t_light_point::get_quadratic() {
    return this->quadratic;
}
}
