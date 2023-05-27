#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    // TODO Flll this in
        if (x < 0 || x >= im.w || y < 0 || y >= im.h || c < 0 || c >= im.c) {
            return 0.0f;
    }
    int index = c * im.h * im.w + y * im.w + x;
      return im.data[index];
}


void set_pixel(image im, int x, int y, int c, float v)
{
    
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    // TODO Fill this in
    for (int y = 0; y < im.h; y++) {
        for (int x = 0; x < im.w; x++) {
            for (int c = 0; c < im.c; c++) {
                copy.data[y * im.w * im.c + x * im.c + c] = im.data[y * im.w * im.c + x * im.c + c];
            }
        }
    }


    return copy;
}

image rgb_to_grayscale(image im)
{
     // TODO Fill this in
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
     for (int i = 0; i < im.w; i++) {
    for (int j = 0; j < im.h; j++) {
      int r = im.data[i * im.w + j * im.c + 0];
      int g = im.data[i * im.w + j * im.c + 1];
      int b = im.data[i * im.w + j * im.c + 2];

      int gray_value = (0.299 * r) + (0.587 * g) + (0.114 * b);
      gray.data[i * im.w + j] = gray_value;
    }
  }

   
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
