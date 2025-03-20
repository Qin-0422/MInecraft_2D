#include "HelpInterface.h"

HelpInterface::HelpInterface()
{
    m_HelpGameScene = new QGraphicsScene;
    m_HelpGameScene->setSceneRect(QRect(0,0,2400,1300));
    m_HelpGameScene->addPixmap(QPixmap(":/back/img/background/IntiBackground.png"));

    m_ExitBtn.resize(493,129);
    m_ExitBtn.setIcon(QIcon(":/init/img/init/Exit.jpg"));
    m_ExitBtn.setIconSize(QSize(493,129));
    m_ExitBtn.setStyleSheet("QToolButton { background: transparent; }");//使背景透明
    m_ExitBtn.move(1800,1100);
    m_ExitBtn.setAutoRaise(true);

    m_HelpGameScene->addWidget(&m_ExitBtn);
}
HelpInterface::~HelpInterface()
{
    delete m_HelpGameScene;
}
