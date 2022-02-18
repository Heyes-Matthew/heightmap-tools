#ifndef IMAGE_H
#define IMAGE_H

typedef struct{
    int width, height, channels;
    unsigned char* data;
} image_t;

void load_image(image_t* img, char* fname);

#define FORMAT_PNG 0
#define FORMAT_JPG 1
#define FORMAT_BMP 2
#define FORMAT_TGA 3
#define FORMAT_HDR 4

void save_image(image_t img, char* fname, int format);

#endif
