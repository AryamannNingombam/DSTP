#include <iostream>
#include <memory>
#include <vector>
#include <stack>

#include "../Graph.h"
#include "../Edge.h"

using namespace std;


class Graph: public BasicGraph{
public:
Graph(int s) : BasicGraph(s){};
// Undirected graph
bool cycleDetectionUndirected(){
    int temp;
    stack<int> s;
    vector<bool> visited(this->size,0);
    s.push(0);
    while (!s.empty()){
        temp = s.top();s.pop();
        for (const auto &i : this->v[temp]){
            if (visited[i])return true;
            visited[i] = 1;
            s.push(i);
        };
    };
    return false;

};
//Directed graph;
bool DFSHelper(int x, vector<bool> &visited,vector<bool> &currentVisited){
    if (!visited[x]){
        visited[x] = 1;
        currentVisited[x] = 1;
        for (auto i : this->v[x]){
            if (!visited[i] && DFSHelper(i,visited,currentVisited)){
                return true;
            }else if (currentVisited[i]){
                return true;
            }
        }


    };

    currentVisited[x] = 0;
    return false;

}



bool cycleDetectionDirected(){
    vector<bool> visited(this->size,0);
    vector<bool> currentVisited(this->size,0);

    for (int i{};i<this->size;i++){
        if (visited[i] || this->v[i].size()==0)continue;
        if (this->DFSHelper(i,visited,currentVisited))return true;
    }

    return false;
}



};

int main(){
    int size;
    cout << "Enter the number of elements in the graph : ";
    cin >> size; 
    auto ptr = make_unique<Graph>(size);
    char input;
    do{
        cout << "You have the following options : \n";
        cout << "\tA. Add an edge between two vertices\n";
        cout << "\tP. Print the graph structure\n";
        cout << "\tE. Add a new vertice to the graph\n";
        cout << "\tC. Check for cycle in the graph\n";
        cout << "\tQ. Quit\n";
        cout << "Enter your command : ";
        cin >> input;
        input = tolower(input);
        switch(input){
            case 'a':{
                int temp1,temp2;
                cout << "Enter the vertices : ";
                cin >> temp1 >> temp2;
                if (ptr->addEdge(temp1,temp2)){
                    cout << "Edge added!\n";
                    
                } else{
                    cout << "Error!\n";
                    cout << "Please check that you have entered the right values\n";
                };
                break;
            }
            case 'p':{
                    ptr->display();
                    break;
            }
            case 'e':{
                if (ptr->addVertice()){
                    cout << "Vertice added!\n";
                }else{
                    cout << "Error! Could not add a vertice!\n";
                };
                break;
            }
            case 'c':{
                cout << "Checking for cycle...\n";
                if (ptr->cycleDetectionDirected()){
                    cout << "Cycle detected!\n";

                }else{
                    cout << "Cycle not detected!\n";
                };
                break;
            }
            case 'q':{
                cout << "Thank you!\n";
                break;
            }


        }


    }while (input!='q');


    return 0;
}