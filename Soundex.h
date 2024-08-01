
#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
/*#ifndef SOUNDEX_H
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
*/
