#pragma once
class Integer
{
    int *m_pInt;
public:
    Integer();
    Integer(int val);
    Integer(const Integer &obj);
    Integer(Integer &&obj);
    int GetValue() const;
    void SetValue(int val);
    ~Integer();
};

