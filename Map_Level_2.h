#ifndef MAP_LEVEL_2_H
#define MAP_LEVEL_2_H
#include<QWidget>
#include<QPainter>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "Level_Map.h"
#include "Steve.h"


class Map_Level_2
{
public:
    Map_Level_2();
    //void DrawMap();
    ~Map_Level_2();
    bool isRoad(int x, int y) const;

    QGraphicsScene* level_2_Scene;
private:
    Level_Map* m_l2_Map;
    QString filePath ;
    vector<vector<int>> map_2;

    Steve m_Steve;
};

#endif // MAP_LEVEL_2_H
