#include <iostream>
#include <list>
#include <typeinfo>

class Colleague;
class Mediator
{
public:
    virtual void addColleague(Colleague* colleague) = 0;
    virtual void mediate(const char* message, Colleague* sender) = 0;
};

class Colleague
{
public:
    Colleague(Mediator* m) : pMediator(m) { pMediator->addColleague(this); }

public:
    void sendMessages(const char* str)
    {
        pMediator->mediate(str, this);
        std::cout << "message: " << str << ", sent by: " << getName() << std::endl;
    }

    void receiveMessages(const char* str)
    {
        std::cout << "message: " << str << ", recv by: " << getName() << std::endl;
    }

    virtual const char* getName() = 0;

protected:
    Mediator* pMediator;
};

class ConcreteColleague1 : public Colleague
{
public:
    ConcreteColleague1(Mediator* m) : Colleague(m) {}
    const char* getName() { return typeid(this).name(); }
};

class ConcreteColleague2 : public Colleague
{
public:
    ConcreteColleague2(Mediator* m) : Colleague(m) {}
    const char* getName() { return typeid(this).name(); }
};

class ConcreteMediator : public Mediator
{
public:
    void addColleague(Colleague* colleague)
    {
        mList.push_back(colleague);
    }

    void mediate(const char* message, Colleague* sender)
    {
        for(Colleague* object : mList)
        {
            if(object != sender)
                object->receiveMessages(message);
        }
    }

private:
    std::list<Colleague*> mList;
};

int main()
{
    ConcreteMediator mConcreteMediator;
    ConcreteColleague1 mConcreteColleague1(&mConcreteMediator);
    ConcreteColleague2 mConcreteColleague2(&mConcreteMediator);

    mConcreteColleague1.sendMessages("First Message...");
    mConcreteColleague2.sendMessages("Second Message...");

    return 0;
}