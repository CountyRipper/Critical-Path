#include "adjNet.h"

void statIndegree(adjNet &net,int *indegree);//统计各个节点的入度

int Criticalpath(adjNet &net);//输出关键活动，成功返回1，失败返回-1