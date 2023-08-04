#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char *s)
{
    /* Return the length of string s using the C convention of
     * being terminated by the NULL character. 
     * Do not call any other functions whatsoever.
     * Even my_strlen -- no solutions involving recursion. */
    int totalLength = 0;
    while (*s != '\0'){
        totalLength++;
        s++;
    }
    return totalLength;
}

void str_reverse(char *str)
{
    /* Modify s to be the reverse string.
     * If s is "hello" when the function is called, then it
     * should be "olleh" when the function is completed. 
     * The only function you can call is my_strlen.
     * Do not call malloc.  */
    int stringLength = my_strlen(str);
    char tmp;
    
    for (int i = 0; i < (stringLength / 2); i++){
        tmp = str[i];
        str[i] = str[((stringLength - 1) - i)]; 
        str[((stringLength - 1) - i)] = tmp;
    }

    /*
    //Tried this implementation first but soon realized it wouldn't work
    char reversedString[stringLength + 1]; 

    for (int i = (stringLength - 1); i >= 0; i--){
        reversedString[((stringLength - 1) - i)] = str[i];
        
    }
    reversedString[stringLength] = '\0';

    printf("Reversed String = %s\n", reversedString);
    return reversedString;
    */

}

int main()
{
    char *str = malloc(strlen("hello world")+1);
    strcpy(str, "hello world");
    str_reverse(str);
    if (strcmp(str, "dlrow olleh") == 0)
    {   
        printf("Congrats!  You have successfully reversed \"hello world\" to \"%s\"\n", str);
        free(str);
        exit(EXIT_SUCCESS);
    }
    else
    {   
        printf("Project does not work yet.  You reversed \"hello world\" to \"%s\"\n", str);
        free(str);
        exit(EXIT_FAILURE);
    }
}
