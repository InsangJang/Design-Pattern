class Singleton
{
private:
    Singleton(){}
    ~Singleton(){}
    Singleton(const Singleton& s){}

public:
    static Singleton* GetInstance()
    {
        if(m_pInstance == nullptr)
        {
            m_pInstance = new Singleton;
        }

        return m_pInstance;
    }

    // explicit delete
    void destroy()
    {
        if(m_pInstance != nullptr)
        {
            delete m_pInstance;
            m_pInstance = nullptr;
        }
    }

private:
    static Singleton* m_pInstance;

};

Singleton* Singleton::m_pInstance = nullptr;

int main()
{
    Singleton* pSingleton = Singleton::GetInstance();

    // explicit delete
    pSingleton->destroy();


    return 0;
}