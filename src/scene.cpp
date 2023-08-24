#include "../include/scene.h"
#include <gassets/gassets.h>
#include <gassets/import_obj.h>


namespace scene {
t_scene::t_scene() {
    this->p_root = new t_scene_node(NULL);
}

void t_scene::add_scene_object(t_scene_object *p_parent, t_scene_object *p_scene_object) {
    t_scene_node *p_child = new t_scene_node(p_scene_object);
    p_scene_object->set_node(p_child);

    if (p_parent == NULL) {
        this->p_root->add_child(p_child);
    }
    else {
        p_parent->get_node()->add_child(p_child);
    }
}

t_scene_object *t_scene::copy_scene_object(t_scene_object *p_scene_object, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) {
    std::cout << "copying... " << std::endl;
    // make a new instance of p_scene object with new position, rotation and scale
    t_scene_object *p_scene_object_copy = new t_scene_object(p_scene_object->get_object());
    p_scene_object_copy->translate_model(-*p_scene_object->get_position_model() + position);
    //p_scene_object_copy->translate_model(position);
    p_scene_object_copy->rotate_model(rotation.x, glm::vec3(1.0, 0.0, 0.0));
    p_scene_object_copy->rotate_model(rotation.y, glm::vec3(0.0, 1.0, 0.0));
    p_scene_object_copy->rotate_model(rotation.z, glm::vec3(0.0, 0.0, 1.0));
    p_scene_object_copy->scale_model(scale);
    this->add_scene_object(NULL, p_scene_object_copy);
    return p_scene_object_copy;
}

std::vector<scene::t_scene_object *> *t_scene::add_scene_object(t_scene_object *p_parent, std::string path_obj) {
    std::vector<scene::t_scene_object *> *result = new std::vector<t_scene_object *>;
    // load objects and parent all to first object
    t_import_obj *p_import_object = new t_import_obj(path_obj);
    for (unsigned int i = 0; i < p_import_object->get_objects()->size(); i++) {
        t_scene_object *p_scene_object = new t_scene_object(p_import_object->get_objects()->at(i));
        result->push_back(p_scene_object);
        // TODO: not the best way to set the node of the scene object afterwards somehow?
        t_scene_node *p_child = new t_scene_node(p_scene_object);
        p_scene_object->set_node(p_child);
        if (p_parent == NULL) {
            this->p_root->add_child(p_child);
        }
        else {
            p_parent->get_node()->add_child(p_child);
        }
    }
    return result;
}

t_scene_node *t_scene::get_tree() {
    return this->p_root;
}
}
