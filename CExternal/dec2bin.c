#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ibase.h>

char* dectobin(int *);

char* dectobin(number)
	int *number;
{
    // int i;
    // char *output = malloc(33);
    // memset(output, 0, 33);
    // for (i = 31; i >= 0; --i, (*number) >>= 1)
    // {
    //     output[i] = ((*number) & 1) + '0';
    // }

    // return output;
    char *ret = (char*)malloc(33);
    memset(ret, '\0', 33);
    strcpy(ret, "Hola\0");
    ret[32] = '\0';
    return "Hola\0";
}