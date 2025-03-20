#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QToolButton>
class Archive
{
public:
    Archive();
    QGraphicsScene * m_ArchiveGameScene;
    QToolButton m_ExitBtn;
    ~Archive();
};

#endif // ARCHIVE_H
