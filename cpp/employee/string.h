#ifndef STRING_H
#define STRING_H
#include <iostream>

class String 
{friend std::ostream& operator<<(std::ostream& out, const String& str);
private:
    char *str;
    int len;
public:
    String();
    String(const char*s); //문자열 상수를 받도록 함.
    String(const String& rhs); //복사 생성자
    ~String();

    String& operator=(const String& rhs);

    bool operator==(const String& rhs);
   
    const String operator+(const String& rhs);
//get 함수 2개
    const char *c_str();
    int size();
//set 함수는 만들지 X(왜냐 멤버변수 하나가 바뀌면 다른 멤버 두 개가 한 꺼번에 바뀌는 속성의 녀석들이라 각각을 바꿔줄 수가 없음)
};

#endif