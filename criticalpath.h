#ifndef _CRITICALPATH_H_
#define _CRITICALPATH_H_

#include "adjNet.h"
#include <queue>
#include <stack>
void statIndegree(adjNet& net,int *indegree);//统计各个节点的入度

int Criticalpath(adjNet& net);//输出关键活动，成功返回1，失败返回-1

#endif