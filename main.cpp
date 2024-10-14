#include "sortutils.hpp"
#include <algorithm>
#include <random>
#include <iostream>

int main() {
    SourceArray random, sorted, reversed, organPipe, rotated;

    // Initialize random array
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-10000000, 10000000);
    for (auto& num : random) {
        num = dis(gen);
    }

    // Prepare other arrays
    sorted = random;
    std::sort(sorted.begin(), sorted.end());

    reversed = sorted;
    std::reverse(reversed.begin(), reversed.end());

    organPipe = sorted;
    organPipeStdArray(organPipe);

    rotated = sorted;
    std::rotate(rotated.begin(), rotated.begin() + 1, rotated.end());

    // Evaluate each type of array
    evaluateRawArray(random, sorted, reversed, organPipe, rotated);
    evaluateStdArray(random, sorted, reversed, organPipe, rotated);
    evaluateStdVector(random, sorted, reversed, organPipe, rotated);

    return 0;
}
