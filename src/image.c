#include "image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void load_image(image_t* img, char* fname)
{
    img->data = stbi_load(fname, &img->width, &img->height, &img->channels, 0);
    if(img->data == NULL)
    {
        printf("Unable to load image %s\n", fname);
        exit(1);
    }
}

void save_image(image_t img, char* fname, int format)
{
    if(format == FORMAT_PNG) {
        stbi_write_png(fname, img.width, img.height, img.channels, img.data, img.width * img.channels);
    }
    else if(format == FORMAT_JPG) {
        stbi_write_jpg(fname, img.width, img.height, img.channels, img.data, 100);
    }
    else if(format == FORMAT_BMP) {
        stbi_write_bmp(fname, img.width, img.height, img.channels, img.data);
    }
    else if(format == FORMAT_TGA) {
        stbi_write_tga(fname, img.width, img.height, img.channels, img.data);
    }
    else if(format == FORMAT_HDR) {
        stbi_write_hdr(fname, img.width, img.height, img.channels, img.data);
    }
    else{
        printf("Cannot save %s, unsupported format", fname);
    }
}