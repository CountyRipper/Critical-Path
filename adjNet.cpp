#include "adjNet.h"
//构造函数:根据老师所给图生成相应网
adjNet::adjNet(){
    for(int i=0;i<9;i++){
        adjlist.push_back(adjNode(i));
    }
    //adjlist[0].nextedgeNode=new edgeNode(2,6,);
}
void adjNet::InsertEdge(int v1,int v2,int w){
    edgeNode *n=adjlist[v1-1].nextedgeNode;
    while(n!=NULL){
        n=n->nextedgeNode;
    }//到末尾退出
    n->nextedgeNode=new edgeNode(v2,w);//添置新节点
}