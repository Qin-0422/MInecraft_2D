#ifndef LEVEL_1_MAP_H
#define LEVEL_1_MAP_H
#include <QObject>
#include <QFile>
#include <QDebug>
#include <vector>
#include <QTextStream>
#include <QGraphicsRectItem>
using namespace  std;

class Level_Map
{
public:
    Level_Map();
    vector<vector<int>> InitByFile(const QString &filePath);
};

#endif // LEVEL_1_MAP_H
