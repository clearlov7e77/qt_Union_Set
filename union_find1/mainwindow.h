#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include<QInputDialog>
#include<iostream>
#include<QDebug>
#include<QString>
#include<union_find.h>
#include<QPixmap>
#include"maze.h"
#include<QToolButton>
#include<QTextEdit>
#include<QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent* );
    int a1=0;
    QPointF point1[31];
    QPointF point2[31][31];
    Union_find *uf;
    Union_find *uf1;
    QPixmap image[16];
    maze* maze1=nullptr;
    QPushButton* T1;
    QPushButton* T2;
    QPushButton* T3;
    int n1=40;
    int p=0;
    int q=0;
    int cond=0;
    int sign=0;
    int sign_cnt=0;
    int alredy_map=0;
    int already_code=0;
    QToolButton v1[16];
    QTextEdit* l1;
    void mousePressEvent(QMouseEvent* );
//    QMouseEvent* e;
private:
    Ui::MainWindow *ui;
public slots:
    void chuxian();
    void changed();
    void c_cond0();
    void c_cond1();
    void c_cond2();
    void c_cond3();
    void c_cond4();
    void fun1();
    void fun2();
    void new_map();
    void chang_p();
    void about();
    void help();
    void code_show();
};

#endif // MAINWINDOW_H
