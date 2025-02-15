#include <stdio.h>
#include <stdint.h> // Для использования uint32_t

int count_set_bits(uint32_t N) {
    int count = 0;
    while (N != 0) {
        count++;
        N = N & (N - 1); // Сбрасываем младший единичный бит
    }
    return count;
}

int main() {
    uint32_t N;

    // Ввод числа N
    //printf("Введите число N (32-битное беззнаковое): ");
    scanf("%u", &N);

    // Подсчет единичных битов
    int result = count_set_bits(N);

    // Вывод результата
    printf("%d\n", result);

    return 0;
}