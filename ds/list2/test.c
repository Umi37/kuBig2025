#include <stdio.h>

int main(void) {
    char *s = "Hello";
    printf("Address of Hello: %p\n", s);

    s = "Hi";
    printf("Address of Hi: %p\n", s);

    return 0;
}

// #include <stdio.h>

// char sayHello(char name) {
//     printf("Hello, %s!\n", name);
// }

// int main(void)
// {
//     sayHello('u');
//     return 0;
// }
// // #include <stdio.h>

// // int sayHello(char *name) {
// //     printf("Hello, %s!\n", name);
// // }

// // int main(void)
// // {
// //     sayHello(char Umi);
// //     return 0;
// // }