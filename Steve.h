#ifndef STEVE_H
#define STEVE_H
#include"Character.h"
#include <QKeyEvent>
#include <QTimer>
#include "Level_Map.h"
#include <QObject>
class Steve:  public QObject ,public Character ,public QGraphicsPixmapItem
{
Q_OBJECT

public:
    Steve();

       //按键事件
       void keyPressEvent(QKeyEvent *event);
       void keyReleaseEvent(QKeyEvent *event);
       void SteveMove();
       void setScene(QGraphicsScene *scene);  // 设置场景函数
       void setMap(Level_Map *map);  // 设置地图函数 // 新增函数
       bool canMoveTo(int newX, int newY);
       bool canFallTo(int newX, int newY);//判断是否挂在梯子上，从而取消重力作用
       void jump();
       void fall(); // 下落函数
       void climbLadder();
       void checkPosition(); // 添加检测位置的函数
signals:
       void positionChanged(); // 添加位置改变的信号
       void changeLevel(); // 添加切换下一关卡的信号
       void changeBackLevel();//添加切换到上一关卡的信号
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
