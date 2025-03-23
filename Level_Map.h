#ifndef LEVEL_1_MAP_H
#define LEVEL_1_MAP_H
#include <QObject>
#include <QFile>
#include <QDebug>
#include <vector>
#include <QTextStream>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
using namespace  std;
enum Map_Element
{
    bedrock,
    Road,
    soil,
    grass,
    Cobblestone,//原石
    Log,
    leaf,
    Plank,
    Stone,
    TransmitBlock,
    craftingTable,
    MossyStone,//苔藓石块
    Ladder,
    LauncherBlock,
    box,
    TransmitBlockBack,//传送回去
};

class Level_Map
{
public:
    Level_Map();
    virtual ~Level_Map() = default;
    vector<vector<int>> InitByFile(const QString &filePath);
    virtual bool isRoad(int x, int y) const = 0;
    virtual bool isLadder(int x, int y) const = 0;
    virtual bool isTransmit(int x, int y) const = 0;
    virtual bool isTransmitBack(int x, int y) const = 0;
    virtual QGraphicsScene* getScene() const = 0;
};
#endif // LEVEL_1_MAP_H
