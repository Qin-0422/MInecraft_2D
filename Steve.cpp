#include "Steve.h"
#include "Map_Level_1.h"
#include <QDebug>
Steve::Steve()
{
    setHealth(20);
    setAttackPower(1);
    setattackDistance_x(50);
    setattackDistance_y(100);
    setPosition(50,1000);
    this->setPixmap(QPixmap(":/Steve/img/character/Steve/Steve_front.png"));
    m_MoveSpeed =5;
    jump_can_height = 100;
    m_isJumping = false;

    m_SteveMoveTimer = new QTimer(this);
    connect(m_SteveMoveTimer, &QTimer::timeout, this, &Steve::SteveMove);
    m_SteveMoveTimer->start(10);  // 每10毫秒触发一次SteveMove

    m_jumpTimer= new QTimer(this);
    connect(m_jumpTimer, &QTimer::timeout, this, &Steve::jump);



    m_fallTimer =new QTimer(this);

    QGraphicsPixmapItem::setFlag(QGraphicsItem::ItemIsFocusable);
    QGraphicsPixmapItem::setFocus();
    m_map = nullptr;  // 初始化地图指针

}

void Steve::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_A:
    case Qt::Key_D:
    case Qt::Key_W:
    case Qt::Key_S:
        mKeyList.append(event->key());
        break;
    case Qt::Key_Space:
            if (!m_isJumping )
            {
                m_isJumping = true;
                current_jumpHeight = 0;
                m_jumpTimer->start(10); // 每10毫秒触发一次jump
            }
            break;
    }
}
void Steve::keyReleaseEvent(QKeyEvent *event)
{
    if(mKeyList.contains(event->key()))
    {
        mKeyList.removeOne(event->key());
    }
}
bool Steve::canMoveTo(int newX, int newY)
{
    // 检查目标位置的包围盒是否都在 Road 上
    int width = pixmap().width();
    int height = pixmap().height();
    for (int x = newX; x < newX + width; ++x) {
        for (int y = newY; y < newY + height; ++y) {
            if (!m_map->isRoad(x, y)) {
                return false;
            }
        }
    }
    return true;
}

void Steve::jump()//跳跃函数
{
    if (current_jumpHeight < jump_can_height)
    {
        m_isJumping = true;
        int newY = static_cast<int>(QGraphicsItem::y()) - m_MoveSpeed;
        if (canMoveTo(static_cast<int>(QGraphicsItem::x()), newY))
        {
            moveBy(0, -m_MoveSpeed);
            current_jumpHeight += m_MoveSpeed;
        }
        else//处理头顶碰方块
        {
            m_jumpTimer->stop();
        }
    }
    else
    {
        m_jumpTimer->stop();
    }

        if(m_isJumping&&!m_jumpTimer->isActive())
        {
            m_fallTimer->start(20);
            connect(m_fallTimer,&QTimer::timeout,this,&Steve::fall);
        }


}

void Steve::fall()//下落函数
{
    int newY = static_cast<int>(QGraphicsItem::y()) + m_MoveSpeed;
    if (canMoveTo(static_cast<int>(QGraphicsItem::x()), newY))
    {
        moveBy(0, m_MoveSpeed);
    }
    else
    {
        m_isJumping = false;
        m_fallTimer->stop();
        m_jumpTimer->start(20);
    }

}

void Steve::SteveMove()
{
    if (!m_map) return;  // 如果地图未设置，则不进行移动
    for(int KeyCode :mKeyList)
    {
        int deltaX = 0;

        switch (KeyCode)
        {
               case Qt::Key_A: deltaX = -m_MoveSpeed; break;
               case Qt::Key_D: deltaX = m_MoveSpeed; break;



        }
        int newX = static_cast<int>(QGraphicsItem::x())  + deltaX;

        if (canMoveTo(newX, static_cast<int>(QGraphicsItem::y())) ) // 使用 canMoveTo 函数进行碰撞检测
        {
                moveBy(deltaX, 0);

        }

    }
}

void Steve::setMap(Map_Level_1 *map)
{
    m_map = map;
}
