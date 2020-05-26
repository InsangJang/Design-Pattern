#include <cstdlib>

class Singleton
{
private:
    Singleton(){}
    ~Singleton(){}
    Singleton(const Singleton& s){}

private:
    static void destroy()
    {
        if(m_pInstance != nullptr)
            delete m_pInstance;
    } // delete

public:
    static Singleton* GetInstance()
    {
        if(m_pInstance == nullptr)
        {
            m_pInstance = new Singleton();
            atexit(destroy);
        }

        return m_pInstance;
    }

private:
    static Singleton* m_pInstance;
};

Singleton* Singleton::m_pInstance = nullptr;

int main()
{
    Singleton* pSIngleton = Singleton::GetInstance();

    return 0;
}