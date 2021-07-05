#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <memory>


using namespace std;
using intVector = vector<int>;
using mapOfAllEdges = map<int,intVector>;
using boolVector = vector<bool>;
using stackForDFS = stack<int>;



class Graph{
    int size;
    mapOfAllEdges m;
    stackForDFS storage;
    boolVector visited;


    public:
    Graph(const int s){
        this->size = s;
        for (int i{};i<s;i++){
            this->m[i] = {};
        };
        
    };
    bool checkVerticeValidity(const int &a){
        if (a < 0 || a >= this->size)return false;
        return true;
    };

    bool addVertice(){
        this->size++;
        this->m[this->size - 1] = {};
        return true;
    };

    bool addEdge(const int &a,const int &b){
        if (this->checkVerticeValidity(a)  && this->checkVerticeValidity(b)){
            this->m[a].push_back(b);
            return true;
        };
        return false;
    };
    void display(){
        for (const auto &i : this->m){
            cout << i.first << "->";
            for (const auto &j : i.second){
                cout << j << ' ';

            };
            cout << '\n';
        };


        return;
    };
    void topologicalSortingHelper(const int i,stackForDFS &result){
       
            this->visited[i] = true;

            for (auto vertex : this->m[i]){
                if (!this->visited[vertex])topologicalSortingHelper(vertex,result);
            };
            result.push(i);

    };
    void topologicalSorting(stackForDFS &result){
        this->visited.resize(this->size,0);

        for (int i{};i<this->size;i++){
            if (!this->visited[i]){
                this->topologicalSortingHelper(i,result);
            }
        }
    }
    





};


int main(){
int size;
cout << "Enter the size of the graph : ";
cin >> size;
auto ptr = make_unique<Graph>(size);
char input;

do{
    cout << "You have the following options\n";
        cout << "\t P. Print the graph edge list.\n";
        cout << "\t V. Add a new vertex to the graph.\n";
        cout << "\t A. Add a new edge between two vertexes.\n";
        cout << "\t T. Start topological sorting.\n";
        cout << "\t Q. Quit.\n";
        cout << "Enter your command : ";
        cin >> input;
        input = tolower(input);
        switch(input){
            case 'p':{
                ptr->display();


                break;
            };
            case 'v':{
                if (ptr->addVertice()){
                    cout << "Vertice successfully added!\n";
                }else{
                    cout << "Error!\n";
                }
                break;
            };
            case 'a':{
                int temp1,temp2;
                cin >> temp1 >> temp2;
                if (ptr->addEdge(temp1,temp2)){
                    cout << "Edge added!\n";
                }else{
                    cout << "Error! Please make sure that you have entered the right values!\n";
                };

                break;
            };
            case 't':{
                stackForDFS s;
               ptr->topologicalSorting(s);
                int temp;
                while (!s.empty()){
                    temp = s.top();s.pop();
                    cout << temp << ' ';
                };
                cout << '\n';

                break;
            };
            case 'q':{
                cout << "Thank you!\n";
                break;
            };
            default:{
                cout << "Invalid Input!\n";
                break;
            }
        }



}while (input != 'q');

//A 5 0 a 5 2 a 2 1 a 1 3 a 4 3 a 4 0


    return 0;
}
