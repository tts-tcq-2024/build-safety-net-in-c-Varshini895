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

int canAppendCode(char *soundex, int sIndex, char code) {
    return sIndex < 4 && code != '0' && code != soundex[sIndex - 1];
}

int modifySoundex(char code, int currentIndex, char *soundex) {
    int notZero = code != '0';
    if (notZero) {
        soundex[currentIndex] = code;
        return ++currentIndex;
    }
    soundex[currentIndex] = soundex[currentIndex];
    return currentIndex;
}

void modifyCode(char *soundex, int *sIndex, char code) {
    if (canAppendCode(soundex, *sIndex, code)) {
        soundex[(*sIndex)++] = code;
    }
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        modifyCode(soundex, &sIndex, getSoundexCode(name[i]));
    }
    memset(soundex + sIndex, '0', 4 - sIndex);
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
