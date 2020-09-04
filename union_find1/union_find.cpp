#include "union_find.h"
class quick_find{
public:
    quick_find(int n){
        for(int i=1;i<=n;i++)id[i]=i;
        count=n;
        amount=n;
    }
    int id[30];
    int count;
    int amount;
    void union1(int p,int q){
        int pid=id[p];
        int qid=id[q];
        if(pid!=qid){
            for(int i=1;i<=amount;i++)
                if(id[i]==qid)id[i]=pid;
         count--;
        }
    }
    bool connected(int p,int q){
        return id[p]==id[q];
    }
    int find(int p){
        return id[p];
    }
};
class quick_union{
public:
    quick_union(int n){
        for(int i=1;i<=n;i++)id[i]=i;
        count=n;
        amount=n;
    }
    int id[30];
    int count;
    int amount;
    void union1(int p,int q){
        int rp=find(p);
        int rq=find(q);
        if(rq!=rp){
            id[rq]=rp;
            count--;
        }

    }
    bool connected(int p,int q){
        return find(p)==find(q);
    }
    int find(int p){
        while(p!=id[p]){
            p=id[p];
        }
        return id[p];
    }
};
class Weighted_Quick_Union{
public:
    Weighted_Quick_Union(int n){
        for(int i=1;i<=n;i++){
            id[i]=i;
            sz[i]=1;
        }
        count=n;
        amount=n;
    }
    int id[30];
    int sz[30];
    int count;
    int amount;
    void union1(int p,int q){
        int rp=find(p);
        int rq=find(q);
        if(rq!=rp){
            if(sz[rq]>sz[rp]){id[rp]=rq;sz[rq]+=sz[rp];}
            else {id[rq]=rp,sz[rp]+=sz[rq];}
            count--;
        }
    }
    bool connected(int p,int q){
        return find(p)==find(q);
    }
    int find(int p){
        while(p!=id[p]){
            p=id[p];
        }
        return id[p];
    }
};
class WU_Quick_Union_with_path_Compresson{
    WU_Quick_Union_with_path_Compresson(int n){
        for(int i=1;i<=n;i++){
            id[i]=i;
            sz[i]=1;
        }
        count=n;
        amount=n;
    }
    int id[30];
    int sz[30];
    int count;
    int amount;
    void union1(int p,int q){
        int rp=find(p);
        int rq=find(q);
        if(rq!=rp){
            if(sz[rq]>sz[rp]){id[rp]=rq;sz[rq]+=sz[rp];}
            else {id[rq]=rp;sz[rp]+=sz[rq];}
            count--;
        }
    }
    bool connected(int p,int q){
        return find(p)==find(q);
    }
    int find(int p){
        if(p!=id[p]){
            id[p]=find(id[p]);
        }
        return id[p];
    }
};
