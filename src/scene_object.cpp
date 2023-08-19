#include "../include/scene_object.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>


namespace scene {
    t_scene_object::t_scene_object(t_object *p_object) {
        this->p_object = p_object;
        this->transformation_model = glm::mat4(1.0); // TODO: can i modify transformation by reference? also at other places in this class.
        this->hidden = false;
        this->scaling_model = glm::vec3(1.0);
        this->position_model = glm::vec3(0.0);
        this->rotation_model = glm::vec3(0.0);

        // center vertices
        if (p_object != NULL) {
            glm::vec3 center = p_object->center();
            this->translate_model(center);
        }
    }

    t_scene_object::~t_scene_object() {

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
    void t_scene_object::set_hidden(bool value) {
        this->hidden = value;
    }

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

    glm::vec3 t_scene_object::get_position_world() {
        // figure out global transformation
        scene::t_scene_node *parent = this->get_node()->get_parent();
        glm::mat4 transformation = *this->get_transformation_model();
        while (parent != NULL) {
            if (parent->get_data() != NULL) {
                transformation = *parent->get_data()->get_transformation_model() * transformation;
            }
            parent = parent->get_parent();
        }
        glm::vec3 v = glm::vec3(transformation * glm::vec4(*this->get_position_model(), 1.0));
        return v;
    }
}

