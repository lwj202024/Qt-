#include "fly_bird.h"
#include "./ui_fly_bird.h"
#include<QTimer>
#include <QKeyEvent>
fly_bird::fly_bird(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fly_bird)
{
    ui->setupUi(this);
    this->setGeometry(QRect(600,300,500,500));
    this->setWindowTitle("飞扬的小鸟");
}
void fly_bird::drawpillar(QPainter &painter,int x,int l1,int l2){
    painter.setBrush(Qt::blue);
    painter.drawRect(x,0,25,l1);
    painter.drawRect(x,500-l2,25,l2);
}
void fly_bird::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if(!s) init();
    for(int i=left;i<=right;i++){
        int x=pillar[i].x;
        int l1=pillar[i].l1;
        int l2=pillar[i].l2;
        drawpillar(painter,x,l1,l2);
    }
    painter.setBrush(Qt::yellow);
    painter.drawRect(bird);
}

fly_bird::~fly_bird()
{
    delete ui;
}
void fly_bird::init(){
    s=1;
    dx=0;
    speed=5;
    int x=0,l1,l2;
    bool f=0;
    srand(time(0));
    for(int i=0;i<=2000;i++){
        x+=(rand()%4+2)*25;
        l1=(rand()%4+1)*25;
        l2=500-l1-(rand()%5+2)*25;
        if(!f) if(x>500) f=1,right=i-1;
        pillar.append({x,l1,l2});
    }
    left=0;
    QRect rect(25,225,10,10);
    bird=rect;
    timer=new QTimer(this);
    timer->start(100);
    connect(timer,SIGNAL(timeout()),SLOT(bird_update()));
}
void fly_bird::bird_update(){
    bird.translate(0,3);
    dx+=speed;
    for(int i=left;i<=right;i++){
        pillar[i].x-=speed;
    }
    if(pillar[left].x+25<=0) left++;
    if(pillar[right+1].x-dx<=500) {
        pillar[right+1].x-=dx;
        right++;
    }
    update();

}
void fly_bird::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Space) {
        bird.translate(0,-20);
    }
    update();
}
