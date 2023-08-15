#include "../include/light.h"


namespace scene {
t_light::t_light(t_object *p_object, glm::vec3 color) : t_scene_object(p_object) {
    this->set_color(color);
}

t_light::~t_light() {

}

glm::vec3 *t_light::get_color() {
    return &this->color;
}

void t_light::set_color(glm::vec3 color) {
    this->color = color;
    if (this->p_object != NULL) {
        std::vector<std::tuple<t_mesh *, assets::t_material *>> *p_mesh_material = this->p_object->get_mesh_material();
        assets::t_material *p_material;
        for (unsigned int i = 0; i < p_mesh_material->size(); i++) {
            p_material = std::get<1>(p_mesh_material->at(i));
            p_material->kd = this->color;
            p_material->shade = false;
        }
    }
}
}
