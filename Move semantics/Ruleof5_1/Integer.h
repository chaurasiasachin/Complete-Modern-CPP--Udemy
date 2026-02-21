#pragma once
class Integer
{
    int *m_pInt;
public:
    Integer();
    Integer(int val);

    // Copy constructor
    Integer(const Integer &obj);

    // Move constructor
    Integer(Integer &&obj);

    // Copy Assignment
    Integer& operator=(const Integer &obj);

    // Move Assignment
    Integer& operator=(Integer &&obj);
    
    int GetValue() const;
    void SetValue(int val);
    ~Integer();
};

