#include <iostream>
#include <queue>
#include <vector>
#include <memory>
#include "../DisjointSet.h"
#include "../Edge.h"
//Test case'
// a a d 17 a g h 16 a a f 16 a d b 15 a b c 15 a d c 13 a f e 12 a c e 11 a e h 10 a e g 9 a d f 9 a d e 8 a c h 5 a f g 4 a a b 2


using namespace std;
class Edge;
using vec = vector<vector<Edge>>;
using pr = pair<char,Edge>;
using pairing = vector<pr>;




ostream &operator<<(ostream &os,const Edge &e){
    os <<e.second << ':' << e.weight;
    return os;
}



bool compare( pr &a,const pr &b){
    return a.second < b.second;
};






class Graph{
private:
int size;
vec v;
pairing p;
pairing krushkalResult;
DisjointSet s = DisjointSet();


public:
Graph(int s_)
{   
    this->size = s_;
    this->v.resize(s_,{});

   
    cout << "Graph initialized!\n";

};

 bool addEdge(char first,char second,int weight)
{
    this->v[toupper(first) - 'A'].push_back(Edge(toupper(second),weight));
    this->v[toupper(second) - 'A'].push_back(Edge(toupper(first),weight));
    this->p.push_back({toupper(first),Edge(toupper(second),weight)});
    return true;

};

void display(){
    for (int i{};i<this->size;i++){
        if (this->v[i].size() == 0)continue;
        cout << char(i + 65) << "->";
        for (auto j : this->v[i]){
            cout << j <<'|';
        };
        cout << '\n';
    };
};



pairing krushkal(){
    if (!this->krushkalResult.empty())return this->krushkalResult;
    sort(this->p.begin(),this->p.end(),compare);
    


    for (auto i : this->p){
        if (this->s.find(i.first - 'A') == this->s.find(i.second.second - 'A'))continue;
        this->s.U(i.first,i.second.second);
        this->krushkalResult.push_back(i);
        
      

    };
    this->s.clearSet();

    return this->krushkalResult;



};







};









int main(){
    auto ptr = make_unique<Graph>(26);
    char input,tempChar,tempChar2;
    int tempInt;

    do {
        cout << "\tYour command options : \n";
        cout << "\tQ. Quit.\n";
        cout << "\tA. Add Edge.\n";
        cout << "\tP. Print the graph structure.\n";
        cout << "\tK. Apply Krushkal's algorithm.\n";
        cout << "Enter your input : ";
        cin >> input;
        input = toupper(input);
        cout << "||||||||||||||||||||||||||||||||||||||||||||\n";
        switch (input){
            case 'Q':{break;}
            case 'A':{
                cout << "Enter the first and second char and enter the weight : ";
                cin >> tempChar >> tempChar2 >> tempInt;
                if (ptr->addEdge(tempChar,tempChar2,tempInt)){
                    cout << "Added!\n";
                };
                break;
            }
            case 'P':{
                ptr->display();

                break;
            }
            case 'K':{
                auto result = ptr->krushkal();
                cout << "Printing MSP\n";
                for (auto i: result){
                    cout << i.first << "|" << i.second << '\n';
                };
                break;
            }


            default:{
            cout << "INVALID!\n";
            break;
            }
        }
        cout << "||||||||||||||||||||||||||||||||||||||||||||\n";


    }while (input!='Q');

    cout << "Thank you!\n";



    return 0;
}