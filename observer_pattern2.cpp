#include <iostream>
#include <vector>
#include <algorithm>

class CSubject
{
public:
    CSubject();
    virtual ~CSubject();

    virtual void registerObserver(CObserver *observer) = 0;
    virtual void removeObserver(CObserver *observer) = 0;
    virtual void notifyObserver() = 0;
};

class CWeatherData : public CSubject
{
public:
    CWeatherData();
    ~CWeatherData();

    void setMeasureChanged(float humidity, int pressure, float temperature)
    {
        mHumidity = humidity;
        mPressure = pressure;
        mTemperature = temperature;
        measurementChanged();
    }

    void registerObserver(CObserver *observer)
    {
        mObserver.push_back(observer);
    }

    void measurementChanged()
    {
        notifyObserver();
    }

    void removeObserver(CObserver *observer)
    {
        std::vector<CObserver*>::iterator iter;
        iter = find(mObserver.begin(), mObserver.end(), observer);
        if(iter != mObserver.end())
        {
            mObserver.erase(iter);
        }
    }

private:
    float mHumidity;
    int mPressure;
    float mTemperature;
    std::vector<CObserver*> mObserver;
    void notifyObserver()
    {
        std::vector<CObserver*>::iterator iter = mObserver.begin();
        for(;iter != mObserver.end(); iter++)
        {
            CObserver *observer = *iter;
            observer->update(mTemperature, mHumidity, mPressure);
        }
    }
};

class CObserver
{
public:
    CObserver();
    ~CObserver();
    virtual void update(float temperature, float humidity, int pressure) = 0;
};

class CCurrentCondition : public CObserver
{
public:
    CCurrentCondition(CSubject *weatherData)
    {
        mWeatherData = weatherData;
        mWeatherData->registerObserver(this);
    }

    ~CCurrentCondition() {}

public:
    void update(float temperature, float humidity, int pressure) override
    {
        mTemperature = temperature;
        mHumidity = humidity;
        mPressure = pressure;
        display();
    }

    void display()
    {
        std::cout << "current pressure : " << mPressure << std::endl;
        std::cout << "current temperature : " << mTemperature << std::endl;
        std::cout << "current humidity : " << mHumidity << std::endl;
    }

private:
    float mHumidity;
    int mPressure;
    float mTemperature;
    CSubject *mWeatherData;
};

int main()
{
    CWeatherData *weather = new CWeatherData();
    CCurrentCondition *condition = new CCurrentCondition(weather);
    CCurrentCondition *condition2 = new CCurrentCondition(weather);

    weather->setMeasureChanged(7.0f, 2, 15.0f);
    std::cout << "delete Observer" << std::endl;

    weather->removeObserver(condition2);
    weather->setMeasureChanged(5.0f, 1, 13.0f);

    return 0;
}