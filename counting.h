#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int* listaOrdenada = new int[size]{0};
            int min = *min_element(elements,elements+size);
            int max = *max_element(elements,elements+size);
            int length = max - min + 1;
            int* count = new int[length]{0};

            for (int i = 0; i < size; ++i) {
                count[elements[i]-min]++;
            }

            for (int i = 1; i < length; ++i) {
                count[i]+=count[i-1];
            }

            for (int i = size - 1; i >= 0; --i) {
                listaOrdenada[count[elements[i] - min] - 1] = elements[i];
                count[elements[i] - min]--;
            }

            for (int i = 0; i < size; ++i) {
                elements[i] = listaOrdenada[i];
            }

            delete[] count;
            delete[] listaOrdenada;
        }

        inline string name() { return "CountingSort"; }
};

#endif