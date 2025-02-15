#include <stdio.h>
#include <stdint.h> // Для использования uint32_t

int extractExp(float num) {
    // Интерпретируем float как uint32_t для доступа к битам
    uint32_t bits = *(uint32_t *)&num;

    // Извлекаем поле экспоненты (биты 23-30)
    uint32_t exp_bits = (bits >> 23) & 0xFF;

    // Преобразуем смещенную экспоненту в фактическую
    int exp = (int)exp_bits - 127;

    return exp;
}

int main() { 
    float num;

    // Ввод числа
    //printf("Введите вещественное число: ");
    scanf("%f", &num);

    // Извлечение экспоненты
    int exp = extractExp(num);

    // Вывод результата
    printf("%d\n", exp);

    return 0;
}