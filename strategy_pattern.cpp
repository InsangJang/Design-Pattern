#include <iostream>

using namespace std;

class Strategy {
public:
    Strategy() {}
    ~Strategy() {}
    virtual void execute() = 0;
};

class A_strategy : public Strategy {
protected:
    virtual void execute() {
        printf("A strategy!\n");
        cout << "A strategy!" << endl;
    }
};

class B_strategy : public Strategy {
protected:
    virtual void execute() {
        printf("B strategy!\n");
    }
};

class Character {
public:
    Character() {}
    ~Character() {}

    void ChangeStrategy(Strategy *s) {
        if(this->stg != nullptr) {
            delete this->stg;
        }
        this->stg = s;
    }

    void Perform() {
        if(this->stg == nullptr) {
            printf("no strategy!\n");
            return;
        }
        this->stg->execute();
    }

private:
    Strategy *stg;
};

int main()
{
    Character *ch = new Character();
    ch->Perform();

    ch->ChangeStrategy(new A_strategy());
    ch->Perform();

    ch->ChangeStrategy(new B_strategy());
    ch->Perform();

    return 0;
}