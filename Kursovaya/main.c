#include <stdio.h>
// #include <stdlib.h>
#include <string.h>
#include  <math.h>
#include "calc.h"

#define eps1 1e-4
#define eps2 1e-4

// Заданные функции
float f1(float x) {
    return 0.6 * x - 1;
}

float f2(float x) {
    return pow(x - 2, 3) - 1;
}

float f3(float x) {
    return 3 / x;
}

// Производные (для метода Ньютона)
float df1(float x) {
    return 0.6;
}

float df2(float x) {
    return 3 * pow(x - 2, 2);
}

float df3(float x) {
    return -3 / (x * x);
}

// Функция для вывода справки
void print_help() {
    printf("Использование программы\n");
    printf("Опции:\n");
    printf("  --help       Вывести справку\n");
    printf("  --intersect  Найти точки пересечения кривых\n");
    printf("  --area       Вычислить площадь, образуемую кривыми\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0) {
        print_help();
        return 0;
    }

    if (strcmp(argv[1], "--intersect") == 0) {
        // Находим точки пересечения f1 и f3 
        float x1 = root(f1, f3, -2, 0, eps1, df1, df3);
        printf("Абсцисса пересечения f1 и f2: x = %f\n", x1);

        // Находим точки пересечения f1 и f3
        float x2 = root(f1, f3, -2.0, 0.0, eps1, df1, df3);
        printf("Абсцисса пересечения f1 и f3: x = %f\n", x2);

        // Находим точки пересечения f2 и f3
        float x3 = root(f2, f3, -2.0, 0.0, eps1, df2, df3);
        printf("Абсцисса пересечения f2 и f3: x = %f\n", x3);
    }

    if (strcmp(argv[1], "--area") == 0) {
        // Находим точки пересечения для определения границ интегрирования
        float x1 = root(f1, f3, -2, 0, eps1, df1, df3);
        float x2 = root(f1, f3, -2.0, 0.0, eps1, df1, df3);
        float x3 = root(f2, f3, -2.0, 0.0, eps1, df2, df3);

        // Вычисляем площадь между кривыми
        float area1 = integral(f1, x1, x2, eps2) - integral(f2, x1, x2, eps2);
        float area2 = integral(f1, x2, x3, eps2) - integral(f3, x2, x3, eps2);
        float total_area = area1 + area2;

        printf("Площадь, образуемая кривыми: %f\n", total_area);
    }
    return 0;
}