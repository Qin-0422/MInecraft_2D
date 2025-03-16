#include "BeginInterface.h"

BeginInterface::BeginInterface()
{
    m_BeginGameScene = new QGraphicsScene;
    m_BeginGameScene->setSceneRect(QRect(0,0,2400,1300));
    m_BeginGameScene->addPixmap(QPixmap(":/back/img/background/IntiBackground.png"));

    m_EasyBeginBtn.resize(800,97);
    m_EasyBeginBtn.setIcon(QIcon(":/init/img/init/easy.png"));
    m_EasyBeginBtn.setIconSize(QSize(800,97));
    m_EasyBeginBtn.setStyleSheet("QToolButton { background: transparent; }");//使背景透明
    m_EasyBeginBtn.move(780,498);
    m_EasyBeginBtn.setAutoRaise(true);

    m_DiffBeginBtn.resize(800,97);
    m_DiffBeginBtn.setIcon(QIcon(":/init/img/init/difficult.png"));
    m_DiffBeginBtn.setIconSize(QSize(800,97));
    m_DiffBeginBtn.setStyleSheet("QToolButton { background: transparent; }");//使背景透明
    m_DiffBeginBtn.move(780,698);
    m_DiffBeginBtn.setAutoRaise(true);

    m_ExitBtn.resize(493,129);
    m_ExitBtn.setIcon(QIcon(":/init/img/init/Exit.jpg"));
    m_ExitBtn.setIconSize(QSize(493,129));
    m_ExitBtn.setStyleSheet("QToolButton { background: transparent; }");//使背景透明
    m_ExitBtn.move(1800,1100);
    m_ExitBtn.setAutoRaise(true);

    m_BeginGameScene->addWidget(&m_EasyBeginBtn);
    m_BeginGameScene->addWidget(&m_DiffBeginBtn);
    m_BeginGameScene->addWidget(&m_ExitBtn);
}

BeginInterface::~BeginInterface()
{
    delete m_BeginGameScene;
}
