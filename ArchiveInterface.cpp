#include "ArchiveInterface.h"

Archive::Archive()
{
    m_ArchiveGameScene = new QGraphicsScene;
    m_ArchiveGameScene->setSceneRect(QRect(0,0,2400,1300));
    m_ArchiveGameScene->addPixmap(QPixmap(":/back/img/background/IntiBackground.png"));

    m_ExitBtn.resize(493,129);
    m_ExitBtn.setIcon(QIcon(":/init/img/init/Exit.jpg"));
    m_ExitBtn.setIconSize(QSize(493,129));
    m_ExitBtn.setStyleSheet("QToolButton { background: transparent; }");//使背景透明
    m_ExitBtn.move(1800,1100);
    m_ExitBtn.setAutoRaise(true);

    m_ArchiveGameScene->addWidget(&m_ExitBtn);
}
Archive::~Archive()
{
    delete m_ArchiveGameScene;
}
