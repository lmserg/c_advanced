#include <stdio.h>
#include <stdint.h> // Для использования uint32_t

// Определение структуры
struct pack_array {
    uint32_t array;   // Поле для хранения упакованного массива
    uint32_t count0 : 8; // Счетчик нулей
    uint32_t count1 : 8; // Счетчик единиц
};

// Функция для упаковки массива в структуру
void array2struct(int arr[], struct pack_array *result) {
    result->array = 0; // Инициализация поля array
    result->count0 = 0; // Инициализация счетчика нулей
    result->count1 = 0; // Инициализация счетчика единиц

    // Упаковка массива и подсчет нулей и единиц
    for (int i = 0; i < 32; i++) {
        // Упаковка элемента в поле array
        result->array |= (arr[i] & 1) << (31 - i);

        // Подсчет нулей и единиц
        if (arr[i] == 0) {
            result->count0++;
        } else {
            result->count1++;
        }
    }
}

int main() {
    // Пример массива из 32 элементов (0 и 1)
    // int arr[32] = {1, 0, 1, 1, 0, 0, 1, 0,
    //                1, 1, 0, 1, 0, 0, 1, 1,
    //                0, 1, 0, 1, 1, 0, 0, 1,
    //                0, 1, 1, 0, 0, 1, 0, 1};
    int arr[32];
    for (int i = 0; i < 32; i++) {
        scanf("%d ", &arr[i]);
    }               
    
    // Структура для хранения результата
    struct pack_array result;

    // Упаковка массива в структуру
    array2struct(arr, &result);

    // Вывод результата
    printf("%u ", result.array);
    printf("%u ", result.count0);
    printf("%u\n", result.count1);

    return 0;
}