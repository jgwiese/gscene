#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "definitions.h"
#include "scene_object.h"
#include "camera.h"
#include "resource_manager.h"


namespace scene {
    class t_scene {
    public:
        t_scene();
        ~t_scene();
        //unsigned int add_mesh(t_mesh *p_mesh);
        t_camera *add_camera(t_scene_object *parent, t_camera *camera);
        t_scene_object *add_scene_object(t_scene_object *p_parent, t_scene_object *p_scene_object); // TODO: remove?
        std::vector<scene::t_scene_object *> *add_scene_object(t_scene_object *p_parent, std::string path_obj);
        std::vector<t_camera *> *get_cameras();
        //t_mesh *get_scene_object_mesh(t_scene_object *p_scene_object);
        t_scene_node *get_tree();

    private:
        t_scene_node *p_root;
        t_resource_manager *p_resource_manager;
        std::vector<t_camera *> v_cameras;
    };
}

#endif // SCENE_H
