/* 과제 1 */
#include <stdio.h>

int main(void){
    int sec = 1;
    int m = 2;
    while(sec <= 20){
        printf("%dsec -> %dm\n", sec, m);
        if(sec >= 5) m += 5;
        else    m += 2;
        sec++;
    }
    return 0;
}