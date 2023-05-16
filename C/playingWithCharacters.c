#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 65535

int main() 
{

    char* character, phrase[MAX_LEN], se[MAX_LEN];   
    scanf("%c", &character);
    scanf("%s", phrase);
    scanf("\n");
    scanf("%[^\n]%*c", se);
    
    printf("%c\n", character);
    printf("%s\n", phrase);
    printf("%s\n", se);
    return 0;
}
