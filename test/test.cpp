#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>
#include "../merge.cpp" 

void sortArray(std::vector<int>& arr) {
    MergeSort sorter;
    sorter.sort(arr.data(), arr.size());
}

// Test case: zachowuje tablicę niezmienioną, gdy ona jest już posortowana rosnąco
TEST(SortArrayTest, AlreadySorted) {
    std::cout << "Running AlreadySorted test" << std::endl;
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = arr;
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: potrafi posortować tablicę, która jest posortowana w odwrotnej kolejności
TEST(SortArrayTest, ReverseSorted) {
    std::cout << "Running ReverseSorted test" << std::endl;
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje losową tablicę liczb
TEST(SortArrayTest, RandomArray) {
    std::cout << "Running RandomArray test" << std::endl;
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    std::vector<int> expected = { 1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje tablice tylko z liczbami ujemnymi
TEST(SortArrayTest, NegativeNumbers) {
    std::cout << "Running NegativeNumbers test" << std::endl;
    std::vector<int> arr = { -5, -1, -3, -2, -4 };
    std::vector<int> expected = { -5, -4, -3, -2, -1 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi
TEST(SortArrayTest, MixedNumbers) {
    std::cout << "Running MixedNumbers test" << std::endl;
    std::vector<int> arr = { -1, 2, -3, 4, -5 };
    std::vector<int> expected = { -5, -3, -1, 2, 4 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: obsługuje pustą tablicę bez rzucania wyjątkiem
TEST(SortArrayTest, EmptyArray) {
    std::cout << "Running EmptyArray test" << std::endl;
    std::vector<int> arr = {};
    std::vector<int> expected = {};
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: nie zmienia tablicy, która zawiera tylko jeden element
TEST(SortArrayTest, SingleElement) {
    std::cout << "Running SingleElement test" << std::endl;
    std::vector<int> arr = { 1 };
    std::vector<int> expected = { 1 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje tablicę z duplikatami liczb
TEST(SortArrayTest, Duplicates) {
    std::cout << "Running Duplicates test" << std::endl;
    std::vector<int> arr = { 5, 1, 5, 3, 5 };
    std::vector<int> expected = { 1, 3, 5, 5, 5 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje tablice ujemną z duplikatami
TEST(SortArrayTest, NegativeDuplicates) {
    std::cout << "Running NegativeDuplicates test" << std::endl;
    std::vector<int> arr = { -5, -1, -5, -3, -5 };
    std::vector<int> expected = { -5, -5, -5, -3, -1 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(SortArrayTest, MixedDuplicates) {
    std::cout << "Running MixedDuplicates test" << std::endl;
    std::vector<int> arr = { -1, 2, -3, 2, -1 };
    std::vector<int> expected = { -3, -1, -1, 2, 2 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje tablicę zawierającą tylko dwa elementy w kolejności rosnącej
TEST(SortArrayTest, TwoElements) {
    std::cout << "Running TwoElements test" << std::endl;
    std::vector<int> arr = { 2, 1 };
    std::vector<int> expected = { 1, 2 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów
TEST(SortArrayTest, LargeArray) {
    std::cout << "Running LargeArray test" << std::endl;
    std::vector<int> arr(1000);
    std::iota(arr.begin(), arr.end(), 0);
    std::vector<int> expected = arr;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(SortArrayTest, LargeMixedArray) {
    std::cout << "Running LargeMixedArray test" << std::endl;
    std::vector<int> arr(1000);
    std::iota(arr.begin(), arr.end(), -500);
    std::vector<int> expected = arr;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// ------------------------------------------------------------------------------------------------
// ----------------------------------------Dodatkowe testy-----------------------------------------


//Test case: wpisano litery zamiast liczb

TEST(SortArrayTest, LettersInsteadOfNumbers) {
    std::cout << "Running LettersInsteadOfNumbers test" << std::endl;
    std::vector<int> arr = { 'c', 'a', 'd', 'b', 'e' };
    std::vector<int> expected = { 'a', 'b', 'c', 'd', 'e' };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}