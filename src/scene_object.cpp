#include "../include/scene_object.h"
#include <glm/gtc/matrix_transform.hpp>


namespace scene {
/*
t_scene_object::t_scene_object(std::vector<unsigned int> *v_mesh_ids, std::vector<unsigned int> *v_material_ids) {
    assert(v_mesh_ids->size() == v_material_ids->size());

    this->transformation = glm::mat4(1.0); // TODO: can i modify transformation by reference? also at other places in this class.
    this->hidden = false;
    this->scaling = glm::vec3(1.0f);
    this->position = glm::vec3(0.0f);
    this->rotation = glm::vec3(0.0f);
    
    unsigned int i;
    for (i = 0; i < v_mesh_ids->size(); i++) {
        this->v_mesh_ids.push_back(v_mesh_ids->at(i));
        this->um_mesh_id_material_id.insert(std::make_pair(v_mesh_ids->at(i), v_material_ids->at(i)));
    }
}
*/
t_scene_object::t_scene_object(t_object *p_object) {

    this->transformation = glm::mat4(1.0); // TODO: can i modify transformation by reference? also at other places in this class.
    this->hidden = false;
    this->scaling = glm::vec3(1.0f);
    this->position = glm::vec3(0.0f);
    this->rotation = glm::vec3(0.0f);
}

glm::mat4 *t_scene_object::get_transformation() {
    glm::mat4 scaling = glm::scale(glm::mat4(1.0f), this->scaling);
    glm::mat4 translation = glm::translate(glm::mat4(1.0f), this->position);
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(this->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    rotation = glm::rotate(rotation, glm::radians(this->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotation = glm::rotate(rotation, glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    this->transformation = translation * scaling * rotation;
    return &this->transformation;
}

void t_scene_object::translate(glm::vec3 translation) {
    this->position += translation;
}

void t_scene_object::rotate(float angle, glm::vec3 axis) {
    this->rotation += angle * axis;
}

void t_scene_object::scale(glm::vec3 values) {
    this->scaling = values;
}

t_scene_node *t_scene_object::get_node() {
    return this->p_node;
}

void t_scene_object::set_node(t_scene_node *p_scene_node) {
    this->p_node = p_scene_node;
}

std::vector<std::tuple<t_mesh *, t_material *>> *t_scene_object::get_mesh_material() {
    // TODO: what is wrong here?
    std::vector<std::tuple<t_mesh *, t_material *>> *result = this->p_object->get_mesh_material();
    return this->p_object->get_mesh_material();
}
}

