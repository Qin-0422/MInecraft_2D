#ifndef STEVE_H
#define STEVE_H
#include"Character.h"
#include <QKeyEvent>
#include <QTimer>
#include "Level_Map.h"

class Steve:  public Character ,public QGraphicsPixmapItem
{


public:
    Steve();

       //按键事件
       void keyPressEvent(QKeyEvent *event);
       void keyReleaseEvent(QKeyEvent *event);
       void SteveMove();
       void setScene(QGraphicsScene *scene);  // 设置场景函数
       void setMap(Level_Map *map);  // 设置地图函数 // 新增函数
       bool canMoveTo(int newX, int newY);
       void jump();
       void fall(); // 下落函数
private:
       bool m_isJumping;
       int  current_jumpHeight;
       int jump_can_height;
       //按键组合
       QList<int> mKeyList;
       QTimer *m_SteveMoveTimer;
       QTimer *m_jumpTimer;
       QTimer *m_fallTimer;
       Level_Map *m_map;  // 添加指向地图的指针
};

#endif // STEVE_H
