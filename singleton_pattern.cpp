#include <iostream>
#include <string>

using namespace std;

class Singleton {
public:
    static Singleton* New(string name) {
        static Singleton* instance = nullptr;
        if(instance == nullptr) instance = new Singleton(name);
        return instance;
    }
    void print() {
        cout << "my name is " << _name << "\n";
    }

private:
    string _name = "";
    Singleton(){}
    Singleton(string name) : _name(name) {}
};

int main()
{
    Singleton *instance = Singleton::New("kissin");
    Singleton *instance2 = Singleton::New("langlnag");

    instance->print();
    instance2->print();

    return 0;
}