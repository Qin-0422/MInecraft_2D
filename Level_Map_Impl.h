#ifndef LEVEL_MAP_IMPL_H
#define LEVEL_MAP_IMPL_H
#include "Level_Map.h"
#include <QGraphicsScene>

class Level_Map_Impl : public Level_Map
{
public:
    Level_Map_Impl();
    ~Level_Map_Impl(); // 添加析构函数
    bool isRoad(int x, int y) const override;
    bool isLadder(int x, int y) const override;
    bool isTransmit(int x, int y) const override;
    bool isTransmitBack(int x, int y) const override;
    QGraphicsScene* getScene() const override;

private:
    vector<vector<int>> map_data;
    QGraphicsScene* scene;
};

#endif // LEVEL_MAP_IMPL_H
