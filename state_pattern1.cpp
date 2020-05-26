#include <iostream>

class State
{
public:
    virtual void handle() = 0;
};

class concreteState1 : public State
{
public:
    void handle() override { std::cout << "concreteState1" << std::endl; }
};

class concreteState2 : public State
{
public:
    void handle() override { std::cout << "concreteState2" << std::endl; }
};

class Context
{
public:
    Context(State* state) : pState(state) {}
    ~Context() { if(pState) delete pState; }

public:
    void setState(State* state) {if(pState) delete pState; pState = state; }
    void request() { pState->handle(); }

private:
    State *pState;
};

int main()
{
    Context *pContext = new Context(new concreteState2());
    pContext->request();

    pContext->setState(new concreteState2());
    pContext->request();

    delete pContext;
    
    return 0;
}