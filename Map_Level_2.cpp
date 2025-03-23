#include "Map_Level_2.h"

Map_Level_2::Map_Level_2()
{
    //初始化地图元素
    m_l2_Map = new Level_Map_Impl; // 创建实现类的实例
    level_2_Scene = new QGraphicsScene;
    filePath = "../Map/level_2.txt";
    map_2 = m_l2_Map->InitByFile(filePath);

    int tileSize = 50;
    for(int row = 0;row< map_2.size() ;++row)
    {
        for(int col = 0;col<map_2[row].size();++col)
        {
            QGraphicsRectItem *tile = new QGraphicsRectItem(col * tileSize, row * tileSize, tileSize, tileSize);
            switch (map_2[row][col])
            {
            case bedrock:
            {
                QPixmap pixmap(":/level_2/img/block/bedrock.jpg");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_2_Scene->addItem(pixmapItem);
                break;
            }
            case Road:
            {
                QPixmap pixmap(":/level_2/img/block/Road.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_2_Scene->addItem(pixmapItem);
                break;
            }
            case Stone:
            {
                QPixmap pixmap(":/level_2/img/block/Stone.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_2_Scene->addItem(pixmapItem);
                break;
            }

            case Cobblestone:
            {
                QPixmap pixmap(":/level_2/img/block/Cobblestone.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_2_Scene->addItem(pixmapItem);
                break;
            }
           case craftingTable:
            {
                QPixmap pixmap(":/level_2/img/block/Crafting_Table.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_2_Scene->addItem(pixmapItem);
                break;
            }
            case Ladder:
            {
                QPixmap pixmap(":/level_2/img/block/Ladder.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_2_Scene->addItem(pixmapItem);
                break;
            }
            case MossyStone:
            {
                QPixmap pixmap(":/level_2/img/block/MossyStone.jpg");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_2_Scene->addItem(pixmapItem);
                break;
            }

            case TransmitBlock:
            {
                QPixmap pixmap(":/level_2/img/block/TransmitBlock.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_2_Scene->addItem(pixmapItem);
                break;
            }
            case TransmitBlockBack:
            {
                QPixmap pixmap(":/level_2/img/block/TransmitBlock.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_2_Scene->addItem(pixmapItem);
                break;
            }
            case LauncherBlock:
            {
                QPixmap pixmap(":/level_2/img/block/Launcher.jpg");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_2_Scene->addItem(pixmapItem);
                break;
            }
            case box:
            {
                QPixmap pixmap(":/level_2/img/block/box.png");
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
                pixmapItem->setPos(col*tileSize,row*tileSize);
                level_2_Scene->addItem(pixmapItem);
                break;
            }
            }
        }
    }

    m_Steve.setX(150);
    m_Steve.setY(100);
    level_2_Scene->addItem(&m_Steve);


    level_2_Scene->addItem(&m_Zombie);
    m_Steve.setMap(this);  // 设置Steve的地图指针
}

Map_Level_2::~Map_Level_2()
{
    delete  m_l2_Map;
    delete level_2_Scene;
}

bool Map_Level_2::isRoad(int x, int y) const
{
    int col = x / 50; // assuming tileSize is 50
    int row = y / 50;
    if (row >= 0 && row < map_2.size() && col >= 0 && col < map_2[row].size())
    {
        return ( map_2[row][col] == 1||map_2[row][col] ==9||map_2[row][col] ==12||map_2[row][col] ==15);  // 修改为检查 map_1[row][col] 是否为 路,传送门，梯子
    }
    return false;
}
bool Map_Level_2::isLadder(int x, int y) const
{
    int col = x / 50; // assuming tileSize is 50
    int row = y / 50;
    if (row >= 0 && row < map_2.size() && col >= 0 && col < map_2[row].size())
    {
        return map_2[row][col] ==12;  // 修改为检查 map_1[row][col] 是否为 梯子
    }
    return false;
}
bool Map_Level_2::isTransmit(int x, int y) const
{
    int col = x / 50; // assuming tileSize is 50
    int row = y / 50;
    if (row >= 0 && row < map_2.size() && col >= 0 && col < map_2[row].size()) {
        return map_2[row][col] == 9;  // 修改为检查 map_1[row][col] 是否为 9
    }
    return false;
}
bool Map_Level_2::isTransmitBack(int x, int y) const
{
    int col = x / 50; // assuming tileSize is 50
    int row = y / 50;
    if (row >= 0 && row < map_2.size() && col >= 0 && col < map_2[row].size()) {
        return map_2[row][col] == 15;  // 修改为检查 map_1[row][col] 是否为 15
    }
    return false;
}
