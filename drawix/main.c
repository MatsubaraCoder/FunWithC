#include <stdlib.h>
#include <stdbool.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "drawix.h"


void drawLines() {
    unsigned int width = 1000, height = 600;
    unsigned char *image = malloc(width * height * COMPONENT);
    if (!image)
        return;

    drawBackground(width, height, image, 51, 17, 79, 255);

    for (int i=0; i<100; i++)
        drawLine(width, height, image, rand()%width, rand()%height, rand()%width, rand()%height, 199, 48, 174, 255);

    stbi_write_png("lines.png", width, height, COMPONENT, image, width * COMPONENT);

    free(image);
}

void drawFemboyFlag() {
    unsigned int width = 1000, height = 600;
    unsigned char *image = malloc(width * height * COMPONENT);
    if (!image)
        return;

    typedef struct {
        unsigned char R;
        unsigned char G;
        unsigned char B;
        unsigned char A;
    } color;

    color colors[] = { {210, 99, 167, 255}, {223, 170, 200, 255}, {224, 224, 224, 255}, {223, 170, 200, 255}, {210, 99, 167, 255} };
    
    int colorLen = sizeof(colors)/sizeof(colors[0]);
    int heightForRows = height / colorLen;
    for (int i=0; i<colorLen; i++)
        printf("row=%d -> %d\n", i, drawRectangle(width, height, image, 0, heightForRows*i, width-1, heightForRows-1, colors[i].R, colors[i].G, colors[i].B, colors[i].A));

    stbi_write_png("femboy.png", width, height, COMPONENT, image, width*COMPONENT);

    free(image);
}

void drawShapes() {
    unsigned int width = 800, height = 600;
    unsigned char *image = malloc(width * height * COMPONENT);
    if (!image)
        return;

    drawBackground(width, height, image, 51, 17, 79, 255);

    printf("%d\n", drawCircle(width, height, image, width/2, height/2, 200, 199, 48, 174, 255));

    printf("%d", drawRectangle(width, height, image, 0, 0, 49, 49, 199, 48, 174, 255));
    printf("%d", drawRectangle(width, height, image, 750, 0, 49, 49, 199, 48, 174, 255));
    printf("%d", drawRectangle(width, height, image, 0, 550, 49, 49, 199, 48, 174, 255));
    printf("%d\n", drawRectangle(width, height, image, 750, 550, 49, 49, 199, 48, 174, 255));

    stbi_write_png("shapes.png", width, height, COMPONENT, image, width*COMPONENT);

    free(image);
}

int main() {
    drawLines();
    drawFemboyFlag();
    drawShapes();

    return 0;
}