#include "Level_Map_Impl.h"

Level_Map_Impl::Level_Map_Impl()
{
    scene = new QGraphicsScene();
}

Level_Map_Impl::~Level_Map_Impl()
{
    delete scene;
}

bool Level_Map_Impl::isRoad(int x, int y) const
{
    int col = x / 50; // 假设 tileSize 是 50
    int row = y / 50;
    if (row >= 0 && row < map_data.size() && col >= 0 && col < map_data[row].size())
    {
        return( map_data[row][col] == 1||map_data[row][col] ==9||map_data[row][col] ==12||map_data[row][col] ==15); // 检查 map_data[row][col] 是否为 1,9
    }
    return false;
}
bool Level_Map_Impl::isLadder(int x, int y) const
{
    int col = x / 50; // 假设 tileSize 是 50
    int row = y / 50;
    if (row >= 0 && row < map_data.size() && col >= 0 && col < map_data[row].size())
    {
        return map_data[row][col] ==12; // 检查 map_data[row][col] 是否为 1,9
    }
    return false;
}
bool Level_Map_Impl::isTransmit(int x, int y) const
{
    int col = x / 50; // 假设 tileSize 是 50
    int row = y / 50;
    if (row >= 0 && row < map_data.size() && col >= 0 && col < map_data[row].size())
    {
        return map_data[row][col] == 9; // 检查 map_data[row][col] 是否为 9
    }
    return false;
}
bool Level_Map_Impl::isTransmitBack(int x, int y) const
{
    int col = x / 50; // 假设 tileSize 是 50
    int row = y / 50;
    if (row >= 0 && row < map_data.size() && col >= 0 && col < map_data[row].size())
    {
        return map_data[row][col] == 15; // 检查 map_data[row][col] 是否为 15
    }
    return false;
}

QGraphicsScene* Level_Map_Impl::getScene() const
{
    return scene;
}
