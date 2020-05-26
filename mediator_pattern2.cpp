#include <iostream>
#include <list>
#include <string>

class Colleague;
class Mediator
{
public:
    virtual void appendUser(Colleague* colleague) = 0;
    virtual void removeUser(Colleague* colleague) = 0;
    virtual void sendMessage(const char* message, Colleague* sender) = 0;
};

class Colleague
{
public:
    Colleague(Mediator* m, const char* name) : pMediator(m), mName(name) {}

public:
    virtual void sendMessages(const char* str) = 0;
    virtual void receiveMessages(const char* str) = 0;

protected:
    Mediator* pMediator;
    std::string mName;
};

class User : public Colleague
{
public:
    User(Mediator* m, const char* name) : Colleague(m, name) {}

public:
    void sendMessages(const char* str) override
    {
        std::cout << mName << " send : " << str << std::endl;
        pMediator->sendMessage(str, this);
    }

    void receiveMessages(const char* str) override
    {
        std::cout << mName << " recv : " << str << std::endl;
    }
};

class ChatMediator : public Mediator
{
public:
    void appendUser(Colleague* colleague) override
    {
        mList.push_back(colleague);
    }

    void removeUser(Colleague* colleague) override
    {
        mList.remove(colleague);
    }

    void sendMessage(const char* message, Colleague* sender)
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
    ChatMediator mChatMediator;

    User mUser1(&mChatMediator, "hong");
    User mUser2(&mChatMediator, "na");
    User mUser3(&mChatMediator, "di");

    mChatMediator.appendUser(&mUser1);
    mChatMediator.appendUser(&mUser2);
    mChatMediator.appendUser(&mUser3);

    mUser1.sendMessages("hi, hello");

    return 0;
}