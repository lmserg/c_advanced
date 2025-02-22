#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Максимальный размер стека
#define MAX_STACK_SIZE 100

// Структура стека
typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

// Инициализация стека
void initStack(Stack *s) {
    s->top = -1;
}

// Проверка, пуст ли стек
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Проверка, полон ли стек
int isFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// Добавление элемента в стек
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Стек переполнен\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

// Извлечение элемента из стека
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Стек пуст\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// Вычисление выражения в обратной польской записи
int evalRPN(char *expression) {
    Stack s;
    initStack(&s);

    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Если токен — число, добавляем его в стек
            push(&s, atoi(token));
        } else {
            // Если токен — оператор, извлекаем два числа из стека и выполняем операцию
            int b = pop(&s);
            int a = pop(&s);
            switch (token[0]) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
                default:
                    printf("Неизвестный оператор: %c\n", token[0]);
                    exit(1);
            }
        }
        token = strtok(NULL, " ");
    }

    // Результат находится на вершине стека
    return pop(&s);
}

int main() {
    char expression[256];
    //printf("Введите выражение в обратной польской записи: ");
    fgets(expression, sizeof(expression), stdin);

    // Удаляем символ новой строки
    expression[strcspn(expression, "\n")] = '\0';

    // Вычисляем результат
    int result = evalRPN(expression);
    printf("%d\n", result);

    return 0;
}