#include "Steve.h"
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
void Steve::SteveMove()
{
    for(int KeyCode :mKeyList)
    {
        switch (KeyCode)
        {
        case Qt::Key_A:this->moveBy(-1*this->m_MoveSpeed,0);
            break;
        case Qt::Key_D:this->moveBy(1*this->m_MoveSpeed,0);
            break;
        case Qt::Key_W:
        {
            break;
        }
        case Qt::Key_S:
        {
            break;
        }
        default:
            break;
        }
    }
}
