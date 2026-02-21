#include "Integer.h"
#include <iostream>
Integer::Integer()
{
    std::cout<<"Integer()"<<std::endl;
    m_pInt = new int(0);
}

Integer::Integer(int value)
{
    std::cout<<"Integer(int )"<<std::endl;
    m_pInt = new int(value);
}

Integer::Integer(const Integer &obj)
{
    // int val = (*obj.m_pInt);
    // m_pInt = new int(val);
    // or
    std::cout<<"Integer(const Integer &)"<<std::endl;
    m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer &&obj)
{
    // In this move contructor we are going to steal the obj using shallow copy
    std::cout<<"Integer(Integer &&)"<<std::endl;
    m_pInt = obj.m_pInt; // Shallow copy
    obj.m_pInt = nullptr; // nullify the source pointer to avoid double deletion
                        // this way when the other object will be destroyed, its destructor will not crash.
                        // The call to delete in destructor will be ignored because that will be delete on a nullptr. 
}

Integer & Integer::operator=(const Integer & obj)
{
    std::cout<<"operator=(const Integer &obj)"<<std::endl;
    if(this == &obj) // self assignment check
        return *this;
    delete m_pInt; // free the existing resource

    // just like copy constuctor, we need to allocate new resource and copy the value
    m_pInt = new int(*obj.m_pInt); // allocate new resource and copy the value
    return *this; // return current object reference
}

Integer & Integer::operator=(Integer && obj)
{
    std::cout<<"operator=(Integer && obj)"<<std::endl;
    if(this == &obj) // self assignment check
        return *this;
    delete m_pInt; // free the existing resource

    // just like move constructor, we can steal the resource using shallow copy and nullify the source pointer
    m_pInt = obj.m_pInt; // Shallow copy of the resource
    obj.m_pInt = nullptr; // nullify the source pointer to avoid double deletion
    return *this; // return current object reference
}

int Integer::GetValue() const
{
    return *m_pInt;
}

void Integer::SetValue(int value)
{
    *m_pInt = value;
}

Integer::~Integer()
{
    std::cout<<"~Integer()"<<std::endl;
    delete m_pInt;
}
