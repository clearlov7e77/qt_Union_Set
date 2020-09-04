#ifndef QUICK_UNION_H
#define QUICK_UNION_H
class Union_find
{
public:
    int id[4000];
    int count;
    int amount;
    int sz[4000];
    typedef void(Union_find::*un) (int,int);
    typedef bool(Union_find::*conn)(int,int);
    un c_un[4]={&Union_find::union1,&Union_find::union2,&Union_find::union3,&Union_find::union4};
    conn c_conn[4]={&Union_find::connected1,&Union_find::connected2,&Union_find::connected3,&Union_find::connected4};
    Union_find(int n){
            for(int i=0;i<=3000;i++){
                id[i]=i;
                sz[i]=1;
            }
            count=n;
            amount=n;
    }
    ~Union_find();
    void union1(int p,int q){
        int pid=id[p];
        int qid=id[q];
        if(pid!=qid){
            for(int i=1;i<=amount;i++)
                if(id[i]==qid)id[i]=pid;
         count--;
        }
    }
    bool connected1(int p,int q){
        return id[p]==id[q];
    }
    int find1(int p){
        return id[p];
    }
    void union2(int p,int q){
        int rp=find2(p);
        int rq=find2(q);
        if(rq!=rp){
            id[rq]=rp;
            count--;
        }

    }
    bool connected2(int p,int q){
        return find2(p)==find2(q);
    }
    int find2(int p){
        while(p!=id[p]){
            p=id[p];
        }
        return id[p];
    }
    void union3(int p,int q){
        int rp=find3(p);
        int rq=find3(q);
        if(rq!=rp){
            if(sz[rq]>sz[rp]){id[rp]=rq;sz[rq]+=sz[rp];}
            else {id[rq]=rp;sz[rp]+=sz[rq];}
            count--;
        }
    }
    bool connected3(int p,int q){
        return find3(p)==find3(q);
    }
    int find3(int p){
        while(p!=id[p]){
            p=id[p];
        }
        return id[p];
    }
    void union4(int p,int q){
        int rp=find4(p);
        int rq=find4(q);
        if(rq!=rp){
            if(sz[rq]>sz[rp]){id[rp]=rq;sz[rq]+=sz[rp];}
            else {id[rq]=rp;sz[rp]+=sz[rq];}
            count--;
        }
    }
    bool connected4(int p,int q){
        return find4(p)==find4(q);
    }
    int find4(int p){
        if(p!=id[p]){
            id[p]=find4(id[p]);
        }
        return id[p];
    }
};

#endif // QUICK_UNION_H
