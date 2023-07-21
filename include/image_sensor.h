#ifndef IMAGE_SENSOR_H
#define IMAGE_SENSOR_H

#include <gassets/gassets.h>


namespace scene {
    class t_image_sensor {
    public:
        t_image_sensor(int width, int height, int channels);
        ~t_image_sensor();
        t_image *get_image();
        int get_width();
        int get_height();
        int get_channels();
        float *get_data();

    private:
        t_image *p_image;
    };
}

#endif // IMAGE_SENSOR_H

