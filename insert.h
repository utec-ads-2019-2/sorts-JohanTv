#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {

            int temp, indice;
            for (int i = 1; i < size; ++i) {
                temp = elements[i];
                indice = i - 1;
                while (indice >= 0 && elements[indice] > temp) {
                    elements[indice + 1] = elements[indice];
                    indice--;
                }
                elements[indice + 1] = temp;
            }
        }
        inline string name(){ return "InsertSort"; }
};

#endif