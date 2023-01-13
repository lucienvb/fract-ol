#include <stdio.h>
#include <stdlib.h>
#include "../fractol.h"

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 100
#define THRESHOLD 4.0

int main() {
    double min_x = -2.0;
    double max_x = 1.0;
    double min_y = -1.5;
    double max_y = 1.5;

    double x_step = (max_x - min_x) / WIDTH;
    double y_step = (max_y - min_y) / HEIGHT;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double c_real = min_x + x * x_step;
            double c_imag = min_y + y * y_step;

            double z_real = 0.0;
            double z_imag = 0.0;

            int iterations = 0;
            while (iterations < MAX_ITERATIONS && (z_real * z_real + z_imag * z_imag) < THRESHOLD) {
                double z_real_new = z_real * z_real - z_imag * z_imag + c_real;
                double z_imag_new = 2 * z_real * z_imag + c_imag;
                z_real = z_real_new;
                z_imag = z_imag_new;
                iterations++;
            }

            if (iterations == MAX_ITERATIONS) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}
