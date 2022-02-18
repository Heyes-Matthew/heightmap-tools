#include <stdio.h>

#include "image.h"
#include "filter.h"

image_t inv(image_t img)
{
    unsigned char max = -1;
    for(int i = 0; i < img.width * img.height; i++)
    {
        img.data[i] = max - img.data[i];
    }

    return img;
}

int main(int argc, char* argv[])
{
   image_t img;
   load_image(&img, "test.png");
   img = inv(img);
   save_image(img, "result.png", FORMAT_PNG);
}