#include <stdio.h>

// void my_strcpy(char *des, const char *src)
// {
//     int i;
//     for (i = 0; src[i] /* != \0' */; ++i){
//         des[i] = src[i];
//     }
//     des[i] = '\0';
// }

void my_strcpy(char *des, const char *src)
{
    // while (*src)
    //     *des++ = *src++;
    // *des = '\0';
    while (*des++ = *src++ )
    ;
}

int main(void)
{
    char str[100];
    char *str2 = "hollo, world";

    my_strcpy(str, str2);
    printf("str: %s\n", str);

    return 0;
}

// #include <stdio.h>

// void my_strcpy(char *des, const char *src)
// {
//     int i;
//     for (i = 0; src[i] /* != \0' */; ++i){
//         des[i] = src[i];
//     }
//     des[i] = '\0';
// }
// int main(void)
// {
//     char str[100];
//     char *str2 = "hollo, world";

//     my_strcpy(str, str2);
//     printf("str: %s\n", str);

//     return 0;
// }