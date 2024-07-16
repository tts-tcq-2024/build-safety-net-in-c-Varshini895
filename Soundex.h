#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {

    static const char soundexTable[26] = {

        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'

    };
 
    c = toupper(c);

    if (c >= 'A' && c <= 'Z') {

        return soundexTable[c - 'A'];

    }

    return '0'; // For non-alphabet characters

}
 
 
void generateSoundex(const char *name, char *soundex) {
    if (name[0] == '\0') {
        strcpy(soundex, "0000");
        return;
    }

    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    char lastDigit = getSoundexCode(name[0]);

    for (int i = 1; name[i] != '\0' && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        char upperChar = toupper(name[i]);

        if (code == '0' || code == lastDigit || strchr("AEIOUYHW", upperChar)) {
            if (strchr("AEIOU", upperChar)) lastDigit = '0';
            continue;
        }

        soundex[sIndex++] = code;
        lastDigit = code;
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
