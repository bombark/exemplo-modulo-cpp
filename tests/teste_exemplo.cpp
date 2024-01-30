/* BSD 2-Clause License
 * 
 * Copyright (c) 2024, Visao Robotica e Imagem (VRI)
 *  - Felipe Bombardelli <felipebombardelli@gmail.com>
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// ===========================================================================
//  Header
// ===========================================================================

#include "exemplo.hpp"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(exemplo) {
    void setup() {}

    void teardown() {
        // mock().clear();
    }

};

// ===========================================================================
//  Pequena documentacao do CppUTest
// ===========================================================================

/* 
 * Funcoes para checar alguma variavel
 *
 *  CHECK(boolean condition) - checks any boolean result.
 *  CHECK_TEXT(boolean condition, text) - checks any boolean result and prints text on failure.
 *  CHECK_FALSE(condition) - checks any boolean result
 *  CHECK_EQUAL(expected, actual) - checks for equality between entities using ==. So if you have a class that supports operator==() you can use this macro to compare two instances. You will also need to add a StringFrom() function like those found in SimpleString. This is for printing the objects when the check failed.
 *  CHECK_COMPARE(first, relop, second) - checks thats a relational operator holds between two entities. On failure, prints what both operands evaluate to.
 *  CHECK_THROWS(expected_exception, expression) - checks if expression throws expected_exception (e.g. std::exception). CHECK_THROWS is only available if CppUTest is built with the Standard C++ Library (default).
 *  STRCMP_EQUAL(expected, actual) - checks const char* strings for equality using strcmp().
 *  STRNCMP_EQUAL(expected, actual, length) - checks const char* strings for equality using strncmp().
 *  STRCMP_NOCASE_EQUAL(expected, actual) - checks const char* strings for equality, not considering case.
 *  STRCMP_CONTAINS(expected, actual) - checks whether const char* actual contains const char* expected.
 *  LONGS_EQUAL(expected, actual) - compares two numbers.
 *  UNSIGNED_LONGS_EQUAL(expected, actual) - compares two positive numbers.
 *  BYTES_EQUAL(expected, actual) - compares two numbers, eight bits wide.
 *  POINTERS_EQUAL(expected, actual) - compares two pointers.
 *  DOUBLES_EQUAL(expected, actual, tolerance) - compares two floating point numbers within some tolerance
 *  FUNCTIONPOINTERS_EQUAL(expected, actual) - compares two void (*)() function pointers
 *  MEMCMP_EQUAL(expected, actual, size) - compares two areas of memory
 *  BITS_EQUAL(expected, actual, mask) - compares expected to actual bit by bit, applying mask
 *  FAIL(text) - always fails
 */

// ===========================================================================
//  Tests
// ===========================================================================

TEST(exemplo, soma_dois_vetores)
{
    const int size = 4;
    int32_t vetor1[size] = {1,2,3,4};
    int32_t vetor2[size] = {11,12,13,14};
    int32_t vetor_real[size] = {12,14,16,18};
    int32_t vetor_out[size];

    bool is_ok = somaVetor(size, vetor1, vetor2, vetor_out);
    CHECK_TRUE(is_ok);
    for (int i=0; i<size; i++) {
        CHECK_EQUAL(vetor_real[i], vetor_out[i]);
    }
}

TEST(exemplo, erro_quando_entra_vetores_nulos)
{
    const int size = 4;
    int32_t vetor_dummy[size] = {1,2,3,4};
    int32_t vetor_real[size] = {0,0,0,0};
    int32_t vetor_out[size];

    {
        bool is_ok = somaVetor(size, NULL, vetor_dummy, vetor_out);
        CHECK_FALSE(is_ok);
    }

    {
        bool is_ok = somaVetor(size, vetor_dummy, NULL, vetor_out);
        CHECK_FALSE(is_ok);
    }
}

// ===========================================================================
//  Main
// ===========================================================================

int main(int ac, char** av) {
   return CommandLineTestRunner::RunAllTests(ac, av);
}