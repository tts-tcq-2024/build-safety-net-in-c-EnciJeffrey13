
#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

//ABCDEFGHIJKLMNOPQRSTUVWXYZ
const int Mapping[26] = {
    0, 1, 2, 3, 0, 1, 2, 0, 0, 2,
    2, 4, 5, 5, 0, 1, 2, 6, 2, 3,
    0, 1, 0, 2, 0, 2             
};

char getSoundexCode(char c) {
    c = toupper(c);
    if (c < 'A' || c > 'Z') {
        return '0'; }
    return Mapping[c - 'A'] + '0';}

void endSoundexCode(int sIndex, char *soundex){
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
    soundex[4] = '\0';
}
int updateSoundexCode(char code, int sIndex, char *soundex){
    if (code != '0' && code != soundex[sIndex - 1]) {
        soundex[sIndex++] = code;
    }
    return sIndex;
}
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    int i = 1;
    for (i = 1; (i<len && sIndex < 4); i++) {
        char code = getSoundexCode(name[i]);
        sIndex = updateSoundexCode(code, sIndex, soundex);}
        endSoundexCode(sIndex, soundex);
}
#endif // SOUNDEX_H
