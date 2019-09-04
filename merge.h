#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            mergeSort(0,size-1);
        }
        void merge(int l, int m, int r)
        {
            int i, j, k;
            int n1 = m - l + 1;
            int n2 =  r - m;

            int* L= new int[n1];
            int* R = new int[n2];

            for (i = 0; i < n1; i++)
                L[i] = elements[l + i];
            for (j = 0; j < n2; j++)
                R[j] = elements[m + 1+ j];


            i = 0;
            j = 0;
            k = l;

            while (i < n1 && j < n2){
                if (L[i] <= R[j]){
                    elements[k] = L[i];
                    i++;
                }
                else{
                    elements[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1){
                elements[k] = L[i];
                i++;
                k++;
            }

            while (j < n2){
                elements[k] = R[j];
                j++;
                k++;
            }

            delete L;
            delete R;
        }



        void mergeSort(int l, int r){
            if (l < r){
                int m = l+(r-l)/2;

                mergeSort(l, m);
                mergeSort(m+1, r);

                merge(l, m, r);
            }
        }


    inline string name() { return "MergeSort"; }
};

#endif