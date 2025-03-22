// 과제 3
#include <stdio.h>
#include <string.h>

typedef enum {
    START,
    STATE1,
    STATE2,
} State;

int process_word(const char*);

int main(void) {
    char input[] = "A CL KL COL KOL COKOO COOOOOL KOAHL COCOCOCOL CKOL CL COKOOOOOOOL CL KOOOOOCL COLLCOL POKCM WKRCO COCOCOCOL KCKCKCOL KOKOLKOL KL COOOOOOOKL";
    char* word;

    word = strtok(input, " ");

    while (word != NULL) {
        int result = process_word(word);
        printf("%d", result);  // print outcomes
        word = strtok(NULL, " ");
    }

    return 0;
}

int process_word(const char* word) {
    // Implement your code as here
    State current = START;
    
    if(word[0] == 'C' || word[0] == 'K')
        current = STATE1;
    else return 0;

    for(int i = 1; i < strlen(word); i++){
        if(current == STATE1 && word[i] == 'O')
            current = STATE2;
        else if(current == STATE2){
            if(word[i] == 'C' || word[i] == 'K')
                current = STATE1;
            else if(word[i] == 'O')   
                current = STATE2;
            else if(word[i] == 'L' && i == (strlen(word)-1))
                return 1;
            else return 0;
        }
        else return 0;
    }
    // Test code that prints the word //
    // for (int i = 0; i < strlen(word); i++) {
    //     printf("%c", word[i]);
    // }
    // printf("\n");

    // Rnd of test code

    return 0;

}