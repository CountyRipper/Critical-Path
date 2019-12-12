#include "criticalpath.h"

int main(int, char**) {
    adjNet net;
    for(int i=1;i<=9;i++){
        net.InsetVex();
    }
    net.InsertEdge(1,2,6);
    net.InsertEdge(1,3,4);
    net.InsertEdge(1,4,5);
    net.InsertEdge(2,5,1);
    net.InsertEdge(3,5,1);
    net.InsertEdge(4,6,2);
    net.InsertEdge(5,7,9);
    net.InsertEdge(5,8,7);
    net.InsertEdge(6,8,4);
    net.InsertEdge(7,9,2);
    net.InsertEdge(8,9,4);
    Criticalpath(net);
    std::cout<<std::endl;
    std::cin.get();
    return 0;
}
