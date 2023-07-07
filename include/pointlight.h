#ifndef SCENE_POINTLIGHT_H
#define SCENE_POINTLIGHT_H

#include "../include/light.h"


namespace scene {
class t_pointlight : public t_light {
public:
    t_pointlight();
    ~t_pointlight();
};
}

#endif // SCENE_POINTLIGHT_H
