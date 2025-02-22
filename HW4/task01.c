#include <stdio.h>
#include <stdlib.h>

// Определение структуры дерева
typedef struct tree {
    int key; // datatype заменен на int для примера
    struct tree *left, *right;
} tree;

// Структура для хранения узла и его горизонтального расстояния
typedef struct {
    tree *node;
    int hd; // horizontal distance
} QueueItem;

// Функция для создания нового узла дерева
tree *createNode(int key) {
    tree *newNode = (tree *)malloc(sizeof(tree));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Функция для печати вида дерева сверху
void btUpView(tree *root) {
    if (root == NULL) return;

    // Очередь для обхода в ширину (BFS)
    QueueItem queue[100]; // Максимальный размер очереди
    int front = 0, rear = 0;

    // Хэш-таблица для хранения видимых узлов
    int hdTable[1000] = {0}; // Инициализация нулями
    int minHd = 0, maxHd = 0;

    // Добавляем корень в очередь
    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    // Обход в ширину
    while (front < rear) {
        QueueItem current = queue[front];
        front++;

        tree *node = current.node;
        int hd = current.hd;

        // Если узел с таким горизонтальным расстоянием еще не был обработан
        if (hdTable[hd + 500] == 0) { // +500 для избежания отрицательных индексов
            hdTable[hd + 500] = node->key;
            if (hd < minHd) minHd = hd;
            if (hd > maxHd) maxHd = hd;
        }

        // Добавляем левого потомка
        if (node->left != NULL) {
            queue[rear].node = node->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

        // Добавляем правого потомка
        if (node->right != NULL) {
            queue[rear].node = node->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    // Печать видимых узлов
    for (int i = minHd; i <= maxHd; i++) {
        printf("%d ", hdTable[i + 500]);
    }
    printf("\n");
}

// Пример использования
int main() {
    // Создаем дерево
    tree *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->left->right->right = createNode(5);
    root->left->right->right->right = createNode(6);

    // Печать вида сверху
    //printf("Вид дерева сверху: ");
    btUpView(root);

    // Освобождение памяти (не реализовано для краткости)
    return 0;
}