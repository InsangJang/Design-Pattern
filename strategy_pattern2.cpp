#include <iostream>

class Strategy
{
public:
    virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
    void AlgorithmInterface() override { std::cout << "Processed by Strategy A" << std::endl; }
};

class ConcreteStrategyB : public Strategy
{
public:
    void AlgorithmInterface() override { std::cout << "Processed by Strategy B" << std::endl; }
};

class ConcreteStrategyC : public Strategy
{
public:
    void AlgorithmInterface() override { std::cout << "Processed by Strategy C" << std::endl; }
};

class Context
{
public:
    Context() : m_pStrategy(0) {}
    ~Context() { if(m_pStrategy) delete m_pStrategy; }

public:
    void ChangeStrategy(Strategy* pStrategy)
    {
        if(m_pStrategy) delete m_pStrategy;
        m_pStrategy = pStrategy;
    }
    void ContextInterface() { m_pStrategy -> AlgorithmInterface(); }

private:
    Strategy* m_pStrategy;
};

int main()
{
    Context* pContext = new Context();

    pContext->ChangeStrategy(new ConcreteStrategyA());
    pContext->ContextInterface();

    pContext->ChangeStrategy(new ConcreteStrategyB());
    pContext->ContextInterface();

    pContext->ChangeStrategy(new ConcreteStrategyC());
    pContext->ContextInterface();

    delete pContext;

    return 0;
}