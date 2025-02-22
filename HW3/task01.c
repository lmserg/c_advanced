#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 105  // Максимальная длина строки + 1 для нуль-терминатора

// Функция для поиска длины наибольшего префикса первой строки, который является суффиксом второй
int find_prefix_suffix_length(const char *str1, const char *str2) {
    int max_length = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Перебираем возможные длины префиксов
    for (int i = 1; i <= len1 && i <= len2; i++) {
        // Сравниваем префикс первой строки с суффиксом второй
        if (strncmp(str1, str2 + len2 - i, i) == 0) {
            max_length = i;
        }
    }

    return max_length;
}

// Функция для поиска длины наибольшего суффикса первой строки, который является префиксом второй
int find_suffix_prefix_length(const char *str1, const char *str2) {
    int max_length = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Перебираем возможные длины суффиксов
    for (int i = 1; i <= len1 && i <= len2; i++) {
        // Сравниваем суффикс первой строки с префиксом второй
        if (strncmp(str1 + len1 - i, str2, i) == 0) {
            max_length = i;
        }
    }

    return max_length;
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    // Считываем две строки
    fgets(str1, MAX_LENGTH, stdin);
    fgets(str2, MAX_LENGTH, stdin);

    // Убираем символ перевода строки '\n' из строк
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Вычисляем длины
    int prefix_suffix_length = find_prefix_suffix_length(str1, str2);
    int suffix_prefix_length = find_suffix_prefix_length(str1, str2);

    // Выводим результат
    printf("%d %d\n", prefix_suffix_length, suffix_prefix_length);

    return 0;
}