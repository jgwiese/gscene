#ifndef SCENE_LIGHT_POINT_H
#define SCENE_LIGHT_POINT_H

#include "light.h"


namespace scene {
class t_light_point : public t_light {
public:
    t_light_point(t_object *p_object, glm::vec3 color);
    t_light_point(t_object *p_object, glm::vec3 color, float constant, float linear, float quadratic);
    virtual ~t_light_point();
    float get_constant();
    float get_linear();
    float get_quadratic();

private:
    float constant;
    float linear;
    float quadratic;
};
}

#endif // SCENE_LIGHT_POINT_H
