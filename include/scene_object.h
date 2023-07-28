#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include <unordered_map>
#include <glm/glm.hpp>
#include <gassets/gassets.h>
#include "definitions.h"


namespace scene {
    class t_scene_object {
    public:
        t_scene_object(t_object *p_object);
        void translate_model(glm::vec3 translation);
        void rotate_model(float angle, glm::vec3 axis);
        void scale_model(glm::vec3 values);
        glm::mat4 *get_transformation_model();
    
    /*
        void translate_world(glm::vec3 translation);
        void rotate_world(float angle, glm::vec3 axis);
        void scale_world(glm::vec3 values);
        glm::mat4 *get_transformation_world();
    */

        bool is_hidden();
        void set_node(t_scene_node *p_scene_node);
        t_scene_node *get_node();
        t_object *get_object();
        std::vector<std::tuple<t_mesh *, assets::t_material *>> *get_mesh_material();
        glm::vec3 *get_position_model();

    protected:
        bool hidden;
        t_scene_node *p_node;
        t_object *p_object;
        glm::vec3 position_model;
        glm::vec3 rotation_model;
        glm::vec3 scaling_model;
        glm::mat4 transformation_model;
        
    /*
        glm::vec3 position_world;
        glm::vec3 rotation_world;
        glm::vec3 scaling_world;
        glm::mat4 transformation_world;
    */
    };
}

#endif // SCENE_OBJECT_H
