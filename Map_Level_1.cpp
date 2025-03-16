#include "Map_Level_1.h"

Map_Level_1::Map_Level_1()
{
    //初始化地图元素
    m_l1_Map = new Level_Map;
    level_1_Scene = new QGraphicsScene;
    filePath = "../Map/level_1.txt";
    map_1 = m_l1_Map->InitByFile(filePath);

}

void Map_Level_1::DrawMap()
{
    int tileSize = 50;
    for(int row = 0;row<map_1.size();++row)
    {
        for(int col = 0;col<map_1[row].size();++col)
        {
            QGraphicsRectItem *tile = new QGraphicsRectItem(col * tileSize, row * tileSize, tileSize, tileSize);
            switch (map_1[row][col])
            {
            case bedrock:
            {
                QPixmap pixmap(":/level_1/img/block/bedrock.jpg");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap, tile);
                level_1_Scene->addItem(tile);
                break;
            }
            case Road:
            {
                QPixmap pixmap("  ");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap, tile);
                level_1_Scene->addItem(pixmapItem);
                break;
            }
            case soil:
            {
                QPixmap pixmap(":/level_1/img/block/soil.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap, tile);
                level_1_Scene->addItem(pixmapItem);
                break;
            }
            case grass:
            {
                QPixmap pixmap(":/level_1/img/block/grass.jpg");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap, tile);
                level_1_Scene->addItem(pixmapItem);
                break;
            }
            case Cobblestone:
            {
                QPixmap pixmap(":/level_1/img/block/Cobblestone.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap, tile);
                level_1_Scene->addItem(pixmapItem);
                break;
            }

            }
        }
    }

}
Map_Level_1::~Map_Level_1()
{
    delete  m_l1_Map;
    delete level_1_Scene;
}


