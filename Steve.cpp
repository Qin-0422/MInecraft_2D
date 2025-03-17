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




    m_SteveMoveTimer = new QTimer(this);
       connect(m_SteveMoveTimer, &QTimer::timeout, this, &Steve::SteveMove);
       m_SteveMoveTimer->start(10);  // 每10毫秒触发一次SteveMove
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
void Steve::SteveMove()
{
    if (!m_map) return;  // 如果地图未设置，则不进行移动
    for(int KeyCode :mKeyList)
    {
        int deltaX = 0;
        int deltaY = 0;
        switch (KeyCode)
        {
               case Qt::Key_A: deltaX = -m_MoveSpeed; break;
               case Qt::Key_D: deltaX = m_MoveSpeed; break;
               case Qt::Key_W:  break;
               case Qt::Key_S:  break;
               default: break;
        }
        int newX = QGraphicsItem::x() + deltaX;
        int newY = QGraphicsItem::y() + deltaY;

        if (canMoveTo(newX, newY))  // 使用 canMoveTo 函数进行碰撞检测
        {
            moveBy(deltaX, deltaY);
        }
    }
}
void Steve::setMap(Map_Level_1 *map)
{
    m_map = map;
}
