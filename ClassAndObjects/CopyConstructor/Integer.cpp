#include "Integer.h"

Integer::Integer()
{
    m_pInt = new int(0);
}

Integer::Integer(int val)
{
    m_pInt = new int(val);
}

Integer::Integer(const Integer &obj)
{
    int val = (*obj.m_pInt);
    m_pInt = new int(val);
}

int Integer::GetValue()
{
    return *m_pInt;
}

void Integer::SetValue(int val)
{
    *m_pInt = val;
}

Integer::~Integer()
{
    delete m_pInt;
}
