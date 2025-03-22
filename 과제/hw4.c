// 과제 4
#include <stdio.h>
#include <string.h>

void decryption(char* code){
    char alphabet[27];
    int codeLength = strlen(code);
    char result[codeLength + 1];

    int i, index, offset;

    for(i = 0; i < 26; i++)
        alphabet[i] = 'A' + i;
    alphabet[i] = '\0';
    
    i = index = offset = 0;
    while (i < codeLength){
        if(code[i] == '-')  
            result[i] = '-';
        else {
            offset = code[i] - '0';
            index += offset;
            int point = (offset + index) % 26;
            result[i] = *(&alphabet[0] + point);
        }
        i++;
    }
    result[i] = '\0';
    for(int i = 0; i < codeLength; i++)
        printf("%c", result[i]);
    
}

int main(void){
    char* letter = "0123456789-2381937466-015628391847-34849512067";
    decryption(letter);
    return 0;
}