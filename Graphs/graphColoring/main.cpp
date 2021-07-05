#include <iostream>
#include "../Edge.h"
#include "../Graph.h"
#include <vector>
#include <memory>
#include <queue>
#include <string>

using namespace std;
using intVector = vector<int>;
class Graph : public BasicGraph{
public:
Graph(int size) : BasicGraph{size}{};

bool checkBipartite(){
queue<int> q;
for (int i{};i<this->size;i++){
    if (this->v[i].size()==0)continue;
    q.push(i);
    break;
}
bool isRed = true;
vector<string> storage(this->size);
int temp;
while (!q.empty()){
    temp = q.front();q.pop();
    storage[temp] = ((isRed) ? "RED" : "BLUE");
    for (auto i : this->v[temp]){
    if (storage[i]==""){
        storage[i] = ((!isRed) ? "RED" : "BLUE");
        q.push(i);
     }else{
         if (storage[i] == storage[temp])return false;
     };

    }

    isRed = !isRed;
};


return true;

};

bool addEdge(int a,int b){
    if (this->check(a) && this->check(b)){
        this->v[a].push_back(b);
        this->v[b].push_back(a);
        return true;
    }
    return false;
}


};


int main(){
    int size;
    cout << "Enter the number of elements in the graph : ";
    cin >> size;
    char input;
    auto ptr = make_unique<Graph>(size);
    do{
        cout << "You have the following commands available : \n";
        cout << "\tA. Add an edge between two vertices.\n";
        cout << "\tV. Add a new vertice in the graph.\n";
        cout << "\tB. Check for bipartite in the graph.\n";
        cout << "\tP. Print the graph structure.\n";
        cout << "\tQ. Quit the program.\n";
        cout << "Enter your input : ";
        cin >> input;
        input = tolower(input);
        switch (input){
            case 'a':{
                int temp1,temp2;
                cout << "Enter the two vertices : ";
                cin >> temp1 >> temp2;
                if (ptr->addEdge(temp1,temp2)){
                    cout << "Vertice added!\n";
                }else{
                    
                    cout << "Error! Please check that you have the right inputs entered!\n";
                
                };
                break;
            }
            case 'v':{
            if (ptr->addVertice()){
                cout << "Vertice added!\n";
            }else{
                cout << "There was an error! Sorry!";
            };


                break;
            }
            case 'b':{
                if (ptr->checkBipartite()){
                    cout << "Bipartatite!\n";
                }else{
                    cout << "No Bipartatite!\n";
                };
                break;
            }
            case 'q':{
                cout << "Thank you!\n";
                break;
            }
            case 'p':{
                ptr->display();
                break;
            }
            default:{
                cout << "INVALID!\n";
                break;
            }


        }; 




    }while (input!='q');



    return 0;


}

