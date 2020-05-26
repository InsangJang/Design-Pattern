#include <iostream>

class Observer
{
public:
    virtual void update() = 0;
};

class ConcreteObserver : public Observer
{
public:
    void update() override { std::cout << this << " : update" << std::endl; }
};

class Subject
{
public:
    void attach(Observer* o) { mList.addTail(o); }
    void detach(Observer* o) { mList.removeAt(mList.find(o)); }

protected:
    void notify()
    {
        
    }
}