#include <iostream>
#include <vector>
#include <memory>


using namespace std;
using vec = vector<int>;
class DisjointSet;
using ptr = unique_ptr<DisjointSet>;



ostream &operator<<(ostream &os,const vec &v){
    for (int i{};i<static_cast<int>(v.size());i++){
        os << i << " : " << v[i] << '\n'; 
         
    };
    return os;


}


class DisjointSet{
    private:
    vec v;
    int size;
    public:
    DisjointSet(int s){
        this->v.resize(s,-1);
        size = s;

    };
    bool changeValue(int index,int value){
        if (index < this->v.size() && index>=0){
            this->v[index] = value;
            return true;
            };
        return false;
    };

    int find(int index){
        if (this->v[index] == -1)return index;
        this->v[index] = find(this->v[index]);
        return v[index];
    };
    
    bool setValues(){
        for (int i{};i<this->size;i++){
            cin >> this->v[i];
        };
        return true;
    };

    vec getV(){
        return this->v;
    }

    ~DisjointSet(){
        cout << "Destructor called!\n";
    };

    void printPath(int index){
        if (this->v[index] < 0){
            cout << "Root : " << index << '\n';
            return;
        }
        cout << index << '\n';
        printPath(this->v[index]);
    };

    bool makeUnion(int index1,int index2){
        if (index1 < this->size && index2 < this->size){
            this->v[index1] = index2;
            return true;
            };
            return false;

    }



};


int main(){
    int size;
    cout << "Enter the size of the disjoint set : ";
    cin >> size;
    ptr p = make_unique<DisjointSet>(size);
    cout << "Enter the elements  : ";
    p->setValues();
    int num;
    cout << "Enter the number to traverse  the path : ";
    cin >>num;
    p->printPath(num);
    p->find(num);
    cout << p->getV();




    return 0;
}