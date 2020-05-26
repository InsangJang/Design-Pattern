#include <iostream>

class Receiver
{
public:
    void action() { std::cout << "Receiver: To do somthing..." << std::endl; }
};

class Command
{
public:
    virtual void execute() = 0;
};

class ConcreteCommand : public Command
{
public:
    void setReceiver(Receiver* r) { pReceiver = r; }
    void execute() override { pReceiver->action(); }

private:
    Receiver* pReceiver;
};

class Invoker
{
public:
    void SetCommand(Command* command)  { pCommand = command; }
    void Execute() { pCommand->execute(); }

private:
    Command* pCommand;
};

int main()
{
    Invoker mInvoker;
    Receiver mReceiver;
    ConcreteCommand mCommand;

    mCommand.setReceiver(&mReceiver);
    mInvoker.SetCommand(&mCommand);
    mInvoker.Execute();

    return 0;
}