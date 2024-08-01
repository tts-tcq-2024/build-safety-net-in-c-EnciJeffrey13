#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

// Map letters to Soundex digits
static const char soundexMap[26] = {
    '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
};

// Convert character to corresponding Soundex digit
static char getSoundexDigit(char c) {
    if (isalpha(c)) {
        return soundexMap[toupper(c) - 'A'];
    }
    return '0';
}

// Generate Soundex code for the given input string
void computeSoundex(const char *input, char *output) {
    output[0] = toupper(input[0]);
    int outIndex = 1;
    char lastDigit = getSoundexDigit(output[0]);

    for (int i = 1; input[i] != '\0' && outIndex < 4; i++) {
        char currentDigit = getSoundexDigit(input[i]);
        if (currentDigit != '0' && currentDigit != lastDigit) {
            output[outIndex++] = currentDigit;
            lastDigit = currentDigit;
        }
    }

    while (outIndex < 4) {
        output[outIndex++] = '0';
    }

    output[4] = '\0';
}
