#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>

#include "Init.h"
#include "BeginInterface.h"
#include "ArchiveInterface.h"
#include "HelpInterface.h"
#include "Map_Level_1.h"
#include "Map_Level_2.h"
#include "Steve.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QGraphicsView * m_view;
    Init m_Init;
    BeginInterface m_BeginInterface;
    Archive m_Archive;
    HelpInterface m_HelpInterface;
    Map_Level_1 m_Map_1;
    Map_Level_2 m_Map_2;


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
