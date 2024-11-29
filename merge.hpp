#include <iostream>
class MergeSort {
    public:
    MergeSort() {};
    ~MergeSort() {};
    void sort(int* arr, int size);

    private:
    void mergeSort(int* arr, int left, int right);
    void merge(int* arr, int left, int mid, int right);

};
