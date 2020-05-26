#include <iostream>

class AbstractClass
{
private:
    virtual void subMethod() = 0;

public:
    void templateMethod() { subMethod(); }
};

class concreteClass : public AbstractClass
{
public:
    void subMethod() override { std::cout << "subMethod" << std::endl; }
};

int main()
{
    AbstractClass *test = new concreteClass;
    test->templateMethod();

    delete test;

    return 0;
}