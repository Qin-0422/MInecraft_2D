#ifndef INIT_H
#define INIT_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QToolButton>
class Init
{
public:
    Init();
    QGraphicsScene * m_InitGameScene;
    QGraphicsPixmapItem * m_title;
    QToolButton m_BeginBtn;
    QToolButton m_ArchiveBtn;//存档按钮
    QToolButton m_HelpBtn;

    ~Init();
};

#endif // INIT_H
