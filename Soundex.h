#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Mapping for consonants based on Soundex rules
const int Mapping[26] = {
    0, 1, 2, 3, 0, 1, 2, 0, 0, 2,
    2, 4, 5, 5, 0, 1, 2, 6, 2, 3,
    0, 1, 0, 2, 0, 2
};

// Get Soundex code for a given character
char getSoundexCode(char c) {
    c = toupper(c);
    if (c < 'A' || c > 'Z') {
        return '0';
    }
    return Mapping[c - 'A'] + '0';
}

// Pad the Soundex code to ensure it is four characters long
void padSoundexCode(int sIndex, char *soundex) {
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
    soundex[4] = '\0';
}

// Update the Soundex code by checking the current character
int updateSoundexCode(char code, int sIndex, char *soundex) {
    if (code != '0' && code != soundex[sIndex - 1]) {
        soundex[sIndex++] = code;
    }
    return sIndex;
}

// Generate the Soundex code for a given name
void generateSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; name[i] != '\0' && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        sIndex = updateSoundexCode(code, sIndex, soundex);
    }
    padSoundexCode(sIndex, soundex);
}

#endif // SOUNDEX_H
