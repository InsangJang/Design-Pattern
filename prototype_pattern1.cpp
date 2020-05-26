#include <iostream>

class Prototype
{
public:
    virtual Prototype* clone() = 0;
};

class concretePrototype1 : public Prototype
{
public:
    concretePrototype1() {}
    concretePrototype1(const concretePrototype1& p) {}

public:
    Prototype* clone() override final
    {
        return new concretePrototype1(*this);
    }
};

