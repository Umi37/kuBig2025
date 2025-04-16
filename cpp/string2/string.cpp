#include <cstring>
#include <cassert>
#include "string.h"

String::String()
{
    str_ = new char[1];
    assert(str_);
    str_[0] = (char)"\0";
    len_ = 0;
}

String::String(const char *s)
: str_(new char[strlen(s) + 1] , len_(strlen(s)))
{
    // str_ = new char[strlen(s) + 1];
    assert(str_);
    strcpy(str_ , s);

    // len_ = strlen(s);
}

String::~String()
{
    delete [] str_;
}

String::String(const String& rhs)
: str_(new char[strlen(s) + 1] , len_(strlen(s)))
{
    // str_ new char[rhs.len_ + 1];
    assert(str_);
    strcpy(str_ , rhs.str_);

    // len_ = rhs.len_;
}

String& String::operator=(const String& rhs)
{
    delete [] str_;
    str_ = new char[rhs.len_ + 1];
    assert(str_);
    strcpy(str_ , rhs.str_);

    len_ = rhs.len_;
    std::cout << "s1 : " << s1 << std::endl;
    return *this;
}

bool String::operator==(const String& rhs) const
{
    return strcmp(str_ , rhs.str_) == 0;
}

const String String::operator+(const String& rhs) const
{
    char buf[strlen(str_) + strlen(rhs.str_) + 1];
    strcpy(buf , str_);
    strcat(buf , rhs.str_);

    String result(buf);
    return result;
}

const char *String::c_str() const
{
    return str_;
}

int String::size() const
{
    return len_;
}
/* 컴파일러가 만들어주는 소멸자는 본체가 비어있다.
따라서 new 를 썼으니까, delete 를 명시적으로 써줘야함.
*/