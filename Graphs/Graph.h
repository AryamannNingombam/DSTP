#include <iostream>
#include <vector>




class BasicGraph{
    protected:
    using graphVec = std::vector<std::vector<int>>;
    int size;
    graphVec v;
    public:
    

    BasicGraph(int s){
        this->size =s;
        this->v.resize(s,{});
    };

    bool check(int a){
        if (a <0 || a>=this->size)return false;
        return true;
    }

    bool addVertice(){
        this->v.push_back({});
        this->size++;
        return true;
    };
    virtual bool addEdge(int a,int b){
        if (this->check(a) && this->check(b)){
            this->v[a].push_back(b);
            return true;
        };
        return false;


    };

    void display(){
        for (int i{};i<this->size;i++){
            if (this->v[i].size()==0)continue;
        std::cout << i<< ':';
            for (auto j : this->v[i]){
                std::cout << j << ' ';
            };
            std::cout << '\n';
        };
        
        return;
    }

    virtual ~BasicGraph(){}

};