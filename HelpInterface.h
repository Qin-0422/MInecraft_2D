#ifndef HELPINTERFACE_H
#define HELPINTERFACE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QToolButton>

class HelpInterface
{
public:
    HelpInterface();
    QGraphicsScene * m_HelpGameScene;
    QToolButton m_ExitBtn;
    ~HelpInterface();
};

#endif // HELPINTERFACE_H
