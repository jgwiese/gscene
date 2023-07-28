#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "definitions.h"
#include "scene_object.h"
#include "camera.h"
#include "light.h"
#include "resource_manager.h"


namespace scene {
    class t_scene {
    public:
        t_scene();
        ~t_scene();
        t_camera *add_camera(t_scene_object *p_parent, t_camera *p_camera);
        t_light *add_light(t_scene_object *p_parent, t_light *p_light);
        t_scene_object *add_scene_object(t_scene_object *p_parent, t_scene_object *p_scene_object); // TODO: remove?
        std::vector<scene::t_scene_object *> *add_scene_object(t_scene_object *p_parent, std::string path_obj);
        std::vector<t_camera *> *get_cameras();
        std::vector<t_light *> *get_lights();
        t_scene_node *get_tree();

    private:
        t_scene_node *p_root;
        t_resource_manager *p_resource_manager;
        std::vector<t_camera *> v_cameras;
        std::vector<t_light *> v_lights;
    };
}

#endif // SCENE_H
