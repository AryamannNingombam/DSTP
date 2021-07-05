#include <iostream>


using namespace std;







class Edge{
    protected:
    friend bool operator<(const Edge &lhs,const Edge &rhs);
    friend bool operator>(const Edge &lhs,const Edge &rhs);
    friend ostream &operator<<(ostream &os,const Edge &e);
    friend class Graph;


        int second;
        int weight;
    public:
    Edge(int s,int w):second{s},weight{w}{

    };
 





};