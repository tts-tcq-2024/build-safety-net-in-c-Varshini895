#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>
#include <stdio.h>


char getSoundexCode(char l) {
    static const char codeTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', // A-I
        '2', '2', '4', '5', '5', '0', '1', '2', '6', // J-R
        '2', '3', '0', '1', '0', '2', '0', '2'       // S-Z
    };
    L = toupper(l);
    if (isalpha(L)) {
        return codeTable[L - 'A'];
    }
    return '0';
}
 
// Function to check if the code can be appended to the Soundex string
int canAppendCode(char *soundex, int sIndex, char code) {
    return sIndex < 4 && code != '0' && code != soundex[sIndex - 1];
}
 
// Function to modify the Soundex string by appending the code if allowed
void modifyCode(char *soundex, int *sIndex, char code) {
    if (canAppendCode(soundex, *sIndex, code)) {
        soundex[(*sIndex)++] = code;
    }
}
 
// Function to generate the Soundex code for a given name
void generateSoundex(const char *name, char *soundex) {
    int length = strlen(name);
    soundex[0] = toupper(name[0]); // First letter of the name
    int sIndex = 1;
 
    // Iterate through the name to generate the Soundex code
    for (int i = 1; i < length && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        modifyCode(soundex, &sIndex, code);
    }
    // Pad the Soundex code with '0's if it's less than 4 characters long
    memset(soundex + sIndex, '0', 4 - sIndex);
    soundex[4] = '\0'; // Null-terminate the string
}

#endif // SOUNDEX_H
