#ifndef SCENE_LIGHT_H
#define SCENE_LIGHT_H

#include "scene_object.h"
#include <gassets/gassets.h>


namespace scene {
class t_light : public t_scene_object {
public:
    t_light(t_object *p_object);
    ~t_light();
};
}

#endif // SCENE_LIGHT_H
