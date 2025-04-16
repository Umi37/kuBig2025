#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "string.h"

class Employee{
private:
    int id;
    String name;
    Employee *pManager;

    // is not used.
    Employee(const Employee& rhs);
    Employee& operator=(const Employee& rhs);

public:
    Employee(int id, String name, Employee *pManager);
    // Employee() {} is not generated! 명시적인 생성사 있으므로 안만들어짐
    
    // Employee(const Employee& rhs) { /*memberwise copy*/} is not generated!
    // ~Employee() []
    // Employee& operator = employees(const Employee& rhs) { /* memberwise copy*/ return *this;} is not generated!
    
    // Employee* operator&() { return this;}
    // const Employee* operator&() const { return this;}

    int getId();
    String getName();
    Employee *getManager();

    bool isManager(); // 이사람이 관리자인지 사장인지



    // set 함수는 있으면 안된다

};

#endif