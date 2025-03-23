#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsScene>
#include <QGraphicsItem>
class Character
{

public:
    Character();
    Character( int health, int attackPower, int attackDistance_x,int attackDistance_y, int x, int y);

        int getHealth() const;
        int getAttackPower() const;
        int getattackDistance_x() const;
        int getattackDistance_y() const;
        int getX() const;
        int getY() const;

        // 设置人物属性
        void setHealth(int health);
        void setAttackPower(int attackPower);
        void setattackDistance_x(int attackDistance_x);
         void setattackDistance_y(int attackDistance_y);
        void setPosition(int x, int y);

        int m_MoveSpeed;

private:
    int m_Health;
    int m_AttackPower;
    int m_AttackDistance_x;
    int m_AttackDistance_y;
    int m_x;
    int m_y;
    bool isAlive() const;// 检查角色是否存活


signals:

public slots:
};

#endif // CHARACTER_H
