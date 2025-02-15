#include <stdio.h>
#include <stdint.h> // Для использования uint32_t

uint32_t invert_high_byte(uint32_t N) {
    // Выделяем старший байт
    uint32_t high_byte = (N >> 24) & 0xFF;

    // Инвертируем старший байт
    high_byte = ~high_byte & 0xFF; // Оставляем только 8 битов

    // Очищаем старший байт в исходном числе
    N = N & 0x00FFFFFF; // Устанавливаем старший байт в 0

    // Добавляем инвертированный старший байт обратно
    N = N | (high_byte << 24);

    return N;
}

int main() {
    uint32_t N;

    // Ввод числа N
    //printf("Введите число N (32-битное беззнаковое): ");
    scanf("%u", &N);

    // Инверсия старшего байта
    uint32_t result = invert_high_byte(N);

    // Вывод результата
    printf("%u\n", result);

    return 0;
}