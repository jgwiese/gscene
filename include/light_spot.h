#ifndef SCENE_LIGHT_SPOT_H
#define SCENE_LIGHT_SPOT_H

#include "light_directional.h"


namespace scene {
class t_light_spot : public t_light_directional {
public:
    t_light_spot(t_object *p_object, glm::vec3 color, glm::vec3 direction, float angle);
    virtual ~t_light_spot();
    float get_angle();
    float get_angle_cos();
    float get_outer_angle_cos();

private:
    float angle;
};
}

#endif // SCENE_LIGHT_SPOT_H

