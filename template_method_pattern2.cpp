#include <iostream>

class Beverage
{
private:
    virtual void make() = 0;
    virtual void add() = 0;

    void boil() { std::cout << "boil water" << std::endl; }
    void cup() { std::cout << "cup" << std::endl; }

public:
    void process()
    {
        boil();
        add();
        make();
        cup();
    }
};

class Coffee : public Beverage
{
private:
    void make() override { std::cout << "make coffee" << std::endl; }
    void add() override { std::cout << "add suger and frima" << std::endl; }
};

class RedTea : public Beverage
{
private:
    void make() override { std::cout << "make reftea" << std::endl; }
    void add() override { std::cout << "add  remon" << std::endl; }
};

int main()
{
    Beverage *coffee = new Coffee;
    Beverage *redtea = new RedTea;

    coffee->process();
    redtea->process();

    delete coffee;
    delete redtea;

    return 0;
}

