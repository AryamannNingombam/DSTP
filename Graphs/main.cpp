#include <iostream>
#include <vector>
#include <memory>
#include <queue>

using namespace std;

using vec = vector<int>;
using qu = queue<int>;





//Not weighted graphs (Edges contain no value);
//For weighted just use pair<int,int> and
//store in the vector;
class AdjacencyList{


//Vector inside vector stores all the points where the index points
protected:

vector<vec> v;
int size;
vector<bool> visited;
qu bfsQueue;



public:

AdjacencyList(const int s){
    this->v.resize(s,{});
    this->size = s;
    this->visited.resize(size,false);
}

virtual bool addVertex(){
    this->v.push_back({});
    this->size++;
    return true;
};

virtual bool addEdge(int first,int second){
    if (first>=this->size || second>=this->size)return false;
    this->v[first].push_back(second);
    return true;


}
void display(){
cout << "+++++++++++++++\n";
for (int i{};i<this->size;i++){
    cout << i << " -> ";
for (int j : this->v[i]){
cout << j << ' ';

}
cout << '\n';
};
cout << "+++++++++++++++\n";

return;


};

void DFS(int index){
    if (this->v[index].size() == 0){
        cout << index << "->DONE\n";

        return;
    };
    if (this->visited[index]){
        cout << "DONE\n";
        return;
    };

    this->visited[index] = true;
    for (auto i : this->v[index]){
        cout << index << "->";
        DFS(i);
    };



}


void BFS(int index,bool firstTime = true){
if (firstTime){
    // cout << index  << "->DONE\n";
    this->bfsQueue.push(index);
    this->visited[index] = true;
};

while (!bfsQueue.empty()){
    int s = this->bfsQueue.front();this->bfsQueue.pop();
    for (auto i : this->v[s]){
        if (this->visited[i])continue;
        this->visited[i]= true;
        this->bfsQueue.push(i);
        printf("Reached point  : %i\n",i);


    };


};


};






virtual ~AdjacencyList(){
    cout << "Destructor called!\n";
}




};




class AdjacencyMatrix : public AdjacencyList{
    private:
    int size;
    vector<vector<bool>> edgeMatrix;
    


    public:
    AdjacencyMatrix(int size) : AdjacencyList(size){
        this->edgeMatrix.resize(size,vector<bool>(size,0));
        
    };
    void displayEdgeM(){
        for (auto i : this->edgeMatrix){
            for (auto j : i){
                cout << j << ' ';
            };
            cout << '\n';
        };
        return;
    };

    virtual bool addEdge(int first,int second){
        if (AdjacencyList::addEdge(first,second)){
            this->edgeMatrix[first][second]= true;
            return true;
        };

        return false;

    };

    virtual bool addVertex(){
        if (AdjacencyList::addVertex()){
            this->edgeMatrix.push_back(vector<bool>(this->size,false));
            for (auto i : this->edgeMatrix){
                i.push_back(false);
            };
            return true;
        };

        return false;
    }

    


virtual ~AdjacencyMatrix(){}

};











int main(){
    int size;
    cout << "Enter the number of vertices in the graph : ";
    cin >> size;
  
    unique_ptr<AdjacencyMatrix> ptr = make_unique<AdjacencyMatrix>(size);
   
    char input;
    do{
        cout << "Command options :\n";
        cout << "Q. Quit\n";
        cout << "P. Print the list\n";
        cout << "A. Add a vertex\n";
        cout << "M. Print the matrix\n";
        cout << "E. Add the edge\n";
        cout << "D. Implement DFS\n";
        cout << "B. Implement BFS\n";

        cout << "Enter the command : ";
        cin >> input;
        input = tolower(input);

        switch (input){
            case 'p':{
                ptr->display();
                break;
            };
            case 'e':{
                int num1,num2;
                cout << "Enter the numbers to add an edge between : ";
                cin >> num1 >> num2;
                if (ptr->addEdge(num1,num2)){
                    cout << "Added!\n";
                }else {
                    cout << "Error!\n";
                };
                break;
            };
            case 'a':{
                ptr->addVertex();
                cout << "Added!\n";
            };
            case 'm':{
                ptr->displayEdgeM();
                break;
            };
            case 'q':{
                cout << "Thank you!\n";
                break;
            };
            case 'd':{
                int num;
                cout << "Enter the number : ";
                cin >> num;
                ptr->DFS(num);
                break;
            };
            case 'b':{
                int num;
                cout << "Enter the number : ";
                cin >> num;
                ptr->BFS(num);
                break;
            }
       

            default:{
                cout << "Invalid!\n";
                break;
            }

        }


    }while (input!='q');





    return 0;
}


/*

*/