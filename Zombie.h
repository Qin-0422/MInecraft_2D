#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <QObject>
#include "Character.h"
#include "Steve.h"
#include <cstdlib>// 用于随机数生成
#include <cmath>// 用于计算距离
#include <QDebug>
#include <QTimer>
#include <QTime>
class Zombie :  public QObject ,public Character ,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Zombie();



    void chase(Steve* target);// 追逐目标函数
    void attack(Steve* target);// 攻击目标函数

    void takeDamage(int damage, Steve* attacker); // 被攻击时的处理函数
    void setHomeAreaX1(int x1)
    {
        m_HomeAreaX1=x1;
    }
    void setHomeAreaX2(int x2)
    {
        m_HomeAreaX2=x2;
    }
    void setHomeAreaY1(int y1)
    {
        m_HomeAreaY1=y1;
    }
    void setHomeAreaY2(int y2)
    {
        m_HomeAreaY1=y2;
    }
private:
    //Zombie活动范围
    int m_HomeAreaX1;
    int m_HomeAreaY1;
    int m_HomeAreaX2;
    int m_HomeAreaY2;

    bool isNear(Steve* target); // 判断目标是否在附近的函数
    void knockBack(Steve* attacker); // 击退效果的处理函数

    Steve* m_TargetSteve;
    QTimer* m_randomMoveTimer; // 定时器用于击退效果
    QTimer* m_KnockBackTimer; // 定时器用于击退效果
    int m_KnockBackSteps; // 击退效果的步数
    int m_KnockBackX; // 击退效果的X方向移动量
    int m_KnockBackY; // 击退效果的Y方向移动量
    int m_KnockBackInitialY; // 初始Y方向移动量
private slots:
    void updateKnockBack(); // 更新击退效果的槽函数
    void randomMove();// 随机移动函数
    void update(Steve* target);// 更新僵尸状态的函数
};

#endif // ZOMBIE_H
