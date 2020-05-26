#include <iostream>

class Receiver
{
public:
    virtual void execute();
};

class FileCreate : public Receiver
{
public:
    virtual void execute() override { std::cout << "file create" << std::endl; }
};

class FileSave : public Receiver
{
public:
    virtual void execute() override { std::cout << "file save" << std::endl; }
};

class FileClose : public Receiver
{
public:
    virtual void execute() override { std::cout << "file close" << std::endl; }
};

template <typename T>
class Command
{
public:
    Command(T* receiver) : pReceiver(receiver) {}
    ~Command() { if(pReceiver) delete pReceiver; }

public:
    void execute() { pReceiver->execute(); } 

private:
    T* pReceiver;
};

int main()
{
    Command<FileCreate> pCommand1(new FileCreate());
    Command<FileSave>   pCommand2(new FileSave());
    Command<FileClose>  pCommand3(new FileClose());

    pCommand1.execute();
    pCommand2.execute();
    pCommand3.execute();

    return 0;
}
