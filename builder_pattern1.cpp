class Product
{

};

class Builder
{
public:
    virtual Product* getResult() = 0;
    virtual void buildPart() = 0;
};

class concreteBuilder : public Builder
{
public:
    void buildPart() override { pProduct = new Product; }
    Product* getResult() { return pProduct; }

private:
    Product* pProduct;
};

class Director
{
public:
    Director(Builder* builder) : pBuilder(builder) {}
    ~Director() { if(pBuilder) delete pBuilder; }

public:
    Product* construct()
    {
        pBuilder->buildPart();
        return pBuilder->getResult();
    }

private:
    Builder* pBuilder;
};

int main()
{
    Director* pDirector = new Director(new concreteBuilder());
    Product* pProduct = pDirector->construct();

    delete pProduct;
    delete pDirector;

    return 0;
}