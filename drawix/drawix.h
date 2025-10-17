#ifndef DRAWX_H
#define DRAWX_H

#define COMPONENT 3 // RGB

bool drawPixel(unsigned int width, unsigned int height, unsigned char *image, unsigned int x, unsigned int y, unsigned char R, unsigned char G, unsigned char B);
void drawBackground(unsigned int width, unsigned int height, unsigned char *image, unsigned char R, unsigned char G, unsigned char B);
bool drawRectangle(unsigned int width, unsigned int height, unsigned char *image, unsigned int x_A, unsigned int y_A, unsigned int widthRec, unsigned int heightRec, unsigned char R, unsigned char G, unsigned char B);
bool drawCircle(unsigned int width, unsigned int height, unsigned char *image, unsigned int center_x, unsigned int center_y, unsigned int diameter, unsigned char R, unsigned char G, unsigned char B);

#endif