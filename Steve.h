#ifndef STEVE_H
#define STEVE_H
#include"Character.h"
#include <QKeyEvent>
#include <QTimer>
class Steve:  public Character ,public QGraphicsPixmapItem
{


public:
    Steve();

       //按键事件
       void keyPressEvent(QKeyEvent *event);
       void keyReleaseEvent(QKeyEvent *event);
       void SteveMove();

       void setScene(QGraphicsScene *scene);  // 添加设置场景函数
private:
       bool m_isJumping;
       bool m_onGround;
       bool m_movingLeft;
       bool m_movingRight;
       bool m_jumping;

       //按键组合
       QList<int> mKeyList;
    QTimer *m_SteveMoveTimer;

};

#endif // STEVE_H
