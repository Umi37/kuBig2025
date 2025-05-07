#include <cstdio>
#include "stack.h"
#include <iostream>

int main() // 괄호안에 void 를 뺌 (C언어에서는 입력값이 어떤 것이 들어올지 모른다는 뜻이라 void를 씀)
// C++ 에서는 void 를 써도 되고, 안써도 됨 (C언어와의 호환성 때문에 쓰는 경우 있음)
{
    Stack s1(10), s2(100); // 지역변수
    //s1.initStack(10);
    //s2.initStack(100);

    s1.push(100);
    s1.push(200);
    s1.push(300);

    // s1.tos = 0;

    // printf("s1 1st pop() : %d\n", s1.pop());
    std::cout << "s1 1st pop() : " << s1.pop() << std::endl; // 이 식의 결과값 : cout , 사이드이팩트로 화면에 출력
    std::cout << "s1 2nd pop() : " << s1.pop() << std::endl;
    std::cout << "s1 3rd pop() : " << s1.pop() << std::endl;

    s2.push(900);
    s2.push(800);
    s2.push(700);
    std::cout << "s2 1st pop() : " << s2.pop() << std::endl; // 이 식의 결과값 : cout , 사이드이팩트로 화면에 출력
    std::cout << "s2 2nd pop() : " << s2.pop() << std::endl;
    std::cout << "s2 3rd pop() : " << s2.pop() << std::endl;

    // s1.cleanupStack();
    // s2.cleanupStack();
    return 0; // 지역변수는 함수가 끝날 때 사라진다 -> 객체가 사라질 때 자동적으로 호출되는 멤버 함수가 바로 소멸자이다.
}

