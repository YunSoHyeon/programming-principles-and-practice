// 과제 2
#include <stdio.h>

int main(void){
    int sum = 0;
    int digit = 0;
    for(int n = 1; n <= 200; n++){
        digit = 0;
        digit += n % 10;    
        int tmp = n / 10;   
        
        if(n >= 10 && n < 100)
            digit += tmp;   
        
        else if(n >= 100){
            tmp %= 10;
            digit += tmp;
            digit += n / 100;
        }
        if(n % 2 == 0 || n % 5 == 0)
            sum = sum - digit;

        else if(n % digit == 0)
            sum = sum - (sum % n);
        
        else    
            sum = sum + sum / n;

    }

    printf("%d\n", sum);

    return 0;
}