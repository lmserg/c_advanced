#include <stdio.h>
#include <stdint.h> // Для использования uint32_t

uint32_t max_k_bit_sequence(uint32_t N, int K) {
    uint32_t max_value = 0; // Максимальное значение
    uint32_t mask = (1 << K) - 1; // Маска для извлечения K битов

    // Перебираем все возможные позиции
    for (int i = 0; i <= 32 - K; i++) {
        // Извлекаем K битов, начиная с позиции i
        uint32_t current_value = (N >> i) & mask;

        // Обновляем максимальное значение
        if (current_value > max_value) {
            max_value = current_value;
        }
    }

    return max_value;
}

int main() {
    uint32_t N;
    int K;

    // Ввод числа N и длины последовательности K
    //printf("Введите число N (32-битное беззнаковое): ");
    scanf("%u", &N);
    //printf("Введите длину последовательности K (1 <= K <= 31): ");
    scanf("%d", &K);

    // Проверка корректности K
    if (K < 1 || K > 31) {
        printf("Длина последовательности K должна быть в диапазоне от 1 до 31.\n");
        return 1;
    }

    // Поиск максимальной последовательности
    uint32_t result = max_k_bit_sequence(N, K);

    // Вывод результата
    printf("%u\n", result);

    return 0;
}