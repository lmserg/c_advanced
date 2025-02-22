#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Определение структуры списка
struct list {
    char word[20];
    struct list *next;
};

// Функция для добавления элемента в список
void add_to_list(struct list **head, char *word) {
    struct list *new_node = (struct list *)malloc(sizeof(struct list));
    strcpy(new_node->word, word);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct list *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Функция для обмена значениями двух элементов списка
void swap_elements(struct list *a, struct list *b) {
    char temp[20];
    strcpy(temp, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, temp);
}

// Функция для сортировки списка по алфавиту
void sort_list(struct list *head) {
    struct list *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->word, j->word) > 0) {
                swap_elements(i, j);
            }
        }
    }
}

// Функция для печати списка
void print_list(struct list *head) {
    struct list *temp = head;
    while (temp != NULL) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
}

// Функция для удаления списка
void delete_list(struct list *head) {
    struct list *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char input[1000];
    //printf("Введите строку (слова разделены пробелами, в конце точка): ");
    fgets(input, sizeof(input), stdin);

    // Удаляем точку и символ новой строки
    input[strcspn(input, ".\n")] = '\0';

    // Разделение строки на слова
    char *word = strtok(input, " ");
    struct list *head = NULL;

    while (word != NULL) {
        add_to_list(&head, word);
        word = strtok(NULL, " ");
    }

    // Сортировка списка
    sort_list(head);

    // Печать отсортированного списка
    //printf("Отсортированный список:\n");
    print_list(head);

    // Удаление списка
    delete_list(head);

    return 0;
}