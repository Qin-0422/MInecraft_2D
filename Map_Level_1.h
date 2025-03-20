#ifndef MAP_LEVEL_1_H
#define MAP_LEVEL_1_H
#include<QWidget>
#include<QPainter>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "Level_Map.h"
#include "Steve.h"


class Map_Level_1
{
public:
    Map_Level_1();
    //void DrawMap();
    ~Map_Level_1();

    void jump();
     bool isRoad(int x, int y) const;
    QGraphicsScene* level_1_Scene;
private:
    Level_Map* m_l1_Map;
    QString filePath ;
    vector<vector<int>> map_1;

    Steve m_Steve;
};

#endif // MAP_LEVEL_1_H
