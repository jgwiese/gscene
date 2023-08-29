#include "../include/light_directional.h"


namespace scene {
t_light_directional::t_light_directional(t_object *p_object, glm::vec3 color, glm::vec3 direction) : t_light(p_object, color) {
    this->set_direction(direction);
    this->set_translation(glm::vec3(0.0, 10.0, 0.0)); // TODO choose a better height, less random, how does this affect ortho
}

t_light_directional::~t_light_directional() {

}
glm::vec3 *t_light_directional::get_direction() {
    return &this->direction;
}

void t_light_directional::set_direction(glm::vec3 direction) {
    this->direction = glm::normalize(direction);
}
}

