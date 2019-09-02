#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute(){

            quickSort(0,size-1);
        }
        void quickSort(int low, int hight){
            if(low < hight){
                int i = particion(low, hight);
                quickSort(low,i-1);
                quickSort(i+1,hight);
            }
        }

        int particion(int low, int hight){
            int pivot = elements[low];
            int i = low;
            int j = hight ;

            while(i<j){
                while(pivot < elements[j]){
                    j--;
                }
                while(i<j && elements[i]<=pivot){
                    i++;
                }
                if(i<j){
                    swap(elements[i],elements[j]);
                }
            }
            swap(elements[j],elements[low]);
            return (i);

        }

        inline string name() { return "QuickSort"; }
};

#endif