#include <stdbool.h>
#include <math.h>

#include "drawix.h"
#include <stdio.h>

bool drawPixel(unsigned int width, unsigned int height, unsigned char *image, unsigned int x, unsigned int y, unsigned char R, unsigned char G, unsigned char B) {
    if (image && x < width && y < height) {
        int index = (y * width + x) * COMPONENT;
        image[index] = R;
        image[index+1] = G;
        image[index+2] = B;
        return true;
    }
    return false;
}

void drawBackground(unsigned int width, unsigned int height, unsigned char *image, unsigned char R, unsigned char G, unsigned char B) {
    if  (!image)
        return;

    for (int y=0; y<height; y++)
        for (int x=0; x<width; x++)
            drawPixel(width, height, image, x, y, R, G, B);
}

bool drawRectangle(unsigned int width, unsigned int height, unsigned char *image, unsigned int x_A, unsigned int y_A, unsigned int widthRec, unsigned int heightRec, unsigned char R, unsigned char G, unsigned char B) {
    if (!image || !widthRec || !heightRec || x_A+widthRec > width || y_A+heightRec > height)
        return false;

    for (int y=y_A; y < y_A+heightRec; y++)
        for (int x=x_A; x < x_A+widthRec; x++)
            drawPixel(width, height, image, x, y, R, G, B);

    return true;
}

bool drawCircle(unsigned int width, unsigned int height, unsigned char *image, unsigned int center_x, unsigned int center_y, unsigned int diameter, unsigned char R, unsigned char G, unsigned char B) {
    if (!image || !diameter)
        return false;

    unsigned int radius = diameter / 2;
    int min_x = center_x - radius;
    int max_x = center_x + radius;
    int min_y = center_y - radius;
    int max_y = center_y + radius;

    if (min_x < 0 || min_y < 0 || max_x >= width || max_y >= height)
        return false;

    for (int y=min_y; y<max_y; y++)
        for (int x=min_x; x<max_x; x++)
            if (sqrt(pow((int)center_x-x, 2) + pow((int)center_y-y, 2)) <= radius)
                drawPixel(width, height, image, x, y, R, G, B);

    return true;
}