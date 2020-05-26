class Bullet {
public:
    int getX() const { return x_; }
    int getY() const { return y_; }
    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y; }

private:
    int x_;
    int y_;
};

class BulletManager {
public:
    Bullet* create(Bullet& bullet) {
        Bullet& bullet = new Bullet();
        bullet->setX(x);
        bullet->setY(y);

        return bullet;
    }

    bool isOnScreen(Bullet& bullet) {
        return bullet.getX() >= 0 &&
            bullet.getY() >= 0 &&
            bullet.getX() < SCREEN_WIDTH &&
            bullet.getY() < SCREEN_HEIGHT;
    }

    void move(Bullet& bullet) {
        bullet.setX(bullet getX() + 5);
    }
};