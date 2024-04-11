#ifndef LAB14_INT_VECTOR_H
#define LAB14_INT_VECTOR_H

#include <corecrt.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;


vector createVector(size_t n);// возвращает структуру-дескриптор вектор из n значений.

void reserve(vector *v, size_t newCapacity);//изменяет количество памяти, выделенное под хранение элементов вектора.

void clear(vector *v);//удаляет элементы из контейнера, но не освобождает выделенную память.

void shrinkToFit(vector *v);//освобождает память, выделенную под неиспользуемые элементы

void deleteVector(vector *v);//освобождает память, выделенную вектору

bool isEmpty(vector *v);// функция проверки является ли массив пустым

bool isFull(vector *v);// функция проверки является ли массив полным

int getVectorValue(vector *v, size_t i);//возвращает i-ый элемент вектора v

void pushBack(vector *v, int x);//добавляет элемент x в конец вектора v.

void popBack(vector *v);// удаляет последний элемент из вектора

int* atVector(vector *v, size_t index);//возвращает указатель на index-ый элемент вектора.

int* back(vector *v);//возвращает указатель на последний элемент вектора

int* front(vector *v);//возвращает указатель на нулевой элемент вектора

#endif //LAB14_INT_VECTOR_H