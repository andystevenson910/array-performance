#ifndef SORTUTILS_HPP
#define SORTUTILS_HPP

#include <array>
#include <vector>
#include <cstddef>
#include <cstdint>

// Constants
const std::size_t HOW_MANY_ELEMENTS = 250000;
const std::uint8_t HOW_MANY_TIMES = 25;

// Type definitions
using SourceArray = std::array<int, HOW_MANY_ELEMENTS>;

// Function prototypes
void initializeRawArrayFromStdArray(const SourceArray& source, int dest[]);
void organPipeStdArray(SourceArray& data);

// Evaluation function prototypes
void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated);
void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated);
void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated);

// Template function to evaluate different array types
template<typename ArrayType>
void evaluate(const ArrayType& random, const ArrayType& sorted, const ArrayType& reversed, const ArrayType& organPipe, const ArrayType& rotated, const std::string& type);

#endif
