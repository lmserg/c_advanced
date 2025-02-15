#include <stdio.h>
#include <stdint.h> // Для использования uint32_t

uint32_t cyclic_right_shift(uint32_t N, int K) {
    // Выполняем циклический сдвиг вправо на K битов
    return (N >> K) | (N << (32 - K));
}

int main() {
    uint32_t N;
    int K;

    // Ввод числа N и сдвига K
    //printf("Введите число N (32-битное беззнаковое): ");
    scanf("%u", &N);
    //printf("Введите сдвиг K (1 <= K <= 31): ");
    scanf("%d", &K);

    // Проверка корректности K
    if (K < 1 || K > 31) {
        printf("Сдвиг K должен быть в диапазоне от 1 до 31.\n");
        return 1;
    }

    // Выполнение циклического сдвига
    uint32_t result = cyclic_right_shift(N, K);

    // Вывод результата
    printf("%u\n", result);

    return 0;
}