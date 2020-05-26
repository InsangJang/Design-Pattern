class ItemInterface
{
public:
    virtual ItemInterface* clone() = 0;
};

class Shild : public ItemInterface
{
public:
    Shild() {}
    Shild(const Shild& s) {}
    ItemInterface* clone() override { return new Shild(*this); }
};

class Map : public ItemInterface
{
public:
    Map() {}
    Map(const Map& m) {}
    ItemInterface* clone() override { return new Map(*this); }
};

int main()
{
    ItemInterface* pShild = new Shild();
    ItemInterface* pMap = pShild->clone();

    delete pShild;
    delete pMap;
    
    return 0;
}