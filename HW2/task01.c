#include <stddef.h>

// Определение структуры списка
typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

// Функция для подсчета общего объема используемой памяти
size_t totalMemoryUsage(list *head) {
    size_t total_memory = 0; // Общий объем памяти

    // Проход по списку
    list *current = head;
    while (current != NULL) {
        // Добавляем размер текущего блока к общему объему
        total_memory += current->size;
        // Переход к следующему элементу
        current = current->next;
    }

    return total_memory;
}