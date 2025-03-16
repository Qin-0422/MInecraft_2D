#ifndef BEGININTERFACE_H
#define BEGININTERFACE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QToolButton>

class BeginInterface
{
public:
    BeginInterface();
    QGraphicsScene * m_BeginGameScene;
    QToolButton m_EasyBeginBtn;
    QToolButton m_DiffBeginBtn;
     QToolButton m_ExitBtn;
    ~BeginInterface();
};

#endif // BEGININTERFACE_H
