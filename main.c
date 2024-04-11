#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include "libs/data_structures/vector/void_vector.h"

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} vector;

vector createVector(size_t capacity) {
    vector v;
    v.data = malloc(capacity * sizeof(int));
    v.size = 0;
    v.capacity = capacity;
    return v;
}

bool isEmpty(const vector* v) {
    return v->size == 0;
}

bool isFull(const vector* v) {
    return v->size == v->capacity;
}

void pushBack(vector* v, int element) {
    if (isFull(v)) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = element;
}

void popBack(vector* v) {
    if (isEmpty(v)) {
        printf("Vector is empty.\n");
        return;
    }
    v->size--;
    // Optional: Resize the vector if necessary
    if (v->size < v->capacity / 2) {
        v->capacity /= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
}

int* atVector(const vector* v, size_t index) {
    if (index >= v->size) {
        printf("Index out of bounds.\n");
        return NULL;
    }
    return &(v->data[index]);
}

int* back(const vector* v) {
    if (isEmpty(v)) {
        printf("Vector is empty.\n");
        return NULL;
    }
    return &(v->data[v->size - 1]);
}

int* front(const vector* v) {
    if (isEmpty(v)) {
        printf("Vector is empty.\n");
        return NULL;
    }
    return &(v->data[0]);
}

void test_pushBack_emptyVector(vector *v) {
    assert(isEmpty(v));
}

void test_pushBack_fullVector(vector *v) {
    assert(isFull(v));
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v;
    int data[] = {1, 2, 3, 4, 5};
    v.data = data;
    v.size = sizeof(data) / sizeof(data[0]);

    for (size_t i = 0; i < v.size; i++) {
        int *element = atVector(&v, i);
        assert(*element == data[i]);
    }

    printf("test_atVector_notEmptyVector passed.\n");
}

void test_atVector_requestToLastElement() {
    vector v;
    int data[] = {1, 2, 3, 4, 5};
    v.data = data;
    v.size = sizeof(data) / sizeof(data[0]);

    int *lastElement = atVector(&v, v.size - 1);
    assert(*lastElement == data[v.size - 1]);

    printf("test_atVector_requestToLastElement passed.\n");
}

void test_back_oneElementInVector() {
    vector v;
    int data[] = {42};
    v.data = data;
    v.size = sizeof(data) / sizeof(data[0]);

    int *lastElement = back(&v);
    assert(*lastElement == data[0]);

    printf("test_back_oneElementInVector passed.\n");
}

void test_front_oneElementInVector() {
    vector v;
    int data[] = {42};
    v.data = data;
    v.size = sizeof(data) / sizeof(data[0]);

    int *firstElement = front(&v);
    assert(*firstElement == data[0]);

    printf("test_front_oneElementInVector passed.\n");
}

void test(vector *v) {
    printf("Is empty: %d\n", isEmpty(v));
    printf("Is full: %d\n", isFull(v));
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
    test_popBack_notEmptyVector();
}

int main() {
    size_t n;
    scanf("%zd", &n);
    vectorVoid v = createVectorV(0, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pushBackV(&v, &x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        getVectorValueV(&v, i, &x);
        printf("%d ", x);
    }
    return 0;
}
