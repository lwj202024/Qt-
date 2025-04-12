#ifndef FLY_BIRD_H
#define FLY_BIRD_H

#include <QMainWindow>
#include<qpainter.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class fly_bird;
}
QT_END_NAMESPACE

class fly_bird : public QMainWindow
{
    Q_OBJECT

public:
    fly_bird(QWidget *parent = nullptr);
    ~fly_bird();
    void paintEvent(QPaintEvent *event);
    void init();

private slots:
    void bird_update();

private:
    Ui::fly_bird *ui;
    void keyPressEvent(QKeyEvent *key);
    void drawpillar(QPainter &painter,int x,int l1,int l2);
    QRect bird;
    QTimer *timer;
    QTimer *timer2;
    bool s=0;
    int left,right,cp;
    struct p{
        int x,l1,l2;
    };
    struct Q{
        double c,nc;
    };

    QVector<p> pillar;
    QVector<QVector<Q>> q;
    int dx,speed;
};
#endif // FLY_BIRD_H
