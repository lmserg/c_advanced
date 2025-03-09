#include "calc.h"
#include <stdio.h>
#include <math.h>

// Функция для нахождения корня уравнения f(x) = g(x) на отрезке [a, b] методом Ньютона
float root(function f, function g, float a, float b, float eps1, function df, function dg) {
    float x0 = (a + b) / 2; // Начальное приближение
    float x1;
    int iterations = 0;

    do {
        x1 = x0 - (f(x0) - g(x0)) / (df(x0) - dg(x0));
        iterations++;
        if (fabs(x1 - x0) < eps1) {
            break;
        } 
        x0 = x1;
    } while (1);

    printf("Итераций для нахождения корня: %d\n", iterations);
    return x1;
}

// Функция для вычисления определённого интеграла методом трапеций
float integral(function f, float a, float b, float eps2) {
    int n = 1;
    float h = (b - a) / n;
    float integral_prev = 0;
    float integral_curr = (f(a) + f(b)) * h / 2;

    while (fabs(integral_curr - integral_prev) > eps2) {
        n *= 2;
        h = (b - a) / n;
        integral_prev = integral_curr;
        integral_curr = 0;

        for (int i = 0; i < n; i++) {
            float x0 = a + i * h;
            float x1 = a + (i + 1) * h;
            integral_curr += (f(x0) + f(x1)) * h / 2;
        }
    }

    return integral_curr;
}