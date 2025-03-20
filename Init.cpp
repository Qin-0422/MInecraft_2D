#include "Init.h"

Init::Init()
{
    m_InitGameScene = new QGraphicsScene;
    m_title =new QGraphicsPixmapItem;


    m_InitGameScene->setSceneRect(QRect(0,0,2400,1300));
    m_InitGameScene->addPixmap(QPixmap(":/back/img/background/IntiBackground.png"));
    m_title->setPixmap(QPixmap(":/init/img/init/Minecraft.png"));
    m_title->setPos(QPoint(524,160));
    m_InitGameScene->addItem(m_title);

    //设置三个ToolButton放在主菜单
    m_BeginBtn.resize(800,97);
    m_BeginBtn.setIcon(QIcon(":/init/img/init/Init_NewWorld.jpg"));
    m_BeginBtn.setIconSize(QSize(800,97));
    m_BeginBtn.setStyleSheet("QToolButton { background: transparent; }");//使背景透明
    m_BeginBtn.move(780,498);
    m_BeginBtn.setAutoRaise(true);

    m_ArchiveBtn.resize(800,97);
    m_ArchiveBtn.setIcon(QIcon(":/init/img/init/Init_Archive.jpg"));
    m_ArchiveBtn.setIconSize(QSize(800,97));
    m_ArchiveBtn.setStyleSheet("QToolButton { background: transparent; }");//使背景透明
    m_ArchiveBtn.move(780,698);
    m_ArchiveBtn.setAutoRaise(true);

    m_HelpBtn.resize(800,97);
    m_HelpBtn.setIcon(QIcon(":/init/img/init/Init_Help.jpg"));
    m_HelpBtn.setIconSize(QSize(800,97));
    m_HelpBtn.setStyleSheet("QToolButton { background: transparent; }");//使背景透明
    m_HelpBtn.move(780,898);
    m_HelpBtn.setAutoRaise(true);

    m_InitGameScene->addWidget(&m_BeginBtn);
    m_InitGameScene->addWidget(&m_ArchiveBtn);
    m_InitGameScene->addWidget(&m_HelpBtn);
}

Init::~Init()
{
    delete m_InitGameScene;
    delete m_title;
}
