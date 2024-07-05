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
    int temp;
    if (len == 0) {
        strcpy(soundex, "0000");
        return;
    }
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    char lastDigit = getSoundexCode(name[0]);
    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (!(strchr("aeiou", word[i-1]))){
            temp = 0;
        }
        if (strchr("aeiou", word[i])){
            temp = 1;
        }
        if (strchr("hw", word[i])){
            continue;
        }
        if ((code != '0' && code != soundex[sIndex - 1]) || (code != '0' && lastDigit == code && temp)) {
            soundex[sIndex++] = code;
            lastDigit = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
