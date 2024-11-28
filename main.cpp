#include <iostream>
#include "merge.hpp"
#include <sstream>
int main() {
    // przyjmowanie linii
    std::cout << "Enter numbers separated by spaces:" << std::endl;

    // zczytywanie linii
    std::string line;
    std::getline(std::cin, line);


    // czyszczenie w celu parsowania liczb
    int* arr = nullptr;
    int capacity = 0;
    int size = 0;

    // sprawdzanie blednego wejscia
    std::stringstream ss(line);
    std::string token;
    while (ss >> token) {
        for (char c : token) {
            if (!isdigit(c) && c != '-') {
                std::cout << "Invalid input: " << token << std::endl;
                return 1;
            }
        }
    }

    ss.clear();
    ss.str(line);

    int value;
    while (ss >> value) {
        // jesli tablica pelna, zwieksz pojemnosc
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            int* newArr = new int[capacity];

            // przeniesienie danych do nowej tablicy
            for (int i = 0; i < size; ++i) {
                newArr[i] = arr[i];
            }

            // usuniecie starej tablicy
            delete[] arr;
            arr = newArr;
        }

        // zwiekszenie rozmiaru i dodanie wartosci
        arr[size++] = value;
    }

    if (size == 0) {
        std::cout << "No numbers were entered!" << std::endl;
        return 1;
    }

    //wysietlanie tablicy przed sortowaniem
    std::cout << "Before sorting: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
}
