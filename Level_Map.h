#ifndef LEVEL_1_MAP_H
#define LEVEL_1_MAP_H
#include <QObject>
#include <QFile>
#include <QDebug>
#include <vector>
#include <QTextStream>
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
};

class Level_Map
{
public:
    Level_Map();
    vector<vector<int>> InitByFile(const QString &filePath);
};

#endif // LEVEL_1_MAP_H
