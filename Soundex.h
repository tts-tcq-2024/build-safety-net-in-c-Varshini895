#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>
#include <stdio.h>

char getSoundexCode(char c) {
    static const char codeTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', // A-I
        '2', '2', '4', '5', '5', '0', '1', '2', '6', // J-R
        '2', '3', '0', '1', '0', '2', '0', '2'      // S-Z
    };
    c = toupper(c);
    if (isalpha(c)) {
        return codeTable[c - 'A'];
    }
    return '0';
}

int modifySoundex(char code, int currentIndex, char *soundex) {
    if (code != '0') {
        soundex[currentIndex] = code;
        return ++currentIndex;
    }
    soundex[currentIndex] = soundex[currentIndex];
    return currentIndex;
}

void generateSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1, len = strlen(name); i < len && sIndex <= 3; i++) {
        char code = getSoundexCode(name[i]);
        sIndex = modifySoundex(code, sIndex, soundex);
    }
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
