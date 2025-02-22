#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для проверки, является ли число трехзначным
int is_three_digit(int num) {
    return num >= 100 && num <= 999;
}

// Функция для подсчета количества уникальных трехзначных чисел
int count_unique_three_digit_numbers(int N) {
    char str[20];
    sprintf(str, "%d", N);  // Преобразуем число в строку
    int len = strlen(str);
    int count = 0;
    int used[1000] = {0};  // Массив для отслеживания использованных чисел

    // Перебираем все возможные комбинации из трех цифр
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            for (int k = j + 1; k < len; k++) {
                // Формируем трехзначное число
                int num = (str[i] - '0') * 100 + (str[j] - '0') * 10 + (str[k] - '0');
                
                // Проверяем, является ли число трехзначным и уникальным
                if (is_three_digit(num) && !used[num]) {
                    used[num] = 1;
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    int N;
    //printf("Введите натуральное число N: ");
    scanf("%d", &N);

    int result = count_unique_three_digit_numbers(N);
    //printf("Количество различных трехзначных чисел: %d\n", result);
    printf("%d\n", result);

    return 0;
}