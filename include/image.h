#ifndef IMAGE_H
#define IMAGE_H


namespace scene {
    class t_image {
    public:
        t_image(float *data, int width, int height, int channels);
        ~t_image();
        float get_pixel(int x, int y, int c);
        void set_pixel(float value, int x, int y, int c);
        int get_width();
        int get_height();
        int get_channels();
        float *get_data();

    private:
        int width, height, channels;
        float *data;
    };
}

#endif // IMAGE_H

