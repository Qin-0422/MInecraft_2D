#include "Level_Map.h"



Level_Map::Level_Map()
{
}

vector<vector<int> > Level_Map::InitByFile(const QString &filePath)
{
    vector<vector<int>> map;
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line =in.readLine();
            QStringList numbers = line.split(",");
            vector<int> row;
            for(const QString &number:numbers)
            {
                row.push_back(number.toInt());
            }
            map.push_back(row);
        }
        file.close();
    }
    return map;
}



