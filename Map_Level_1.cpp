#include "Map_Level_1.h"

Map_Level_1::Map_Level_1()
{
    //初始化地图元素
    m_l1_Map =  new Level_Map_Impl;
    level_1_Scene = new QGraphicsScene;
    filePath = "../Map/level_1.txt";
    map_1 = m_l1_Map->InitByFile(filePath);

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
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_1_Scene->addItem(pixmapItem);
                break;
            }
            case Road:
            {
                QPixmap pixmap(":/level_1/img/block/Road.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_1_Scene->addItem(pixmapItem);
                break;
            }
            case soil:
            {
                QPixmap pixmap(":/level_1/img/block/soil.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_1_Scene->addItem(pixmapItem);
                break;
            }
            case grass:
            {
                QPixmap pixmap(":/level_1/img/block/grass.jpg");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_1_Scene->addItem(pixmapItem);
                break;
            }
            case Cobblestone:
            {
                QPixmap pixmap(":/level_1/img/block/Cobblestone.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_1_Scene->addItem(pixmapItem);
                break;
            }
            case Log:
            {
                QPixmap pixmap(":/level_1/img/block/Log.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_1_Scene->addItem(pixmapItem);
                break;
            }
            case leaf:
            {
                QPixmap pixmap(":/level_1/img/block/leaf.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_1_Scene->addItem(pixmapItem);
                break;
            }
            case Plank:
            {
                QPixmap pixmap(":/level_1/img/block/Planks.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_1_Scene->addItem(pixmapItem);
                break;
            }

            }
        }
    }

    m_Steve.setX(300);
    m_Steve.setY(950);
    level_1_Scene->addItem(&m_Steve);
     m_Steve.setMap(this);  // 设置Steve的地图指针
}


Map_Level_1::~Map_Level_1()
{
    delete  m_l1_Map;
    delete level_1_Scene;
}

bool Map_Level_1::isRoad(int x, int y) const
{
    int col = x / 50; // assuming tileSize is 50
    int row = y / 50;
    if (row >= 0 && row < map_1.size() && col >= 0 && col < map_1[row].size()) {
        return map_1[row][col] == 1;  // 修改为检查 map_1[row][col] 是否为 1
    }
    return false;
}





