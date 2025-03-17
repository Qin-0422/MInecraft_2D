#ifndef STEVE_H
#define STEVE_H
#include"Character.h"
#include <QKeyEvent>
#include <QTimer>
class Map_Level_1;
class Steve:  public Character ,public QGraphicsPixmapItem
{


public:
    Steve();

       //按键事件
       void keyPressEvent(QKeyEvent *event);
       void keyReleaseEvent(QKeyEvent *event);
       void SteveMove();

       void setScene(QGraphicsScene *scene);  // 设置场景函数
       void setMap(Map_Level_1 *map);  // 设置地图函数 // 新增函数
       bool canMoveTo(int newX, int newY);
private:
       bool m_isJumping;
       bool m_onGround;
       bool m_movingLeft;
       bool m_movingRight;
       bool m_jumping;

       //按键组合
       QList<int> mKeyList;
       QTimer *m_SteveMoveTimer;
       Map_Level_1 *m_map;  // 添加指向地图的指针 // 新增成员变量
};

#endif // STEVE_H
