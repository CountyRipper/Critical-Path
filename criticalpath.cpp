#include "criticalpath.h"
#include <queue>
#include <stack>

void statIndegree(adjNet &net,int *indegree){
    for(int v=0;v<net.GetVexNum();v++){
        indegree[v]=0;//初始化入度队列组
    }
    for(int v1=1;v1<net.GetVexNum();v1++){
        //遍历网的顶点
        for(int v2=net.FirstAdjVex(v1);v2!=-1;v2=net.NextAdjVex(v1,v2)){
            //v2为v1的一个邻接点
            indegree[v2]++;
        }
    }
}

int CriticalPath(adjNet &net){
    //初始：存在有向网络
    //如果net无回路，输出net的关键活动，并且返回1，否则返回-1
    
    int *indegree = new int[net.GetVexNum()];//顶点入度数组
    int *ve = new int[net.GetVexNum()];//事件最早发生时刻数组
    std::queue<int>q;//存储入度为0的顶点
    std::stack<int>s;//用于实现拓扑排序的栈
    int ee,el,u,v,count=0;
    for(v=0;v<net.GetVexNum();v++){
        ve[v]=0;
    }
    statIndegree(net,indegree);//统计入度

    for(v=1;v<net.GetVexNum();v++){
        //遍历顶点
        if(indegree[v]==0){
            //建立入度为0的顶点队列
            q.push(v);
        }
    }
    while(!q.empty()){
        //队列非空
        u=q.front();//获取第一个数
        q.pop();
        s.push(u);
        count++;//对顶点进行计数
        for(v=net.FirstAdjVex(u);v!=-1;v=net.NextAdjVex(u,v)){
            //v为u的一个邻接点，对v每个入度减一
            if(--indegree[v]==0){
                q.push(v);
            }
            if(ve[u]+net.GetWeight(u,v)>ve[v]){
                //修改ve[v]
                ve[v]=ve[u]+net.GetWeight(u,v);
            }
        }
    }
    delete []indegree;
    if(count<net.GetVexNum()-1){

        delete[]ve;
        return -1;//有回路
    }
    int *vl =new int[net.GetVexNum()];//事件最迟发生时刻数组
    u=s.top();//取出栈顶元素，u为汇点
    for(v=0;v<net.GetVexNum();v++){
        vl[v]=ve[u];
    }
    while(!s.empty()){
        //当栈非空
        u=s.top();
        s.pop();
        for(v=net.FirstAdjVex(u);v!=-1;v=net.NextAdjVex(u,v)){
            if(vl[v]-net.GetWeight(u,v)<vl[u]){
                //修改vl[u]
                vl[u]=vl[v]-net.GetWeight(u,v);
            }
        }
    }
    for(int u=1;u<net.GetVexNum();u++){
        //求ee，el和关键路径
        for(v=net.FirstAdjVex(u);v!=-1;v=net.NextAdjVex(u,v)){
            //v为u的一个邻接点
            ee=ve[u];el=vl[v]-net.GetWeight(u,v);
            if(ee==el){
                //<u,v>为关键活动
                std::cout<<"<v"<<u<<","<<"v"<<v<<">";
            }
        }
    }
    delete []ve;
    delete []vl;
    return 1;
}