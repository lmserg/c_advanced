// Функция для поиска адреса блока с максимальным размером
uint64_t findMaxBlock(list *head) {
    uint64_t max_address = 0; // Адрес блока с максимальным размером
    size_t max_size = 0;      // Максимальный размер блока

    // Проход по списку
    list *current = head;
    while (current != NULL) {
        // Если текущий блок больше максимального
        if (current->size > max_size) {
            max_size = current->size;
            max_address = current->address;
        }
        // Переход к следующему элементу
        current = current->next;
    }

    return max_address;
}