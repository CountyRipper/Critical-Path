#include "adjNet.h"
//构造函数:根据老师所给图生成相应网
adjNet::adjNet(){
    adjlist.push_back(adjNode());
    //adjlist[0].nextedgeNode=new edgeNode(2,6,);
}
int adjNet::InsertEdge(int v1,int v2,int w){
    int num=adjlist.size();
    if(v1>num||v2>num){
        return -1;
    }
    if(adjlist[v1].nextedgeNode==nullptr){
        adjlist[v1].nextedgeNode = new edgeNode(v2,w,nullptr);
    }
    else{
        edgeNode* n = adjlist[v1].nextedgeNode;
        while(n->nextedgeNode!=nullptr){
            n=n->nextedgeNode;
        }//到末尾退出
        n->nextedgeNode = new edgeNode(v2,w,nullptr);//添置新节点
    //n->nextedgeNode = new edgeNode(v2+1,w,nullptr);
    }
    //std::cout<<adjlist[v1].nextedgeNode->adjnum;
    return 1;
}

//添加顶点vex
void adjNet::InsetVex(){
    int n=adjlist.size();
    adjNode *a1= new adjNode(n);
    adjlist.push_back((*a1));
}
//获得结点数
int adjNet::GetVexNum(){
    return adjlist.size();
} 

//返回第一个邻接结点
int adjNet::FirstAdjVex(int v1){
    if(adjlist[v1].nextedgeNode!=nullptr){
        return adjlist[v1].nextedgeNode->adjnum;
    }
    else{
        return -1;
    }
}

//返回v1到v2的邻接点
int adjNet::NextAdjVex(int v1,int v2){
    bool tag=true;
    edgeNode* n;
    for(n=adjlist[v1].nextedgeNode;n!=nullptr;n=n->nextedgeNode){
        if(n->adjnum==v2) break;
    }
    n=n->nextedgeNode;
    if(n==nullptr) tag=false;
    if(tag){
        return n->adjnum;
    }
    else{
        return -1;
    }
}

int adjNet::GetWeight(int v1,int v2){
    edgeNode* n=adjlist[v1].nextedgeNode;
    while(n!=nullptr){
        if(n->adjnum==v2)break;
        n=n->nextedgeNode;
    }
    if(n){
        return n->weight;
    }
    else{
        return 0;
    }
}

adjNet::~adjNet(){
    Destroy();
}
