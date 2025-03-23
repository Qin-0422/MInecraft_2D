#ifndef MAP_LEVEL_1_H
#define MAP_LEVEL_1_H
#include<QWidget>
#include<QPainter>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "Level_Map_Impl.h" // 引入实现类
#include "Steve.h"


class Map_Level_1: public Level_Map_Impl // 继承 Level_Map_Impl
{
public:
    Map_Level_1();
    ~Map_Level_1();

    bool isRoad(int x, int y) const override;
    bool isLadder(int x, int y) const override;
    bool isTransmit (int x, int y) const override;
    bool isTransmitBack (int x, int y) const override;
    QGraphicsScene* getScene() const override { return level_1_Scene; }
    QGraphicsScene* level_1_Scene;
    Steve m_Steve;
private:
    Level_Map_Impl* m_l1_Map;
    QString filePath ;
    vector<vector<int>> map_1;


};

#endif // MAP_LEVEL_1_H
