#include "../include/image_sensor.h"


namespace scene {
    t_image_sensor::t_image_sensor(int width, int height, int channels) {
        this->p_image = new t_image(NULL, width, height, channels);
    }

    t_image_sensor::~t_image_sensor() {

    }

    t_image *t_image_sensor::get_image() {
        return this->p_image;
    }

    int t_image_sensor::get_width() {
        return this->p_image->get_width();
    }

    int t_image_sensor::get_height() {
        return this->p_image->get_height();
    }

    int t_image_sensor::get_channels() {
        return this->p_image->get_channels();
    }

    float *t_image_sensor::get_data() {
        return this->p_image->get_data();
    }
}

