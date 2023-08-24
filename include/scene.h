#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "definitions.h"
#include "scene_object.h"
#include "camera.h"
#include "light_directional.h"
#include "light_point.h"
#include "light_spot.h"


namespace scene {
    class t_scene {
    public:
        t_scene();
        ~t_scene();
        void add_scene_object(t_scene_object *p_parent, t_scene_object *p_scene_object);
        t_scene_object *copy_scene_object(t_scene_object *p_scene_object, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
        std::vector<scene::t_scene_object *> *add_scene_object(t_scene_object *p_parent, std::string path_obj);
        t_scene_node *get_tree();

    private:
        t_scene_node *p_root;
    };
}

#endif // SCENE_H
