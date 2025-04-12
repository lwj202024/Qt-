#include "fly_bird.h"
#include "./ui_fly_bird.h"
#include<QTimer>
#include <QKeyEvent>
#include<QFile>
#include<QTextStream>
fly_bird::fly_bird(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fly_bird)
{
    ui->setupUi(this);
    this->setGeometry(QRect(600,300,500,500));
    this->setWindowTitle("飞扬的小鸟");
}
void fly_bird::drawpillar(QPainter &painter,int x,int l1,int l2){
    //painter.setBrush(Qt::blue);
    painter.drawPixmap(x,0,35,l1,QPixmap(":/new/prefix1/images/管柱.png"));
    painter.drawPixmap(x,500-l2,35,l2,QPixmap(":/new/prefix1/images/管柱.png"));
    // painter.drawRect(x,0,25,l1);
    // painter.drawRect(x,500-l2,25,l2);
}
void fly_bird::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0,0,500,500,QPixmap(":/new/prefix1/images/blue_sky.png"));
    if(!s) init();
    for(int i=left;i<=right;i++){
        int x=pillar[i].x;
        int l1=pillar[i].l1;
        int l2=pillar[i].l2;
        drawpillar(painter,x,l1,l2);
    }
    //painter.setBrush(Qt::yellow);
    painter.drawPixmap(bird,QPixmap(":/new/prefix1/images/bird1.png"));
    //painter.drawRect(bird);
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
        x+=(rand()%4+3)*25;
        l1=(rand()%4+1)*25;
        l2=500-l1-100;
        if(!f) if(x>500) f=1,right=i-1;
        pillar.append({x,l1,l2});
    }
    left=0,cp=0;
    QRect rect(25,225,30,30);
    bird=rect;
    timer=new QTimer(this);
    timer->start(70);
    connect(timer,SIGNAL(timeout()),SLOT(bird_update()));
    QFile file(":/new/prefix1/ai_matrix/output.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString all=stream.readAll();
    QStringList list=all.split(' ');
    for(int i=0;i<list.size();i+=400){
        QVector<Q> row;
        for(int j=i;j<i+400&&j<list.size();j++){
            bool ok1,ok2;
            QStringList list2=list[j].split(',');
            double x=list2[0].toDouble(&ok1);
            double y=list2[1].toDouble(&ok2);
            if(ok1&&ok2) row.append({x,y});
        }
        q.append(row);
    }
    file.close();
}
void fly_bird::bird_update(){
    dx+=speed;
    for(int i=left;i<=right;i++){
        pillar[i].x-=speed;
    }
    if(pillar[left].x+25<=0) left++;
    if(pillar[right+1].x-dx<=500) {
        pillar[right+1].x-=dx;
        right++;
    }
    if(pillar[cp].x<35) cp++;
    int x=pillar[cp].x-35;
    int y=-(500-pillar[cp].l2-bird.bottom())+200;
    // qInfo()<<x<<' '<<y-200;
    // qInfo()<<q[x][y].c<<' '<<q[x][y].nc<<' '<<(q[x][y].c>q[x][y].nc);
    if(y<200){
        if(q[x][y].c>q[x][y].nc) bird.translate(0,-20);
    }else if(q[x][y].c>=q[x][y].nc) bird.translate(0,-20);

    bird.translate(0,3);
    update();

}
void fly_bird::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Space) {
        bird.translate(0,-20);
    }
    update();
}
