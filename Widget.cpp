#include "Widget.h"
#include "ui_widget.h"
#include <QToolButton>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    m_view = new QGraphicsView(this);
   

    this->setFixedSize(2400,1300);
    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 关闭滚动条
    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view->setSceneRect(QRect(0,0,2400,1300));

    m_view->setScene(m_Init.m_InitGameScene);
    //主界面和开始游戏的往返
    connect(&m_Init.m_BeginBtn,&QToolButton::clicked,[this](){
        m_view->setScene(m_BeginInterface.m_BeginGameScene);
        m_view->show();
    });
    connect(&m_BeginInterface.m_ExitBtn,&QToolButton::clicked,[this](){
        m_view->setScene(m_Init.m_InitGameScene);
        m_view->show();
    });
     //主界面和存档的往返
    connect(&m_Init.m_ArchiveBtn,&QToolButton::clicked,[this](){
        m_view->setScene(m_Archive.m_ArchiveGameScene);
        m_view->show();
    });
    connect(&m_Archive.m_ExitBtn,&QToolButton::clicked,[this](){
        m_view->setScene(m_Init.m_InitGameScene);
        m_view->show();
    });
     //主界面和帮助的往返
    connect(&m_Init.m_HelpBtn,&QToolButton::clicked,[this](){
        m_view->setScene(m_HelpInterface.m_HelpGameScene);
        m_view->show();
    });
    connect(&m_HelpInterface.m_ExitBtn,&QToolButton::clicked,[this](){
        m_view->setScene(m_Init.m_InitGameScene);
        m_view->show();
    });
    //简单到level——1 （后期要修改)
    connect(&m_BeginInterface.m_EasyBeginBtn,&QToolButton::clicked,[this](){
        m_view->setScene(m_Map_1.level_1_Scene);
        m_view->show();
    });

    //从关卡1到关卡2
    connect(&m_Map_1.m_Steve,&Steve::changeLevel,[this](){
        m_view->setScene(m_Map_2.level_2_Scene);
        m_Map_1.m_Steve.setX(100);
        m_Map_1.m_Steve.setY(100);
        m_view->show();
    });
    //从关卡2到关卡3
//    connect(&m_Map_2.m_Steve,&Steve::changeLevel,[this](){
//        m_view->setScene(m_Map_3 );
//        m_view->show();


    //从关卡2到关卡1
    connect(&m_Map_2.m_Steve,&Steve::changeBackLevel,[this](){
       m_view->setScene(m_Map_1.level_1_Scene);
       m_Map_1.m_Steve.setX(1900);
       m_Map_1.m_Steve.setY(1100);
       m_view->show();
    });

    ui->setupUi(this);
}



Widget::~Widget()
{
    delete ui;

}
