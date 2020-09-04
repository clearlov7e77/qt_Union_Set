#ifndef MAZE_H
#define MAZE_H
#include<QPushButton>
#include<random>
#include<QString>
extern int open_p;
extern QString  s_1[5];
class maze
{
public:
    maze(int n){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                int temp=rand()%100+1;
                if(temp<=open_p)map1[i][j]=1;
                else map1[i][j]=0;
            }
    }
    ~maze();
    bool map1[60][60];
};

#endif // VERTEX_H
