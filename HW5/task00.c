#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    unsigned short *array;
    unsigned char k;
    size_t arraySize, i;

    // Открываем файл input.bin для чтения
    inputFile = fopen("input.bin", "rb");
    if (inputFile == NULL) {
        perror("Не удалось открыть файл input.bin");
        return EXIT_FAILURE;
    }

    // Определяем размер массива
    fseek(inputFile, 0, SEEK_END);
    arraySize = ftell(inputFile) - 1; // -1, так как последний байт это число k
    arraySize /= sizeof(unsigned short); // Количество элементов в массиве
    fseek(inputFile, 0, SEEK_SET);

    // Выделяем память под массив
    array = (unsigned short *)malloc(arraySize * sizeof(unsigned short));
    if (array == NULL) {
        perror("Не удалось выделить память");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Читаем массив и число k
    fread(array, sizeof(unsigned short), arraySize, inputFile);
    fread(&k, sizeof(unsigned char), 1, inputFile);
    fclose(inputFile);

    // Выполняем циклический сдвиг массива на k элементов влево
    for (i = 0; i < k; i++) {
        unsigned short temp = array[0];
        for (size_t j = 0; j < arraySize - 1; j++) {
            array[j] = array[j + 1];
        }
        array[arraySize - 1] = temp;
    }

    // Открываем файл output.bin для записи
    outputFile = fopen("output.bin", "wb");
    if (outputFile == NULL) {
        perror("Не удалось открыть файл output.bin");
        free(array);
        return EXIT_FAILURE;
    }

    // Записываем результат в файл output.bin
    fwrite(array, sizeof(unsigned short), arraySize, outputFile);
    fclose(outputFile);

    // Освобождаем память
    free(array);

    return EXIT_SUCCESS;
}