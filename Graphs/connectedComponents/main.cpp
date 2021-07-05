#include <iostream>
#include "../Edge.h"
#include <vector>
#include "../Graph.h"
#include <memory>


using namespace std;


class Graph : public BasicGraph{
    public:
    Graph(int s):BasicGraph(s){};

    void countConnectedComponentsHelper(int first,vector<bool>&visited){
        for (auto i : this->v[first]){
            if (visited[i])continue;

            visited[i] = true;
            this->countConnectedComponentsHelper(i,visited);
        };


    }

    int countConnectedComponents(){
        vector<bool> visited(this->size,0);
        int counter = 0;
        for (int i{};i<this->size;i++){
            
            if (!visited[i]){
                this->countConnectedComponentsHelper(i,visited);
                printf("Counting for : %d\n",i);
                ++counter;
            };
            visited[i] = 1;
            
        }

        


        return counter;
    }

    virtual bool addEdge(int a,int b){
        if (this->check(a) && this->check(b)){
            this->v[a].push_back(b);
            this->v[b].push_back(a);
            return true;
        };
        return false;
    };

virtual ~Graph(){}

};





int main(){
    int size;
    cout << "Enter the number of vertices in the graph : ";
    cin >> size;
    
    auto ptr = make_unique<Graph>(size);
    char input;
    do {
        cout << "You have the following options  : \n";
        cout << "\tA. Add an edge to the graph\n";
        cout << "\tP. Print the graph structure\n";
        cout << "\tV. Add a new vertice to the graph\n";
        cout << "\tC. Count the connected components in the graph\n";
        cout << "\tQ. Quit the program\n";
        cout << "Enter your command : ";
        cin >> input;
        input = tolower(input);
        switch(input)
{
        case 'a':{
            int temp1,temp2;
            cout << "Enter the vertices : ";
            cin >>temp1 >> temp2;
            if (ptr->addEdge(temp1,temp2)){
                cout << "Edge added!\n";
            }else{
                cout << "Error!\n";
            }
            break;
        }
        case 'p':{
            ptr->display();
            break;
        }
        case 'v':{
            if (ptr->addVertice()){
                cout << "New vertice added!\n";
            }else{
                cout << "Error!\n";
            }
            break;
        }
        case 'c':{
            int result = ptr->countConnectedComponents();
            printf("Number of connected components : %d\n",result);
            break;

        }
        case 'q':{
                cout << "Thank you!\n";
                break;
        }




}

    }while (input != 'q');


    return 0;
}

