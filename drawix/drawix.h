#ifndef DRAWX_H
#define DRAWX_H

#define COMPONENT 4 // RGBA

bool drawPixel(unsigned int width, unsigned int height, unsigned char *image, unsigned int x, unsigned int y, unsigned char R, unsigned char G, unsigned char B, unsigned char opacity);
bool drawLine(unsigned int width, unsigned int height, unsigned char *image, double x0, double y0, double x1, double y1, unsigned char R, unsigned char G, unsigned char B, unsigned char opacity);
void drawBackground(unsigned int width, unsigned int height, unsigned char *image, unsigned char R, unsigned char G, unsigned char B, unsigned char opacity);
bool drawRectangle(unsigned int width, unsigned int height, unsigned char *image, unsigned int x_A, unsigned int y_A, unsigned int widthRec, unsigned int heightRec, unsigned char R, unsigned char G, unsigned char B, unsigned char opacity);
bool drawCircle(unsigned int width, unsigned int height, unsigned char *image, unsigned int center_x, unsigned int center_y, unsigned int diameter, unsigned char R, unsigned char G, unsigned char B, unsigned char opacity);

#endif