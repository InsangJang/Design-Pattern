#include <iostream>

class SortInterface
{
public:
    virtual void sort() = 0;
};

class QuickSort : public SortInterface
{
public:
    void sort() override { std::cout << "quick sort" << std::endl; }
};

class BubbleSort : public SortInterface
{
public:
    void sort() override { std::cout << "bubble sort" << std::endl; }
};

class MergeSort : public SortInterface
{
public:
    void sort() override { std::cout << "merge sort" << std::endl; } 
};

class SortManager
{
public:
    SortManager() : pInterface(0) {}
    ~SortManager(){ if(pInterface) delete pInterface; }

public:
    void sort() { pInterface->sort(); }
    void interfaceSetting(SortInterface* _interface)
    {
        if(pInterface) delete pInterface;
        pInterface = _interface;
    }

private:
    SortInterface* pInterface;
};

int main()
{
    SortManager *pManager = new SortManager();
    pManager->interfaceSetting(new BubbleSort());
    pManager->sort();

    pManager->interfaceSetting(new QuickSort());
    pManager->sort();

    pManager->interfaceSetting(new MergeSort());
    pManager->sort();

    delete pManager;

    return 0;
}