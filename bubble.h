#ifndef BUBBLE_H
#define BUBBLE_H

#include "sort.h"
#include <algorithm>

class BubbleSort : public Sort {       
    public:
        BubbleSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int temp;
            for(int i=size-1; i>=0 ; i--){
                for(int j=0; j<i;j++){
                    if(elements[j]>elements[j+1]){
                        temp = elements[j];
                        elements[j] = elements[j+1];
                        elements[j+1] = temp;
                    }
                }
            }
        }

        inline string name() { return "BubbleSort"; }
};

#endif