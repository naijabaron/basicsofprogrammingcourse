#include <stdlib.h>
#include <string.h>
#include "void_vector.h"


vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v;
    v.data = malloc(n * baseTypeSize);
    v.size = n;
    v.capacity = n;
    v.baseTypeSize = baseTypeSize;
    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity > v->capacity) {
        void *newData = realloc(v->data, newCapacity * v->baseTypeSize);
        if (newData) {
            v->data = newData;
            v->capacity = newCapacity;
        }
    }
}

void shrinkToFitV(vectorVoid *v) {
    if (v->size < v->capacity) {
        void *newData = realloc(v->data, v->size * v->baseTypeSize);
        if (newData) {
            v->data = newData;
            v->capacity = v->size;
        }
    }
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (index < v->size) {
        char *src = (char *)v->data + index * v->baseTypeSize;
        memcpy(destination, src, v->baseTypeSize);
    }
}
void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index < v->size) {
        void *dest = (char *)v->data + index * v->baseTypeSize;
        memcpy(dest, source, v->baseTypeSize);
    }
}

void popBackV(vectorVoid *v) {
    if (v->size > 0) {
        v->size--;
    }
}

void pushBackV(vectorVoid *v, void *source) {
    if (v->size == v->capacity) {
        size_t newCapacity = v->capacity * 2;
        void *newData = realloc(v->data, newCapacity * v->baseTypeSize);
        if (newData) {
            v->data = newData;
            v->capacity = newCapacity;
        } else {
            // Ошибка перевыделения памяти
            return;
        }
    }

    void *dest = (char *)v->data + v->size * v->baseTypeSize;
    memcpy(dest, source, v->baseTypeSize);
    v->size++;
}