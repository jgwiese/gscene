#ifndef SCENE_LIGHT_H
#define SCENE_LIGHT_H

#include "scene_object.h"
#include <gassets/gassets.h>


namespace scene {
class t_light : public t_scene_object {
public:
    t_light(t_object *p_object, glm::vec3 color);
    virtual ~t_light();
    glm::vec3 *get_color();
    void set_color(glm::vec3 color);

protected:
    glm::vec3 color;
};
}

#endif // SCENE_LIGHT_H
