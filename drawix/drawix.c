#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "drawix.h"
#include <stdio.h>

bool drawPixel(unsigned int width, unsigned int height, unsigned char *image, unsigned int x, unsigned int y, unsigned char R, unsigned char G, unsigned char B, unsigned char opacity) {
    if (image && x < width && y < height) {
        int index = (y * width + x) * COMPONENT;
        image[index] = R;
        image[index+1] = G;
        image[index+2] = B;
        image[index+3] = opacity;
        return true;
    }
    return false;
}

void swap(double *x0, double *y0, double *x1, double *y1) {
    double temp;
    temp = *x0; *x0 = *x1; *x1 = temp;
    temp = *y0; *y0 = *y1; *y1 = temp;
}

bool drawLine(unsigned int width, unsigned int height, unsigned char *image, double x0, double y0, double x1, double y1, unsigned char R, unsigned char G, unsigned char B, unsigned char opacity) {
    if (!image || x0 < 0 || x1 < 0 || y0 < 0 || y1 < 0 || x0 >= width || x1 >= width || y0 >= height || y1 >= height)
        return false;

    if (fabs(x1 - x0) > fabs(y1 - y0)) {
        if (x0 > x1)
            swap(&x0, &y0, &x1, &y1);

        double dx = x1 - x0;
        double dy = y1 - y0;

        double m = dx != 0 ? dy / dx : 1;

        int ix, iy;
        double alpha0, alpha1;

        for (int i=0; i<=dx; i++) {
            double x = x0 + i;
            double y = m * i + y0;

            ix = (int)floor(x);
            iy = (int)floor(y);

            alpha0 = y - iy;
            alpha1 = 1 - alpha0;

            drawPixel(width, height, image, ix, iy, R, G, B, (unsigned char)lround(alpha1*opacity));
            drawPixel(width, height, image, ix, iy+1, R, G, B, (unsigned char)lround(alpha0*opacity));
        }
    } else {
        if (y0 > y1)
            swap(&x0, &y0, &x1, &y1);

        double dx = x1 - x0;
        double dy = y1 - y0;

        double m = dy != 0 ? dx / dy : 1;

        int ix, iy;
        double alpha0, alpha1;

        for (int i=0; i<=dy; i++) {
            double x = m * i + x0;
            double y = y0 + i;

            ix = (int)floor(x);
            iy = (int)floor(y);

            alpha0 = x - ix;
            alpha1 = 1 - alpha0;

            drawPixel(width, height, image, ix, iy, R, G, B, (unsigned char)lround(alpha1*opacity));
            drawPixel(width, height, image, ix+1, iy, R, G, B, (unsigned char)lround(alpha0*opacity));
        }
    }
    return true;
}

void drawBackground(unsigned int width, unsigned int height, unsigned char *image, unsigned char R, unsigned char G, unsigned char B, unsigned char opacity) {
    if  (!image)
        return;

    for (int y=0; y<height; y++)
        for (int x=0; x<width; x++)
            drawPixel(width, height, image, x, y, R, G, B, opacity);
}

bool drawRectangle(unsigned int width, unsigned int height, unsigned char *image, unsigned int x_A, unsigned int y_A, unsigned int widthRec, unsigned int heightRec, unsigned char R, unsigned char G, unsigned char B, unsigned char opacity) {
    if (!image || !widthRec || !heightRec || x_A+widthRec >= width || y_A+heightRec >= height)
        return false;

    for (int y=y_A; y <= y_A+heightRec; y++)
        for (int x=x_A; x <= x_A+widthRec; x++)
            drawPixel(width, height, image, x, y, R, G, B, opacity);

    return true;
}

bool drawCircle(unsigned int width, unsigned int height, unsigned char *image, unsigned int center_x, unsigned int center_y, unsigned int diameter, unsigned char R, unsigned char G, unsigned char B, unsigned char opacity) {
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
        for (int x=min_x; x<max_x; x++) {
            int dx = (int)center_x - x;
            int dy = (int)center_y - y;
            if (dx*dx + dy*dy <= radius*radius)
                drawPixel(width, height, image, x, y, R, G, B, opacity);
        }

    return true;
}