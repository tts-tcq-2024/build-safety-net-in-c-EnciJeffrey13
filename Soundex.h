// // #ifndef SOUNDEX_H
// // #define SOUNDEX_H

// // #include "Soundex.h"
// // #include <ctype.h>
// // #include <string.h>

// // char getSoundexCode(char c) {
// //     c = toupper(c);
// //     switch (c) {
// //         case 'B': case 'F': case 'P': case 'V': return '1';
// //         case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
// //         case 'D': case 'T': return '3';
// //         case 'L': return '4';
// //         case 'M': case 'N': return '5';
// //         case 'R': return '6';
// //         default: return '0'; // For A, E, I, O, U, H, W, Y
// //     }
// // }

// // void generateSoundex(const char *name, char *soundex) {
// //     int len = strlen(name);
// //     soundex[0] = toupper(name[0]);
// //     int sIndex = 1;

// //     for (int i = 1; i < len && sIndex < 4; i++) {
// //         char code = getSoundexCode(name[i]);
// //         if (code != '0' && code != soundex[sIndex - 1]) {
// //             soundex[sIndex++] = code;
// //         }
// //     }

// //     while (sIndex < 4) {
// //         soundex[sIndex++] = '0';
// //     }

//  // ASSERT_EQ(soundex,"A200");
// }
// //     soundex[4] = '\0';
// // }

// // #endif // SOUNDEX_H
// // #ifndef SOUNDEX_H
// // #define SOUNDEX_H
 
// // #include <ctype.h>
// // #include <string.h>
// // #include <stdio.h>
 
// // char getSoundexCode(char c) {
// //     static const char codeTable[26] = {
// //         '0', '1', '2', '3', '0', '1', '2', '0', '0','2', '2', '4', '5', '5', '0', '1', '2', '6',  '2', '3', '0', '1', '0', '2', '0', '2'     
// //     };
// //      c = toupper(c);
// //     if (isalpha(c)) {
// //         return codeTable[c - 'A'];
// //     }
// //     return '0';
// // }  
 
// // int updateSoundex(char code, int sIndex, char *soundex) {
// //     int notZero = code != '0';
// //     if (notZero) {
// //         soundex[sIndex] = code;
// //         return ++sIndex;
// //     } 
// //     soundex[sIndex] = soundex[sIndex];
// //     return sIndex;
// // }
// // void generateSoundex(const char *name, char *soundex) {
// //     soundex[0] = toupper(name[0]);
// //     int sIndex = 1;
 
// //      for (int i = 1; name[i] != '\0' && sIndex <=3; i++) {
// //         char code = getSoundexCode(name[i]);
// //         sIndex = updateSoundex(code, sIndex, soundex); 
// //     }
// //     memset(soundex + sIndex, '0', 4 - sIndex);
// //     soundex[4] = '\0';
// // }
 
// // #endif // SOUNDEX_H
// #ifndef SOUNDEX_H
// #define SOUNDEX_H

// #include <ctype.h>
// #include <string.h>

// static char getSoundexCode(char c) {
//     static const char codeTable[26] = {
//         '0', '1', '2', '3', '0', '1', '2', '0', '0','2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'     
//     };
//     c = toupper(c);
//     if (isalpha(c)) {
//         return codeTable[c - 'A'];
//     }
//     return '0';
// }

// static void generateSoundex(const char *name, char *soundex) {
//     soundex[0] = toupper(name[0]);
//     int sIndex = 1;

//     for (int i = 1; name[i] != '\0' && sIndex < 4; i++) {
//         char code = getSoundexCode(name[i]);
//         if (code != '0' && code != soundex[sIndex - 1]) {
//             soundex[sIndex++] = code;
//         }
//     }

//     // Pad with '0' if necessary
//     while (sIndex < 4) {
//         soundex[sIndex++] = '0';
//     }
//     soundex[4] = '\0';
// }

// #endif // SOUNDEX_H
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
