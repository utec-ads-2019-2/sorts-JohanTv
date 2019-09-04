#ifndef RADIX_H
#define RADIX_H

#include "sort.h"




class RadixSort : public Sort {       
    public:
        RadixSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            radixsort();
        }

        void radixsort(){
            int max = *max_element(elements, elements+size);

            for (int exp = 1; max/exp > 0; exp *= 10)
                countSort(exp);
        }


        void countSort(int exp){
            int* listaOrdenada = new int[size];
            int i, count[10] = {0};

            for (i = 0; i < size; i++)
                count[ (elements[i]/exp)%10 ]++;

            for (i = 1; i < 10; i++)
                count[i] += count[i - 1];

            for (i = size - 1; i >= 0; i--){
                listaOrdenada[count[ (elements[i]/exp)%10 ] - 1] = elements[i];
                count[ (elements[i]/exp)%10 ]--;
            }

            for (i = 0; i < size; i++)
                elements[i] = listaOrdenada[i];

            delete[] listaOrdenada;
        }



    inline string name() { return "RadixSort"; }
};

#endif