#include "int_vector.h"
#include <stdio.h>
#include <stdlib.h>


vector createVector(size_t n) {
    vector vec;
    vec.size = n;
    vec.capacity = n > 0 ? n : 1; // Устанавливаем вместимость как минимум 1, если n = 0
    vec.data = (int *)malloc(vec.capacity * sizeof(int)); // Выделяем память под массив

    if (vec.data == NULL) {
        fprintf(stderr, "bad alloc\n");
        exit(1);
    }

    return vec;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
    }

    void *newData = realloc(v->data, newCapacity * sizeof(int));
    if (newData == NULL && newCapacity != 0) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    v->data = newData;
    v->capacity = newCapacity;
}

void clear(vector *v) {v->size = 0;}

void shrinkToFit(vector *v) {
    if (v->size < v->capacity) {
        v->capacity = v->size;
        v->data = (int *) realloc(v->data, v->capacity * sizeof(int));
    }
}
void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isFull(vector* v) {
    return v->size >= v->capacity;
}

bool isEmpty(vector* v) {
    return v->size == 0;
}


int getVectorValue(vector *v, size_t i){
    return v->data[i];
}

void pushBack(vector *v, int x){
    if(v->size == v->capacity){
        reserve(v, 2 * v->capacity);
    }

    v->data[v->size] = x;
    v->size++;
}

void popBack(vector* v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty. Cannot pop back.\n");
        exit(1);
    }
    v->size--;
}

int* atVector(vector* v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "Index out of range.\n");
        exit(1);
    }
    return &(v->data[index]);
}

int* back(vector* v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty.\n");
        exit(1);
    }
    return &(v->data[v->size - 1]);
}

int* front(vector* v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty.\n");
        exit(1);
    }
    return &(v->data[0]);
}

