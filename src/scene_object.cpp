#include "../include/scene_object.h"
#include <glm/gtc/matrix_transform.hpp>

namespace scene {
    t_scene_object::t_scene_object(t_object *p_object) {
        this->p_object = p_object;
        this->transformation_model = glm::mat4(1.0); // TODO: can i modify transformation by reference? also at other places in this class.
        this->hidden = false;
        this->scaling_model = glm::vec3(1.0);
        this->position_model = glm::vec3(0.0);
        this->rotation_model = glm::vec3(0.0);
    }

    glm::mat4 *t_scene_object::get_transformation_model() {
        glm::mat4 scaling = glm::scale(glm::mat4(1.0), this->scaling_model);
        glm::mat4 translation = glm::translate(glm::mat4(1.0), this->position_model);
        glm::mat4 rotation = glm::mat4(1.0);
        rotation = glm::rotate(rotation, glm::radians(this->rotation_model.x), glm::vec3(1.0, 0.0, 0.0));
        rotation = glm::rotate(rotation, glm::radians(this->rotation_model.y), glm::vec3(0.0, 1.0, 0.0));
        rotation = glm::rotate(rotation, glm::radians(this->rotation_model.z), glm::vec3(0.0, 0.0, 1.0));
        this->transformation_model = translation * scaling * rotation;
        return &this->transformation_model;
    }

    void t_scene_object::translate_model(glm::vec3 translation) {
        this->position_model += translation;
    }

    void t_scene_object::rotate_model(float angle, glm::vec3 axis) {
        this->rotation_model += angle * axis;
    }

    void t_scene_object::scale_model(glm::vec3 values) {
        this->scaling_model = values;
    }

/*
    glm::mat4 *t_scene_object::get_transformation_world() {
        glm::mat4 scaling = glm::scale(glm::mat4(1.0), this->scaling_world);
        glm::mat4 translation = glm::translate(glm::mat4(1.0), this->position_world);
        glm::mat4 rotation = glm::mat4(1.0);
        rotation = glm::rotate(rotation, glm::radians(this->rotation_world.x), glm::vec3(1.0, 0.0, 0.0));
        rotation = glm::rotate(rotation, glm::radians(this->rotation_world.y), glm::vec3(0.0, 1.0, 0.0));
        rotation = glm::rotate(rotation, glm::radians(this->rotation_world.z), glm::vec3(0.0, 0.0, 1.0));
        this->transformation_world = translation * scaling * rotation;
        return &this->transformation_world;
    }

    void t_scene_object::translate_world(glm::vec3 translation) {
        this->position_world += translation;
    }

    void t_scene_object::rotate_world(float angle, glm::vec3 axis) {
        this->rotation_world += angle * axis;
    }

    void t_scene_object::scale_world(glm::vec3 values) {
        this->scaling_world = values;
    }
*/

    bool t_scene_object::is_hidden() {
        return this->hidden;
    }

    t_scene_node *t_scene_object::get_node() {
        return this->p_node;
    }

    void t_scene_object::set_node(t_scene_node *p_scene_node) {
        this->p_node = p_scene_node;
    }

    t_object *t_scene_object::get_object() {
        return this->p_object;
    }

    std::vector<std::tuple<t_mesh *, assets::t_material *>> *t_scene_object::get_mesh_material() {
        return this->p_object->get_mesh_material();
    }

    glm::vec3 *t_scene_object::get_position_model() {
        return &this->position_model;
    }
}

