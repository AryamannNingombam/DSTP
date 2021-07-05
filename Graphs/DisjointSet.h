#include <iostream>
#include <vector>

using namespace std;





class DisjointSet{
protected:
friend class Graph;
vector<int>v;
const int size = 26;
public:
DisjointSet(){

    for (int i{};i<this->size;i++){
        this->v.push_back(-1);
    }

};
   int find(int index){
        if (this->v[index] < 0)return index;
        this->v[index] = find(this->v[index]);
        return v[index];
    };

bool clearSet(){
    this->v.clear();
    for (int i{};i<this->size;i++){
        this->v.push_back(-1);
    }
    return true;
}

bool U( char c1, char c2){

    c1 = toupper(c1);
    c2 = toupper(c2);
    if (this->find(c1 - 'A') != this->find(c2 - 'A')){
        this->v[c1 - 'A'] = c2 - 'A';
    }


    return true;

};








};
