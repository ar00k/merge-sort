#include <iostream>

/**
 * @class MergeSort
 * @brief Klasa implementująca algorytm sortowania przez scalanie (MergeSort).
 */
class MergeSort {
    public:
    /**
     * @brief Konstruktor domyślny klasy MergeSort.
     */
    MergeSort() {};

    /**
     * @brief Destruktor klasy MergeSort.
     */
    ~MergeSort() {};

    /**
     * @brief Sortuje tablicę liczb całkowitych za pomocą algorytmu MergeSort.
     *
     * @param arr Wskaźnik do tablicy do posortowania.
     * @param size Rozmiar tablicy.
     */
    void sort(int* arr, int size);

    private:
    /**
     * @brief Funkcja pomocnicza do rekurencyjnego dzielenia tablicy na części.
     *
     * @param arr Wskaźnik do tablicy.
     * @param left Indeks początkowy obecnego zakresu.
     * @param right Indeks końcowy obecnego zakresu.
     */
    void mergeSort(int* arr, int left, int right);

    /**
     * @brief Scala dwie części tablicy w jeden posortowany ciąg.
     *
     * @param arr Wskaźnik do tablicy.
     * @param left Indeks początkowy pierwszej części.
     * @param mid Indeks końcowy pierwszej części (środek zakresu).
     * @param right Indeks końcowy drugiej części.
     */
    void merge(int* arr, int left, int mid, int right);
};
