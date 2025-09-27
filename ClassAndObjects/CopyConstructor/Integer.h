#pragma once
class Integer
{
    int *m_pInt;
public:
    Integer();
    Integer(int val);
    Integer(const Integer &obj);
    int GetValue();
    void SetValue(int val);
    ~Integer();
};

