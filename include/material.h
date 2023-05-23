#ifndef SCENE_MATERIAL_H
#define SCENE_MATERIAL_H

#include <glm/glm.hpp>
#include <string>


namespace scene {
    class t_material {
    public:
        t_material(std::string path_material);
        ~t_material();
        unsigned int get_texture_id();
        glm::vec4 get_diffuse();

    private:
        glm::vec4 diffuse;
        unsigned int texture_id;
    };
}

#endif // SCENE_MATERIAL_H

