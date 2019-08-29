#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int temp;
            int indice;
            for(int i = 0; i < size -1; ++i){
                indice = i;
                for(int j = i+1; j < size ; ++j ){
                    if(elements[indice]>elements[j]){
                        indice = j;
                    }
                }
                temp = elements[i];
                elements[i] = elements[indice];
                elements[indice] = temp;
            }

        }

        inline string name() { return "SelectSort"; }
};

#endif