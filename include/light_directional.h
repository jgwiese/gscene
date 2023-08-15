#ifndef SCENE_LIGHT_DIRECTIONAL_H
#define SCENE_LIGHT_DIRECTIONAL_H

#include "light.h"


namespace scene {
class t_light_directional : public t_light {
public:
    t_light_directional(t_object *p_object, glm::vec3 color, glm::vec3 direction);
    virtual ~t_light_directional();
    glm::vec3 *get_direction();
    void set_direction(glm::vec3 direction);
    
private:
    glm::vec3 direction;
};
}

#endif // SCENE_LIGHT_DIRECTIONAL_H

