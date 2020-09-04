#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "union_find.h"
#include <QPainter>
#include<QToolButton>
#include<QString>
#include<QInputDialog>
#include<QPixmap>
#include<QDir>
#include"maze.h"
#include<random>
#include<QMessageBox>
#include<QMouseEvent>
#define BTNSTYLESHEET "QPushButton {color: blue;background: lightgray;border: %1px solid darkgray;border-radius: %2px;} QPushButton:pressed{color: white;background: orange;border: %1px solid darkgray;border-radius: %2px;}"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  //  uf=new quick_find(30);
   /* restartBtn = new QPushButton("Restart", this);
    restartBtn->setGeometry(100, 120, 200, 50);
    restartBtn->setFont(font);
    restartBtn->setStyleSheet(QString(BTNSTYLESHEET).arg(3).arg(15));
    connect(restartBtn, SIGNAL(clicked()), gameWidget, SLOT(restart()));
    */
    ui->setupUi(this);
    QFont font1;
    font1.setFamily("Consolas");
    font1.setBold(true);
    font1.setPixelSize(25);
    T1=new QPushButton(this);
    T1->setVisible(0);
    T1->setStyleSheet(QString(BTNSTYLESHEET).arg(3).arg(15));
    T1->setFont(font1);
    T2=new QPushButton(this);
    T2->setVisible(0);
    T2->setStyleSheet(QString(BTNSTYLESHEET).arg(3).arg(15));
    T2->setFont(font1);
    T3=new QPushButton(this);
    T3->setVisible(0);
    T3->setStyleSheet(QString(BTNSTYLESHEET).arg(3).arg(15));
    T3->setFont(font1);
    for(int i=1;i<=15;i++)v1[i].setParent(this);
    connect(T2,&QPushButton::clicked,this,&MainWindow::fun2);
    connect(T1,&QPushButton::clicked,this,&MainWindow::chang_p);
    connect(T3,&QPushButton::clicked,this,&MainWindow::new_map);
    connect(ui->toolButton_3,&QToolButton::clicked,this,&MainWindow::chuxian);
    connect(ui->toolButton_2,&QToolButton::clicked,this,&MainWindow::changed);
    connect(ui->actionquick_find,&QAction::triggered,this,&MainWindow::c_cond0);
    connect(ui->actionquick_union,&QAction::triggered,this,&MainWindow::c_cond1);
    connect(ui->actionweighted_quick_union,&QAction::triggered,this,&MainWindow::c_cond2);
    connect(ui->actionweighted_QU_path_compression,&QAction::triggered,this,&MainWindow::c_cond3);
    connect(ui->actiondynamic_connectivity,&QAction::triggered,this,&MainWindow::c_cond4);
    connect(ui->actionzuozhe,&QAction::triggered,this,&MainWindow::about);
    connect(ui->actionhelp,&QAction::triggered,this,&MainWindow::help);
    connect(ui->toolButton,&QToolButton::clicked,this,&MainWindow::code_show);
    ui->toolButton_3->setGeometry(1400,50,100,30);
    ui->toolButton_2->setGeometry(1400,80,100,30);
    ui->toolButton->setGeometry(1400,110,100,30);
    ui->toolButton->setText("show_code");
       l1=new QTextEdit(this);
       l1->setGeometry(1000,500,500,500);
       l1->setVisible(0);
   /* v1[1]=new QToolButton(this);
    v1[1]->setIcon(QIcon(":/new/prefix1/pointer/1.png"));
    v1[1]->setStyleSheet("border-style:flat");
    v1[1]->setGeometry(100,100,30,30);
        */
    QString s2=":/new/prefix1/pointer/%1.png";
    QSize size1(30,30);
   // QPainter painter3(this);
  //  QString s4="QPushButton{border-image: url(:/new/prefix1/pointer/%1.png);border-style:flat;}";
    for(int i=1;i<=15;i++){
     //   QPixmap pixmap2(s2.arg(i));
     //   int width=pixmap2.width();
     //   int height=pixmap2.height();
     //   pixmap2= pixmap2.scaled(width*5,height*5,Qt::KeepAspectRatio);
     //   v1[i].setStyleSheet(s4.arg(i));
        v1[i].setIcon(QIcon(s2.arg(i)));
        v1[i].setIconSize(size1);
    //    v1[i].setFixedSize(300,300);
        v1[i].setStyleSheet("border-style:flat");
        v1[i].setVisible(0);
   //     v1[i].setGeometry(point1[i].rx(),point1[i].ry(),30,30);
        connect(&v1[i],&QToolButton::clicked,
                [i,this]()
        {
            sign=i;
           // qDebug()<<sign;
        }
        );
        connect(&v1[i],&QToolButton::clicked,this,&MainWindow::fun1);
    }
    s_1[0]="Union_find(int n){\n            for(int i=0;i<=3000;i++){\n                id[i]=i;\n                sz[i]=1;\n            }\n            count=n;\n            amount=n;\n    }\n    void union1(int p,int q){\n        int pid=id[p];\n        int qid=id[q];\n        if(pid!=qid){\n            for(int i=1;i<=amount;i++)\n                if(id[i]==qid)id[i]=pid;\n         count--;\n        }\n    }\n    bool connected1(int p,int q){\n        return id[p]==id[q];\n    }\n    int find1(int p){\n        return id[p];\n    }\n";
    s_1[1]="    Union_find(int n){\n            for(int i=0;i<=3000;i++){\n                id[i]=i;\n                sz[i]=1;\n            }\n            count=n;\n            amount=n;\n    }\n    void union2(int p,int q){\n        int rp=find2(p);\n        int rq=find2(q);\n        if(rq!=rp){\n            id[rq]=rp;\n            count--;\n        }\n\n    }\n    bool connected2(int p,int q){\n        return find2(p)==find2(q);\n    }\n    int find2(int p){\n        while(p!=id[p]){\n            p=id[p];\n        }\n        return id[p];\n    }\n";
    s_1[2]="    Union_find(int n){\n            for(int i=0;i<=3000;i++){\n                id[i]=i;\n                sz[i]=1;\n            }\n            count=n;\n            amount=n;\n    }\n    void union3(int p,int q){\n        int rp=find3(p);\n        int rq=find3(q);\n        if(rq!=rp){\n            if(sz[rq]>sz[rp]){id[rp]=rq;sz[rq]+=sz[rp];}\n            else {id[rq]=rp;sz[rp]+=sz[rq];}\n            count--;\n        }\n    }\n    bool connected3(int p,int q){\n        return find3(p)==find3(q);\n    }\n    int find3(int p){\n        while(p!=id[p]){\n            p=id[p];\n        }\n        return id[p];\n    }\n";
    s_1[3]="    Union_find(int n){\n            for(int i=0;i<=3000;i++){\n                id[i]=i;\n                sz[i]=1;\n            }\n            count=n;\n            amount=n;\n    }\n    void union4(int p,int q){\n        int rp=find4(p);\n        int rq=find4(q);\n        if(rq!=rp){\n            if(sz[rq]>sz[rp]){id[rp]=rq;sz[rq]+=sz[rp];}\n            else {id[rq]=rp;sz[rp]+=sz[rq];}\n            count--;\n        }\n    }\n    bool connected4(int p,int q){\n        return find4(p)==find4(q);\n    }\n    int find4(int p){\n        if(p!=id[p]){\n            id[p]=find4(id[p]);\n        }\n        return id[p];\n    }\n";
}


MainWindow::~MainWindow()
{
    delete ui;
    //delete uf;
  //  delete uf1;
    //delete uf;
    //for(int i=0;i<=15;i++)delete v1[i];
}

void MainWindow::paintEvent(QPaintEvent *)
{   QPainter painter(this);
    int _x3=50;
    int _y3=50;
    if(alredy_map==0)return;
    if(cond==4){
     //     qDebug()<<cond;
    //    painter.setPen(QPen(Qt::black,2));
        painter.setBrush(Qt::black);
        for(int i=0;i<n1;i++)
            for(int j=0;j<n1;j++){
                if(maze1->map1[i][j]==0){
                        painter.drawRect(_x3+j*20,_y3+i*20,20,20);
                }
            }
        painter.setBrush((Qt::yellow));
        for(int i=0;i<n1;i++){
            for(int j=0;j<n1;j++){
                if(maze1->map1[i][j]==1)
                    if(uf1->connected4(i*n1+j+1,n1*n1+88))painter.drawRect(_x3+j*20,_y3+i*20,20,20);
            }
        }
        painter.setBrush((Qt::white));
        for(int i=0;i<n1;i++){
            for(int j=0;j<n1;j++){
                if(maze1->map1[i][j]==1)
                    if(!uf1->connected4(i*n1+j+1,n1*n1+88))painter.drawRect(_x3+j*20,_y3+i*20,20,20);
            }
        }
        painter.setPen(QPen(Qt::black,2));
       // if(uf1->connected4(n1*n1+88,n1*n1+87)==1)painter.drawText(1200,300,"YES");
        return;
    }
    if(a1==0){
        return;
    }
    painter.setPen(QPen(Qt::red,2));
    for(int i=1;i<=a1;i++){
       // painter.drawEllipse(point1[i],20,20);
        if(i!=uf->id[i])painter.drawLine(point1[i].x()+20,point1[i].y()+20,point1[uf->id[i]].x()+20,point1[uf->id[i]].y()+20);
      //  painter.drawPixmap(point1[i].x(),point1[i].y(),30,30,image[i]);
        //QString s1="%1";
 //       painter.drawText(point1[i].x()+10,point1[i].y()+10,s1.arg(i));
    }
    painter.setPen(QPen(Qt::blue,3));
    painter.drawText(100,870,"index");
    painter.drawText(100,900,"id[]");
    int _x1=120,_y1=870,_y2=900;
    for(int i=1;i<=a1;i++){
    _x1+=30;
    QString s2="%1";
    painter.drawText(_x1,_y1,s2.arg(i));
    QString s3="%1";
    painter.drawText(_x1,_y2,s3.arg(uf->id[i]));
    }
    int len=_x1-90+30;
    painter.drawRect(90,850,len,60);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(cond==4){
    double x1=e->x();
    double y1=e->y();
    int i1=(y1-50)/20;
    int j1=(x1-50)/20;
    if(i1<0)return;
    if(j1<0)return;
    if(i1>=40)return;
    if(j1>=40)return;
    int walk[4][2]={0,1,0,-1,1,0,-1,0};
    if(maze1!=nullptr){
        if(maze1->map1[i1][j1]==0){
        maze1->map1[i1][j1]=1;
        for(int k=0;k<4;k++){
                    int i2=i1+walk[k][0];
                    int j2=j1+walk[k][1];
                  //  qDebug()<<i1<<" "<<j1;
                    if(i2<0||i2>=n1||j2<0||j2>=n1)continue;
                    if(maze1->map1[i2][j2]==1){
                           uf1->union4(i2*n1+j2+1,i1*n1+j1+1);
                    }
         }
       }
   }
    update();
   }
}

//初始化
void MainWindow::chuxian(){
    sign_cnt=0;
    /*
    QString s1=":/new/prefix1/pointer/%1.png";
    for(int i=1;i<=15;i++){
     image[i].load(s1.arg(i));
    }
    */
    bool ok;
    int a2=QInputDialog::getInt(this,"请输入要生成的节点数","节点数",10,1,15,1,&ok);
    /*
    v1[1]=new QToolButton(this);
    v1[1]->setVisible(1);
    v1[1]->setIcon(QIcon(":/new/prefix1/pointer/1.png"));
    v1[1]->setStyleSheet("border-style:flat");
    v1[1]->setGeometry(100,100,30,30);
    */
    if(ok){
        a1=a2;
        int x1=250,y1=50;
        int temp=900/(a1)+1;
        uf=new Union_find(a1);
        for(int i=1;i<=a1;i++){
                point1[i].setX(x1);
                point1[i].setY(y1);
                x1+=temp;
        }
        for(int i=1;i<=a1;i++){
            v1[i].setVisible(1);
        }
        for(int i=a1+1;i<=15;i++){
            v1[i].setVisible(0);
        }
 //   qDebug()<<a1;
        for(int i=1;i<=a1;i++){
          v1[i].setGeometry(point1[i].x(),point1[i].y(),40,40);
        }
        alredy_map=1;
        update();
    }
}
//通过输入p,q的形式调用Union 只支持个位数
void MainWindow::changed(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Union"),
                                         tr("请以p,q的形式输入(p,q为union操作的节点):"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if(alredy_map==0)return;
    int p=0,q=0;
    int i;
    for(i=0;i<text.size();i++){
        char c1=text[i].toLatin1();
        if(c1>='0'&&c1<='9'){
            p*=10;
            p+=c1-'0';
        }
        else break;
    }
    i++;
    for(;i<text.size();i++){
        char c1=text[i].toLatin1();
        if(c1>='0'&&c1<='9'){
            q*=10;
            q+=c1-'0';
        }
    }
   // qDebug()<<p<<" "<<q;
    if(ok)
    {
    if(p<=0||p>15||q<=0||q>15){
        QMessageBox::information(this, "Warning", "Error Input !");
        return;
    }
    (uf->*uf->c_un[cond])(p,q);
    qDebug()<<cond;
    bool marked[30]={0};
    bool marked1[30][30]={0};
  //  for(int i=0;i<30;i++)
     //   for(int j=0;j<30;j++)marked1[i][j]=0;
    int cnt=0;
    int x1=250,y1=50;
    int cnt1=0;
    for(int i=1;i<=a1;i++){
        if(i==uf->id[i])cnt1++;
    }
    int temp=1080/(cnt1)+1;
    for(int i=1;i<=a1;i++){
        if(i==uf->id[i]){
            marked[i]=1;
            point1[i].setX(x1);
            point1[i].setY(y1);
            x1+=temp;
        }
    }
    cnt+=cnt1;
    while(1){
        if(cnt==a1)break;
        for(int i=1;i<=a1;i++){
            if(marked[i])continue;
            if(marked[uf->id[i]]){
                marked[i]=1;
                cnt++;
                for(int j=7;j<15;j--){
                    if(!marked1[uf->id[i]][j]){
                        marked1[uf->id[i]][j]=1;
                        point1[i].setX(point1[uf->id[i]].x()+(j-7)*30);
                        point1[i].setY(point1[uf->id[i]].y()+50);
                      //  qDebug()<<uf->id[i]<<" "<<point1[i].x()<<" "<<point1[i].y();
                      //  qDebug()<<i<<" "<<point1[i].x()<<" "<<point1[i].y();
                        break;
                    }
                    if(!marked1[uf->id[i]][14-j]){
                        marked1[uf->id[i]][14-j]=1;
                        point1[i].setX(point1[uf->id[i]].x()+(7-j)*30);
                        point1[i].setX(point1[uf->id[i]].y()+50);
                    }
                }
            }
        }
    }
    for(int i=1;i<=a1;i++){
     v1[i].setGeometry(point1[i].x(),point1[i].y(),40,40);
    }
    update();
    }
}

void MainWindow::c_cond0()
{
    cond=0;
    T1->setVisible(0);
    T2->setVisible(0);
    T3->setVisible(0);
    ui->toolButton_2->setVisible(1);
    ui->toolButton_3->setVisible(1);
    ui->toolButton->setVisible(1);
    alredy_map=0;
    for(int i=1;i<=15;i++)v1[i].setVisible(0);
    l1->setVisible(0);
    ui->toolButton->setText("show_code");
    already_code=0;
    update();
}

void MainWindow::c_cond1()
{
    cond=1;
    T1->setVisible(0);
    T2->setVisible(0);
    T3->setVisible(0);
    ui->toolButton_2->setVisible(1);
    ui->toolButton_3->setVisible(1);
    ui->toolButton->setVisible(1);
    alredy_map=0;
    for(int i=1;i<=15;i++)v1[i].setVisible(0);
    l1->setVisible(0);
    ui->toolButton->setText("show_code");
    already_code=0;
    update();
}

void MainWindow::c_cond2()
{
    cond=2;
    T1->setVisible(0);
    T2->setVisible(0);
    T3->setVisible(0);
    ui->toolButton_2->setVisible(1);
    ui->toolButton_3->setVisible(1);
    ui->toolButton->setVisible(1);
    alredy_map=0;
    for(int i=1;i<=15;i++)v1[i].setVisible(0);
    l1->setVisible(0);
    ui->toolButton->setText("show_code");
    already_code=0;
    update();
}

void MainWindow::c_cond3()
{
    cond=3;
    T1->setVisible(0);
    T2->setVisible(0);
    T3->setVisible(0);
    ui->toolButton_2->setVisible(1);
    ui->toolButton_3->setVisible(1);
    ui->toolButton->setVisible(1);
    alredy_map=0;
    for(int i=1;i<=15;i++)v1[i].setVisible(0);
    l1->setVisible(0);
    ui->toolButton->setText("show_code");
    already_code=0;
    update();
}

void MainWindow::c_cond4()
{
    cond=4; 
    T1->setVisible(1);
    T1->setGeometry(1200,300,300,30);
    T1->setText("修改每个点open的概率");
    T2->setVisible(1);
    T2->setGeometry(1200,270,300,30);
    T2->setText("开始");
    T3->setVisible(1);
    T3->setText("生成");
    T3->setGeometry(1200,240,300,30);
    ui->toolButton->hide();
    ui->toolButton_2->hide();
    ui->toolButton_3->hide();
   // qDebug()<<cond;
    for(int i=1;i<=15;i++){
        v1[i].setVisible(0);
    }
    maze1=nullptr;
    alredy_map=0;
    l1->setVisible(0);
    ui->toolButton->setText("show_code");
    already_code=0;
    update();
    return;
}
void MainWindow::new_map(){
    int n=40;
    //qDebug()<<n;
    n1=n;
    maze1=new maze(n);
    alredy_map=1;
    update();
    uf1=new Union_find(n*n+100);
}

void MainWindow::chang_p()
{
    bool ok;
    int a2=QInputDialog::getInt(this,"请输入节点开放的概率（0~100）%","概率",50,0,100,1,&ok);
    open_p=a2;
}

void MainWindow::about()
{
    QMessageBox::information(this, "关于我们", "作者:\n肖冉，华征宇 ");
}

void MainWindow::help()
{
    QMessageBox::information(this,"帮助","使用时有问题请联系我们");
}

void MainWindow::code_show()
{
    if(already_code==0){
       already_code=1;
       ui->toolButton->setText("隐藏代码");
       l1->setVisible(1);
       l1->setText(s_1[cond]);
    }
    else{
        already_code=0;
        ui->toolButton->setText("show_code");
        l1->setVisible(0);
    }
}
//通过按钮调用Union方法
void MainWindow::fun1()
{
  //  qDebug()<<sign_cnt;
    if(sign_cnt==0){
    p=sign;
    sign_cnt=1;
 //   qDebug()<<p<<" ";
    }
    else{
        q=sign;
        (uf->*uf->c_un[cond])(q,p);
        bool marked[30]={0};
        bool marked1[30][30];
        for(int i=0;i<30;i++)
            for(int j=0;j<30;j++)marked1[i][j]=0;
        int cnt=0;
        int x1=300,y1=50;
        int cnt1=0;
        for(int i=1;i<=a1;i++){
            if(i==uf->id[i])cnt1++;
        }
        int temp=1080/(cnt1)+1;
        for(int i=1;i<=a1;i++){
            if(i==uf->id[i]){
                marked[i]=1;
                point1[i].setX(x1);
                point1[i].setY(y1);
                x1+=temp;
            }
        }
        cnt+=cnt1;
        while(1){
            if(cnt==a1)break;
            for(int i=1;i<=a1;i++){
                if(marked[i])continue;
                if(marked[uf->id[i]]){
                    marked[i]=1;
                    cnt++;
                    for(int j=7;j<15;j--){
                        if(!marked1[uf->id[i]][j]){
                            marked1[uf->id[i]][j]=1;
                            point1[i].setX(point1[uf->id[i]].x()+(j-7)*30);
                            point1[i].setY(point1[uf->id[i]].y()+40);
                          //  qDebug()<<uf->id[i]<<" "<<point1[i].x()<<" "<<point1[i].y();
                          //  qDebug()<<i<<" "<<point1[i].x()<<" "<<point1[i].y();
                            break;
                        }
                        if(!marked1[uf->id[i]][14-j]){
                            marked1[uf->id[i]][14-j]=1;
                            point1[i].setX(point1[uf->id[i]].x()+(7-j)*30);
                            point1[i].setY(point1[uf->id[i]].y()+40);
                            break;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=a1;i++){
            v1[i].setGeometry(point1[i].x(),point1[i].y(),40,40);
        }
        update();
        sign_cnt=0;
      //  qDebug()<<p<<" "<<q;
    }
}

void MainWindow::fun2()
{
   /* int n=40;
    //qDebug()<<n;
    n1=n;
    maze1=new maze(n);
    uf1=new Union_find(n*n+100);
    */
    if(maze1==nullptr)return;
    int n=40;
   // qDebug()<<n;
    int walk[4][2]={0,1,0,-1,1,0,-1,0};
    for(int i=0;i<n1;i++)
        for(int j=0;j<n1;j++){
           // qDebug()<<maze1->map1[i][j];
            if(maze1->map1[i][j]==0)continue;
            for(int k=0;k<4;k++){
                int i1=i+walk[k][0];
                int j1=j+walk[k][1];
              //  qDebug()<<i1<<" "<<j1;
                if(i1<0||i1>=n1||j1<0||j1>=n1)continue;
                if(maze1->map1[i1][j1]==1){
                       uf1->union4(i*n+j+1,i1*n+j1+1);
                }
            }
       }
    for(int j=0;j<n;j++){
        if(maze1->map1[0][j]==1)uf1->union4(j+1,n*n+88);
    }
  //  qDebug()<<uf1->find4(n*n+88);
  /*  for(int j=0;j<n;j++){
        if(maze1->map1[n-1][j]==1)uf1->union4((n-1)*n+j+1,n*n+87);
    }
    */
   // qDebug()<<uf1->find4(n*n+87);
  //    qDebug()<<n;
         update();
         return;
}

