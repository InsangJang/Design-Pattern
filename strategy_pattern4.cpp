#include <iostream>

class ShootingInterface
{
public:
    virtual void shoot() = 0;
};

class ShootingScore2 : public ShootingInterface
{
public:
    void shoot() override { std::cout << "score 2" << std::endl; }
};

class ShootingScore3 : public ShootingInterface
{
public:
    void shoot() override { std::cout << "score 3" << std::endl; }
};

class ShootingDunk : public ShootingInterface
{
public:
    void shoot() override { std::cout << "score dung" << std::endl; }
};

class ShootingManager
{
public:
    ShootingManager() : m_pInterface(nullptr) {}
    ~ShootingManager() { if(m_pInterface) delete m_pInterface; }

public:
    void ShootSetting(ShootingInterface* pInterface)
    {
        if(m_pInterface) delete m_pInterface;
        m_pInterface = pInterface;
    }

    void shoot() { m_pInterface->shoot(); }

private:
    ShootingInterface* m_pInterface;
};

int main()
{
    ShootingManager* nPlayer = new ShootingManager();
    nPlayer->ShootSetting(new ShootingScore2());
    nPlayer->shoot();

    nPlayer->ShootSetting(new ShootingScore3());
    nPlayer->shoot();

    nPlayer->ShootSetting(new ShootingDunk());
    nPlayer->shoot();
    delete nPlayer;
    return 0;
}