#ifndef MAP_LEVEL_2_H
#define MAP_LEVEL_2_H
#include<QWidget>
#include<QPainter>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "Level_Map_Impl.h" // 引入实现类
#include "Steve.h"//引入人物类
#include "Zombie.h"//引入僵尸类

class Map_Level_2: public Level_Map_Impl // 继承 Level_Map_Impl
{
public:
    Map_Level_2();
    ~Map_Level_2();

    bool isRoad(int x, int y) const override;
    bool isLadder(int x, int y) const override;
    bool isTransmit (int x, int y) const override;
    bool isTransmitBack (int x, int y) const override;
    QGraphicsScene* getScene() const override { return level_2_Scene; }
    QGraphicsScene* level_2_Scene;
    Steve m_Steve;
private:
    Level_Map_Impl* m_l2_Map; // 使用实现类
    QString filePath ;
    vector<vector<int>> map_2;
    Zombie m_Zombie;

};

#endif // MAP_LEVEL_2_H
