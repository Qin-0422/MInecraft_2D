#include "Zombie.h"

Zombie::Zombie(): m_KnockBackTimer(new QTimer(this)), m_KnockBackSteps(0), m_KnockBackX(0), m_KnockBackY(0)
{
    m_randomMoveTimer = new QTimer(this);
    //m_KnockBackTimer = new QTimer(this);
    m_randomMoveTimer->start(500);
    this->setX(700);
    this->setY(1050);
    this->setHomeAreaX1(400);
    this->setHomeAreaX2(750);
    this->setHomeAreaY1(800);
    this->setHomeAreaY2(1150);
    this->setHealth(20);
    this->setAttackPower(5);
    this->setPixmap(QPixmap(":/Steve/img/character/Steve/Steve_front.png"));
    connect(m_randomMoveTimer, &QTimer::timeout,this,&Zombie::randomMove);

    connect(m_KnockBackTimer, &QTimer::timeout, this, &Zombie::updateKnockBack);
}


// 随机移动函数的定义，僵尸在规定区域内随机移动
void Zombie::randomMove()
{
    int newX = m_HomeAreaX1 + std::rand() % (m_HomeAreaX2 - m_HomeAreaX1 + 1);
    qDebug()<<"x="<<newX<<"y="<<this->getY();
    this->setX(newX);
}
void Zombie::chase(Steve* target)
{
    int targetX = target->getX();
    int zx = getX();
    int zy = getY();

    if (targetX > zx)
        zx += 5;
    else if (targetX < zx)
        zx -= 5;

    setPosition(zx, zy);
}
void Zombie::attack(Steve* target)
{
    if (this->QGraphicsPixmapItem::collidesWithItem(target))
    {
        target->setHealth(target->getHealth() - getAttackPower());
        qDebug() << "Zombie attacks " << target->getX() << " for " << getAttackPower() << " damage!";
    }
}
void Zombie::update(Steve* target)
{
    if (this->QGraphicsPixmapItem::collidesWithItem(target))
    {
        attack(target);
    }
    else if (isNear(target))
    {
        chase(target);
    }
    else
    {
        randomMove();
    }
}
bool Zombie::isNear(Steve* target)
{
    double distance = std::sqrt(std::pow(getX() - target->getX(), 2) + std::pow(getY() - target->getY(), 2));
    return distance < 250;
}
void Zombie::takeDamage(int damage, Steve* attacker)
{
    setHealth(getHealth() - damage);
    if (getHealth() <= 0)
    {
        setHealth(0);
        qDebug() << "Zombie is dead!";
    }
    else
    {
        qDebug() << "Zombie takes " << damage << " damage!";
        knockBack(attacker); // 触发击退效果
    }
}
// 击退效果的处理函数
void Zombie::knockBack(Steve* attacker)
{
    int dx = getX() - attacker->getX();
    double distance = std::abs(dx);

    if (distance > 0)
    {
        int knockBackDistance = 50;
        m_KnockBackSteps = 10; // 击退效果分为10步完成
        m_KnockBackX = static_cast<int>((dx / distance) * knockBackDistance / m_KnockBackSteps);
        m_KnockBackInitialY = -20; // 初始Y方向移动量
        m_KnockBackY = m_KnockBackInitialY; // 设置初始的Y方向移动量

        m_KnockBackTimer->start(50); // 50毫秒更新一次
    }
}

// 更新击退效果的槽函数
void Zombie::updateKnockBack()
{
    if (m_KnockBackSteps > 0)
    {
        setPosition(getX() + m_KnockBackX, getY() + m_KnockBackY);
        m_KnockBackSteps--;

        // 使 Y 轴移动形成抛物线效果
        if (m_KnockBackSteps <= 5)
        {
            m_KnockBackY += 4; // 在击退效果的后半段，Y轴移动减小
        }
        else
        {
            m_KnockBackY -= 4; // 在击退效果的前半段，Y轴移动增加
        }
    }
    else
    {
        m_KnockBackTimer->stop();
    }
}
