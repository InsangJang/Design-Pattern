#include <cstdlib>
#include <iostream>

template<typename T>
class Singleton
{
protected:
    Singleton(){}
    virtual ~Singleton(){}
    Singleton(const SIngleton& s){}

private:
    statice void destroy()
    {
        if(m_pInstance != nullptr)
            delete m_pInstancel
    }

public:
    static T* GetInstance()
    {
        if(m_pInstance == nullptr)
        {
            m_pInstance = new T();
            atexit(destroy);
        }

        return m_pInstance;
    }

private:
    static T* m_pInstance;
};

template <typename T>
T* Singleton <T>::m_pInstance;