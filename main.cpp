#include <iostream>
#include "merge.hpp"
#include <sstream>
#include <stdexcept>

int main() {
    //_________________________________Wprowadzanie Danych____________________________________

    // Prosba o wprowadzenie danych
    std::cout << "Enter numbers separated by spaces:" << std::endl;

    // Zczytanie calej linii wejsciowej
    std::string line;
    std::getline(std::cin, line);


    //_________________________________Walidacja____________________________________

    // Sprawdzenie, czy dane wejsciowe nie sa puste
    if (line.empty()) {
        std::cout << "No input provided!" << std::endl;
        return 1;
    }

    // Inicjalizacja wskaznika na dynamicznie alokowana tablice
    int* arr = nullptr;
    int capacity = 0;
    int size = 0;

    // Sprawdzenie poprawnosci danych wejsciowych
    std::stringstream ss(line);  // Tworzymy strumien z wczytanej linii
    std::string token;
    while (ss >> token) {
        bool isValid = true;

        // Sprawdzamy, czy token jest liczba calkowita, z uwzglednieniem liczby ujemnej
        if (token[0] == '-') {
            for (size_t i = 1; i < token.size(); ++i) {
                if (!isdigit(token[i])) {
                    isValid = false;
                    break;
                }
            }
        } else {  // Jesli liczba nie jest ujemna
            for (char c : token) {
                if (!isdigit(c)) {  // Sprawdzamy, czy wszystkie znaki to cyfry
                    isValid = false;
                    break;
                }
            }
        }

        if (!isValid) {  // Jesli token nie jest liczba calkowita
            std::cout << "Invalid input: " << token << std::endl;
            return 1;
        }
    }

    // Czyscimy strumien i przygotowujemy do parsowania liczb
    ss.clear();
    ss.str(line);

    int value;
    while (ss >> value) {
        // Jesli tablica jest pelna, zwiekszamy jej pojemnosc
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            int* newArr = new int[capacity];

            // Przenosimy dane ze starej tablicy do nowej
            for (int i = 0; i < size; ++i) {
                newArr[i] = arr[i];
            }

            // Usuwamy stara tablice i wskazujemy na nowa
            delete[] arr;
            arr = newArr;
        }

        // Dodajemy nowa liczbe do tablicy
        arr[size++] = value;
    }

    // Jesli zadna liczba nie zostala wprowadzona, konczymy program
    if (size == 0) {
        std::cout << "No numbers were entered!" << std::endl;
        return 1;
    }
    //_________________________________Sortowanie____________________________________
        // Wyswietlamy tablice przed sortowaniem
    std::cout << "Before sorting: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Usuwamy dynamicznie alokowana tablice
    delete[] arr;

    return 0;
}
