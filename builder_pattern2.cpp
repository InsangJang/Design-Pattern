#include <iostream>
#include <string>

class CEngine
{
public:
    CEngine(int mph) : mMPH(mph) {}
    int getMPH() const { return mMPH; }

private:
    int mMPH;
};

class CWheel
{
public:
    CWheel(int size) : mSize(size) {}
    int getSize() const { return mSize; }

private:
    int mSize;
};

class CBody
{
public:
    CBody(std::string shape) : mShape(shape) {}
    std::string getShape() const { return mShape; }

private:
    std::string mShape;
};

class Car
{
public:
    Car() : mEngine(nullptr), mWheel(nullptr), mBody(nullptr) {}
    ~Car() { if(mEngine) delete mEngine; if(mWheel) delete mWheel; if(mBody) delete mBody; }

public:
    void setEngine(CEngine* engine) { mEngine = engine; }
    void setWheel(CWheel* wheel) { mWheel = wheel; }
    void setBody(CBody* body) { mBody = body; }
    void setManufacturer(std::string m) { mManufacturer = m; }

    void print() const
    {
        std::cout << "product company : " << mManufacturer = std::endl;
        std::cout << "horse power : " << mEngine->getMPH() << std::endl;
        std::cout << "wheel size : " << mWheel->getSize() << std::endl;
        std::cout << "body type : " << mBody->getShape() << std::endl;
    }

private:
    CEngine* mEngine;
    CWheel* mWheel;
    CBody* mBody;
    std::string mManufacturer;
};

class Builder
{
public:
    virtual CEngine* getEngine() = 0;
    virtual CWheel* getWheel() = 0;
    virtual CBody* getBody() = 0;
    virtual std::string getManufacturer() = 0;
};

class JeepBuilder : public Builder
{
public:
    CEngine* getEngine() override { return new CEngine(120); }
    CWheel* getWheel() override { return new CWheel(20); }
    CBody* getBody() override { return new CBody("SUV"); }
    std::string getManufacturer() override { return "Jeep"; }
};

class FordBuilder : public Builder
{
public:
    CEngine* getEngine() override { return new CEngine(150); }
    CWheel* getWheel() override { return new CWheel(18); }
    CBody* getBody() override { return new CBody("hatch bag"); }
    std::string getManufacturer() override { return "Ford"; }
};

class Director
{
public:
    Director(Builder* builder) : pBuilder(builder) {}
    ~Director() { if(pBuilder) delete pBuilder; }

public:
    Car* construct()
    {
        Car* pCar = new Car;

        pCar->setBody(pBuilder->getBody());
        pCar->setEngine(pBuilder->getEngine());
        pCar->setWheel(pBuilder->getWheel());
        pCar->setManufacturer(pBuilder->getManufacturer());

        return pCar;
    }

private:
    Builder* pBuilder;
};

int main()
{
    Director* pDirector = new Director(new FordBuilder());
    Car* pCar = pDirector->construct();

    pCar->print();

    delete pCar;
    delete pDirector;

    return 0;
}