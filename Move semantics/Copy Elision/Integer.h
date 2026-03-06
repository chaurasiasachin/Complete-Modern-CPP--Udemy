#pragma once
class Integer
{
    int *m_pInt;
public:
    // Default Constructor
    Integer();
    // Parameterised Constructor
    Integer(int val);
    // Copy Constructor
    Integer(const Integer &obj);
    // Move Constructor
    Integer(Integer &&obj);
    int GetValue() const;
    void SetValue(int val);
    ~Integer();
};

