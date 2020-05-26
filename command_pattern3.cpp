#include <iostream>

class Receiver
{
public:
    virtual void execute() = 0;
};

class FileCreate : public Receiver
{
public:
    virtual void execute() override { std::cout << "file create" << std::endl; }
};

class FileSave : public Receiver
{
    virtual void execute() override { std::cout << "file save" << std::endl; }
};

class FileClose : public Receiver
{
public:
    virtual void execute() override { std::cout << "file close" << std::endl; }
};

class Command
{
public:
    virtual void execute() = 0;
};

class FileCreateCommand : public Command
{
public:
    void receiverSetting(Receiver* r) { pReceiver = r; }
    void execute() { pReceiver->execute(); }

private:
    Receiver* pReceiver;
};

class FileSaveCommand : public Command
{
public:
    void receiverSetting(Receiver* r) { pReceiver = r; }
    void execute() { pReceiver->execute(); }
private:
    Receiver* pReceiver;
};

class FileCloseCommand : public Command
{
public:
    void receiverSetting(Receiver* r) { pReceiver = r; }
    void execute() { pReceiver->execute(); }

private:
    Receiver* pReceiver;
};

class Invoker
{
public:
    void commandSetting(Command* pCmd) { pCommand = pCmd; }
    void commandExecution() { pCommand->execute(); }

private:
    Command* pCommand;
};

int main()
{
    Invoker pInvoker;
    FileCreate pFileNew;
    FileCreateCommand pCommand;

    pCommand.receiverSetting(&pFileNew);
    pInvoker.commandSetting(&pCommand);
    pInvoker.commandExecution();

    return 0;
}