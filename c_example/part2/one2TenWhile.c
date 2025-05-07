// 1~10 까지 while 로 출력하기

// #include <stdio.h>
// #include <stdbool.h>

// int main(void)
// {
//     int i = 0 ;
//     while (true) //나중에 C++ 을 생각하면 (1) 대신 (true)를 쓰는 것이 좋다

//     {   if(i == 10)
//             break;
//         printf("%d 번 출력입니다.\n", i ) ;
       
//         ++i;
//     } 
//     return 0 ;

// }

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i = 0 ;
    while (i != 10)  // (!= 보다 <로 하는게 좋다(임베디드에서 에러날 수도))
                    
    {   
        printf("%d 번 출력입니다.\n", i + 1 ) ;
        ++i;
    } 
    return 0 ;

}