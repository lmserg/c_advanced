#include <stdio.h>

// Функция для подсчета количества нулей в двоичной записи числа
int countZeros(int number) {
    int count = 0;
    while (number > 0) {
        if ((number & 1) == 0) { // Проверяем младший бит
            count++;
        }
        number >>= 1; // Сдвигаем число вправо на 1 бит
    }
    return count;
}

int main() {
    int N, K;
    //printf("Введите N: ");
    scanf("%d", &N);
    //printf("Введите K: ");
    scanf("%d", &K);

    int result = 0;

    // Перебираем все числа от 1 до N
    for (int i = 1; i <= N; i++) {
        if (countZeros(i) == K) {
            result++; // Увеличиваем счетчик, если количество нулей равно K
        }
    }

    printf("%d\n", result);

    return 0;
}