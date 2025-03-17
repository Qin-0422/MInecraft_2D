#ifndef MAP_LEVEL_1_H
#define MAP_LEVEL_1_H
#include<QWidget>
#include<QPainter>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "Level_Map.h"
#include "Steve.h"
enum Map_1_Element
{
    bedrock,//基岩
    Road,
    soil,
    grass,
    Cobblestone,//原石
};

class Map_Level_1
{
public:
    Map_Level_1();
    //void DrawMap();
    ~Map_Level_1();
    QGraphicsScene* level_1_Scene;
private:
    Level_Map* m_l1_Map;
    QString filePath ;    
    vector<vector<int>> map_1;

    Steve m_Steve;
};

#endif // MAP_LEVEL_1_H
