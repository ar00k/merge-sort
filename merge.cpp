#include <iostream>
#include "merge.hpp"  // Dołączamy plik nagłówkowy, który zawiera deklaracje

// Funkcja publiczna sortująca tablicę
void MergeSort::sort(int* arr, int size) {
    if (arr == nullptr || size <= 0) {
        return;  // Jeżeli tablica jest pusta lub rozmiar jest nieprawidłowy, wychodzimy
    }
    mergeSort(arr, 0, size - 1);  // Wywołanie funkcji pomocniczej
}

// Funkcja pomocnicza realizująca algorytm merge sort
void MergeSort::mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Znalezienie środkowego indeksu

        // Rekurencyjnie dzielimy tablicę na dwie części
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Łączenie posortowanych części
        merge(arr, left, mid, right);
    }
}

// Funkcja pomocnicza łącząca dwie posortowane części tablicy
void MergeSort::merge(int* arr, int left, int mid, int right) {
    // Rozmiar lewego i prawego podciągu
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tworzenie pomocniczych tablic
    int* L = new int[n1];
    int* R = new int[n2];

    // Kopiowanie danych do tablic pomocniczych
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    // Łączenie
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Kopiowanie pozostałych elementów z L, jeśli jakieś pozostały
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Kopiowanie pozostałych elementów z R, jeśli jakieś pozostały
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    // Usuwanie tablic pomocniczych
    delete[] L;
    delete[] R;
}