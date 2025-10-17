#include <stdlib.h>
#include <stdbool.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "drawix.h"


int drawFemboyFlag() {
    unsigned int width = 1000, height = 600;
    unsigned char *image = malloc(width * height * COMPONENT);
    if (!image)
        return 1;

    typedef struct {
        unsigned char R;
        unsigned char G;
        unsigned char B;
    } color;

    unsigned int heightForRows = height / 5;
    color colors[] = { {210, 99, 167}, {223, 170, 200}, {224, 224, 224}, {223, 170, 200}, {210, 99, 167} };

    for (int i = 0; i < 5; i++) {
        drawRectangle(width, height, image, 0, i * heightForRows, width, heightForRows, colors[i].R, colors[i].G, colors[i].B);
    }

    stbi_write_png("femboy.png", width, height, COMPONENT, image, width * COMPONENT);

    free(image);
    return 0;
}

void drawShapes() {
    unsigned int width = 800, height = 600;
    unsigned char *image = malloc(width * height * COMPONENT);
    if (!image)
        return;

    drawBackground(width, height, image, 51, 17, 79);

    printf("%d\n", drawCircle(width, height, image, width/2, height/2, 200, 199, 48, 174));

    printf("%d", drawRectangle(width, height, image, 0, 0, 49, 49, 199, 48, 174));
    printf("%d", drawRectangle(width, height, image, 750, 0, 49, 49, 199, 48, 174));
    printf("%d", drawRectangle(width, height, image, 0, 550, 49, 49, 199, 48, 174));
    printf("%d\n", drawRectangle(width, height, image, 750, 550, 49, 49, 199, 48, 174));

    stbi_write_png("shapes.png", width, height, COMPONENT, image, width*3);

    free(image);
}

int main() {
    drawFemboyFlag();
    drawShapes();

    return 0;
}