#include "tgaimage.h"

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);


int main(int argc, char **argv) {
    TGAImage image(100, 100, TGAImage::RGB);
    line(0, 0, 10, 10, image, red);
    line(40, 40, 60, 60, image, white);
    line(35, 45, 64, 64, image, white);
    line(80, 80, 70, 70, image, red);
    image.flip_vertically();
    image.write_tga_file("output.tga");
    return 0;
}

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
    int x_direction = x0 < x1 ? 1 : -1;
    int y_direction = y0 < y1 ? 1 : -1;

    int currentXPosition = x0;
    int currentYPosition = y0;

    while (x1 > currentXPosition && y1 > currentYPosition) {
        image.set(currentXPosition, currentYPosition, color);
        if (x_direction == 1) {
            if (currentXPosition < x1) {
                currentXPosition += x_direction;
            }
        } else {
            if (currentXPosition > x1) {
                currentXPosition += x_direction;
            }
        }
        if (y_direction == 1) {
            if (currentYPosition < y1) {
                currentYPosition += y_direction;
            }
        } else {
            if (currentYPosition > y1) {
                currentYPosition += y_direction;
            }
        }
    }
}
