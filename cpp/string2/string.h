#ifndef STRING_H
#define STRING_H
#include <iostream>

class String{
friend std::ostream& operator<<(std::ostream& out , String& rhs);
private:
    char *str_;
    int len_;

public:
    String();
    String(const char *s); // String() { } ==> 디폴트 생성자는 만들어지지 않는다.
    String(const String& rhs); // String(const String& ) { /* memberwise copy */}
    ~String(); // ~String() { }
    
    String& operator=(const String& rhs); // String& operator=(const String& ) { /* memberwise copy */ return *this; }
    
    bool operator==(const String& rhs) const;

    const String operator+(const String& rhs) const;

    const char *c_str() const;
    int size() const;

    // String *operator&() { return this; }
    // const String *operator&() const { return this; }

};

#endif