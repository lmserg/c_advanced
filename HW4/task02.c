#include <stdio.h>
#include <stdlib.h>

// Определение структуры дерева
typedef struct tree {
    int key; // datatype заменен на int для примера
    struct tree *left, *right;
    struct tree *parent; // ссылка на родителя
} tree;

// Функция для создания нового узла дерева
tree *createNode(int key, tree *parent) {
    tree *newNode = (tree *)malloc(sizeof(tree));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->parent = parent;
    return newNode;
}

// Функция для поиска узла по ключу
tree *findNode(tree *root, int key) {
    if (root == NULL) return NULL;
    if (root->key == key) return root;

    tree *leftResult = findNode(root->left, key);
    if (leftResult != NULL) return leftResult;

    return findNode(root->right, key);
}

// Функция для поиска брата
tree *findBrother(tree *root, int key) {
    // Находим узел с заданным ключом
    tree *node = findNode(root, key);
    if (node == NULL) return 0; // Узел не найден

    // Проверяем, есть ли родитель
    if (node->parent == NULL) return 0; // У корня нет брата

    // Определяем, кто является братом
    if (node->parent->left == node) {
        return node->parent->right; // Брат — правый дочерний узел родителя
    } else {
        return node->parent->left; // Брат — левый дочерний узел родителя
    }
}

// Пример использования
int main() {
    // Создаем дерево
    tree *root = createNode(1, NULL);
    root->left = createNode(2, root);
    root->right = createNode(3, root);
    root->left->left = createNode(4, root->left);
    root->left->right = createNode(5, root->left);
    root->right->left = createNode(6, root->right);
    root->right->right = createNode(7, root->right);

    // Поиск брата для узла с ключом 5
    int key = 5;
    tree *brother = findBrother(root, key);
    if (brother != 0) {
        printf("Брат узла с ключом %d: %d\n", key, brother->key);
    } else {
        printf("У узла с ключом %d нет брата\n", key);
    }

    // Поиск брата для узла с ключом 1 (корень)
    key = 1;
    brother = findBrother(root, key);
    if (brother != 0) {
        printf("Брат узла с ключом %d: %d\n", key, brother->key);
    } else {
        printf("У узла с ключом %d нет брата\n", key);
    }

    // Освобождение памяти (не реализовано для краткости)
    return 0;
}