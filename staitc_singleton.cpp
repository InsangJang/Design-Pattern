class Singleton
{
private:
    Singleton(){}
    ~Singleton(){}
    Singleton(const Singleton& s){}

public:
    static Singleton* GetInstance()
    {
        return &m_pInstance;
    }

private:
    static Singleton m_pInstance;
};

int main()
{
    Singleton* pSingleton = Singleton::GetInstance();

    return 0;
}