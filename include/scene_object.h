#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include <unordered_map>
#include <glm/glm.hpp>
#include <gassets/gassets.h>
#include "definitions.h"


namespace scene {
    class t_scene_object {
    public:
        //t_scene_object(std::vector<unsigned int> *v_mesh_ids, std::vector<unsigned int> *v_material_ids);
        t_scene_object(t_object *p_object);
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scaling;
        glm::mat4 *get_transformation();
        void translate(glm::vec3 translation);
        void rotate(float angle, glm::vec3 axis);
        void scale(glm::vec3 values);
        void set_node(t_scene_node *p_scene_node);
        t_scene_node *get_node();
        t_object *get_object();
        std::vector<std::tuple<t_mesh *, t_material *>> *get_mesh_material();
        bool hidden;

    private:
        t_scene_node *p_node;
        t_object *p_object;

    protected:
        glm::mat4 transformation;
    };
}

#endif // SCENE_OBJECT_H
