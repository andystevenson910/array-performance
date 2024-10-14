#include "sortutils.hpp"
#include <algorithm>
#include <execution>
#include <iostream>
#include <chrono>
#include <vector>

// Copies elements from std::array to raw array
void initializeRawArrayFromStdArray(const SourceArray& source, int dest[]) {
    std::copy(source.begin(), source.end(), dest);
}

// Organizes the array into an organ pipe structure

void organPipeStdArray(SourceArray& data) {
    std::size_t half = data.size() / 2;

    // Copy sorted data into the first half
    for (std::size_t i = 0; i < half; ++i) {
        data[i] = data[i];
    }

    // Mirror the first half into the second half
    for (std::size_t i = half; i < data.size(); ++i) {
        data[i] = data[data.size() - 1 - i];
    }
}


// Template for evaluating the array types with sequential and parallel sorting
template<typename ArrayType>
void evaluate(const ArrayType& random, const ArrayType& sorted, const ArrayType& reversed, const ArrayType& organPipe, const ArrayType& rotated, const std::string& type) {
    using namespace std::chrono;
    ArrayType temp;

    // Sequential sort
    std::cout << "--- " << type << " Sequential ---" << std::endl;

    // Random array
    std::cout << "Random Time: ";
    auto start = high_resolution_clock::now();
    for (std::uint8_t i = 0; i < HOW_MANY_TIMES; ++i) {
        temp = random;
        std::sort(temp.begin(), temp.end());
    }
    auto end = high_resolution_clock::now();
    std::cout << duration_cast<milliseconds>(end - start).count() << " ms" << std::endl;

    // Sorted array
    std::cout << "Sorted Time: ";
    start = high_resolution_clock::now();
    for (std::uint8_t i = 0; i < HOW_MANY_TIMES; ++i) {
        temp = sorted;
        std::sort(temp.begin(), temp.end());
    }
    end = high_resolution_clock::now();
    std::cout << duration_cast<milliseconds>(end - start).count() << " ms" << std::endl;

    // Reversed array
    std::cout << "Reversed Time: ";
    start = high_resolution_clock::now();
    for (std::uint8_t i = 0; i < HOW_MANY_TIMES; ++i) {
        temp = reversed;
        std::sort(temp.begin(), temp.end());
    }
    end = high_resolution_clock::now();
    std::cout << duration_cast<milliseconds>(end - start).count() << " ms" << std::endl;

    // Organ Pipe array
    std::cout << "Organ Pipe Time: ";
    start = high_resolution_clock::now();
    for (std::uint8_t i = 0; i < HOW_MANY_TIMES; ++i) {
        temp = organPipe;
        std::sort(temp.begin(), temp.end());
    }
    end = high_resolution_clock::now();
    std::cout << duration_cast<milliseconds>(end - start).count() << " ms" << std::endl;

    // Rotated array
    std::cout << "Rotated Time: ";
    start = high_resolution_clock::now();
    for (std::uint8_t i = 0; i < HOW_MANY_TIMES; ++i) {
        temp = rotated;
        std::sort(temp.begin(), temp.end());
    }
    end = high_resolution_clock::now();
    std::cout << duration_cast<milliseconds>(end - start).count() << " ms" << std::endl;

    // Parallel sort (if supported)
#ifdef __cpp_lib_execution
    std::cout << "--- " << type << " Parallel ---" << std::endl;

    // Random array (Parallel)
    std::cout << "Random Time: ";
    start = high_resolution_clock::now();
    for (std::uint8_t i = 0; i < HOW_MANY_TIMES; ++i) {
        temp = random;
        std::sort(std::execution::par, temp.begin(), temp.end());
    }
    end = high_resolution_clock::now();
    std::cout << duration_cast<milliseconds>(end - start).count() << " ms" << std::endl;

    // Sorted array (Parallel)
    std::cout << "Sorted Time: ";
    start = high_resolution_clock::now();
    for (std::uint8_t i = 0; i < HOW_MANY_TIMES; ++i) {
        temp = sorted;
        std::sort(std::execution::par, temp.begin(), temp.end());
    }
    end = high_resolution_clock::now();
    std::cout << duration_cast<milliseconds>(end - start).count() << " ms" << std::endl;

    // Reversed array (Parallel)
    std::cout << "Reversed Time: ";
    start = high_resolution_clock::now();
    for (std::uint8_t i = 0; i < HOW_MANY_TIMES; ++i) {
        temp = reversed;
        std::sort(std::execution::par, temp.begin(), temp.end());
    }
    end = high_resolution_clock::now();
    std::cout << duration_cast<milliseconds>(end - start).count() << " ms" << std::endl;

    // Organ Pipe array (Parallel)
    std::cout << "Organ Pipe Time: ";
    start = high_resolution_clock::now();
    for (std::uint8_t i = 0; i < HOW_MANY_TIMES; ++i) {
        temp = organPipe;
        std::sort(std::execution::par, temp.begin(), temp.end());
    }
    end = high_resolution_clock::now();
    std::cout << duration_cast<milliseconds>(end - start).count() << " ms" << std::endl;

    // Rotated array (Parallel)
    std::cout << "Rotated Time: ";
    start = high_resolution_clock::now();
    for (std::uint8_t i = 0; i < HOW_MANY_TIMES; ++i) {
        temp = rotated;
        std::sort(std::execution::par, temp.begin(), temp.end());
    }
    end = high_resolution_clock::now();
    std::cout << duration_cast<milliseconds>(end - start).count() << " ms" << std::endl;

#else
    std::cout << "Parallel execution not supported on this system." << std::endl;
#endif
}

// Function to evaluate the raw array
void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated) {
    int raw[HOW_MANY_ELEMENTS];
    initializeRawArrayFromStdArray(random, raw);
    evaluate(random, sorted, reversed, organPipe, rotated, "Raw Array");
}

// Function to evaluate the std::array
void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated) {
    evaluate(random, sorted, reversed, organPipe, rotated, "std::array");
}

// Function to evaluate the std::vector
void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated) {
    std::vector<int> vec(random.begin(), random.end());
    std::vector<int> sortedVec(sorted.begin(), sorted.end());
    std::vector<int> reversedVec(reversed.begin(), reversed.end());
    std::vector<int> organPipeVec(organPipe.begin(), organPipe.end());
    std::vector<int> rotatedVec(rotated.begin(), rotated.end());

    evaluate(vec, sortedVec, reversedVec, organPipeVec, rotatedVec, "std::vector");
}
