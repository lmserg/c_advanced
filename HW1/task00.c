#include <stdio.h>
#include <limits.h> // Для INT_MIN

int main() {
    int N;
    scanf("%d", &N); // Считываем количество чисел

    if (N <= 0) {
        printf("N должно быть больше 0\n");
        return 1;
    }

    int max_value = INT_MIN; // Начальное значение максимума
    int count = 0;           // Счетчик вхождений максимума

    for (int i = 0; i < N; i++) {
        int current_number;
        scanf("%d", &current_number); // Считываем текущее число

        // Используем побитовые операции для сравнения
        if ((current_number ^ max_value) & ~INT_MIN) {
            // Если текущее число больше max_value
            if (current_number > max_value) {
                max_value = current_number;
                count = 1; // Сбрасываем счетчик
            }
        } else if (current_number == max_value) {
            count++; // Увеличиваем счетчик
        }
    }

    printf("%d\n", count); // Выводим результат
    return 0;
}