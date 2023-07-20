#include "../include/scene.h"
#include <gassets/gassets.h>
#include <gassets/import_obj.h>


namespace scene {
t_scene::t_scene() {
    this->p_root = new t_scene_node(NULL);
    this->p_resource_manager = new t_resource_manager();
}

t_camera *t_scene::add_camera(t_scene_object *p_parent, t_camera *p_camera) {
    /*
    if (parent == NULL) {
        this->p_root->add_child(new t_scene_node(camera));
    }
    else {
        parent->get_node()->add_child(new t_scene_node(camera));
    }
    */
    this->add_scene_object(p_parent, p_camera);
    this->v_cameras.push_back(p_camera);
    return p_camera;
}

t_scene_object *t_scene::add_scene_object(t_scene_object *p_parent, t_scene_object *p_scene_object) {
    t_scene_node *p_child = new t_scene_node(p_scene_object);
    p_scene_object->set_node(p_child);

    if (p_parent == NULL) {
        this->p_root->add_child(p_child);
    }
    else {
        p_parent->get_node()->add_child(p_child);
    }
    return p_scene_object;
}

std::vector<scene::t_scene_object *> *t_scene::add_scene_object(t_scene_object *p_parent, std::string path_obj) {
    std::vector<scene::t_scene_object *> *result = new std::vector<t_scene_object *>;
    // load objects and parent all to first object
    t_import_obj *p_import_object = new t_import_obj(path_obj);
    for (unsigned int i = 0; i < p_import_object->get_objects()->size(); i++) {
        std::cout << p_import_object->get_objects()->at(i)->get_name() << std::endl;
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

std::vector<t_camera *> *t_scene::get_cameras() {
    return &this->v_cameras;
}
}
