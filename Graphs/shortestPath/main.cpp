#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <queue>
#include <string>
#include <stack>

//Directed,weighted graph;

using namespace std;
//This vector would store the edges corresponding
// to the index of the edgeVector 
using intVector = vector<int>;
//eg. edgesVector[0] would contain all the edges 
//that would be directed from the vertice 0 to the
//other edges. This would only contain the
//edges starting from the index as this is a 
///directed graph;
using edgesVector = vector<intVector>;

//vector that would be used to check
//whether the given index has been 
// visited before during BFS;
using boolVector = vector<bool>;


//Queue that would be used when implementing BFS;
using BFSqueue = queue<int>;

//map to track the path of the whole traversal;
using pathsVisitedMap = unordered_map<int,int>;

//to display the track when it is found
using st = stack<int>;



class Graph{
    int size;
    edgesVector v;

    public:
    Graph(const int s){
        this->size = s;
        this->v.resize(s,{});
  
    };
    bool addVertice(){
        this->v.push_back({});
        this->size++;
        return true;
    }
    bool addEdge(const int a,const int b){
    //As we start from zero based indexing, if 
    // a or b exceeds the size, then the input
    //would be invalid, so return false indicating 
    // that the edge cannot be added;
    if (!this->exists(a) || !this->exists(b))return false;
    this->v[a].push_back(b);
    return true;



    };
    //function to check if the input is valid or not;
    bool exists(const int a){
        if (a < 0 || a>=this->size)return false;

        return true;
    }


    void display(){
        for (int i{};i<this->size;i++){
            if (this->v[i].size() == 0)continue;
            cout << i << "->";
            for (auto j : this->v[i]){
                cout << j << ' ';
            };

            cout << '\n';




        }

    return;

    };


    void search(const int start,const int end)
{
    if (!this->exists(start) || !this->exists(end)){
        cout << "You entered invalid inputs!\n";
        return;
    };
    BFSqueue exploringVertices;
    boolVector visitedCheck(this->size,false);
    pathsVisitedMap mapping;

    exploringVertices.push(start);
    mapping[start] = start;
    visitedCheck[start] = true;
    bool done = (start == end);
    //If exploring... is empty, it means that the path
    // was not find
    //on the contrary, if done is true,it
    //means that the path has been found and
    //we don't have to traverse any more;
    while (!exploringVertices.empty()  && !done){

        int current = exploringVertices.front();exploringVertices.pop();
        //storing all the edges directed from the 
        //current vertices in the variable -edges;
        auto edges = this->v[current];
        //looping through each connected 
        //vertice;
        for (auto edge : edges){
            


            //if this is not done, if a cycle is found,
            //the code would most probably get stuck
            //in an infinite loop;
            if (visitedCheck[edge])continue;
            
            visitedCheck[edge] = true;

            //This mapping is done to store the
            //path if the path is found;
            mapping[edge]  = current;
            exploringVertices.push(edge);

            //if we found the path;
            if (edge == end){
                    done = true;
                    break;
            }



        }
        };

    if (!done){
        cout << "Path not found!!!!\n";
        return;
    }else {
        ///CODE TO DISPLAY THE ANSWER TO THE 
        //USER HERE
        cout << "Found!\n";
        cout << "Printing the path...\n";
        int tempIncrement = end;
        st answer;
        while (mapping.at(tempIncrement) != tempIncrement){
            answer.push(tempIncrement);
            tempIncrement = mapping.at(tempIncrement);
        };
        cout << start << "->";
        int temp;
        while (!answer.empty()){

            temp = answer.top();answer.pop();
            if (answer.empty()){
                cout << temp << '\n';
            }else cout << temp << "->";
        }
        

    }
    return;

    }



};
//some testcases


//e 0 1 e 1 4 e 0 2 e 2 3 e 3 4 
//E 0 2 e 2 7 e 7 6 e 6 4 e 0 5 e 5 8 e 8 6 e 0 1 e 1 3 e 5 1 e 3 5 e 3 8 



int main(){
    int size;
    cout << "Enter the number of elements in the graph : ";
    cin >> size;
    
    auto ptr = make_unique<Graph>(size);

    char input;
    do{
        cout << "You have the following options : \n";
        cout << "\tP. Print the graph structure\n";
        cout << "\tE. Add an edge between two vertices\n";
        cout << "\tA. Add a new vertice\n";
        cout << "\tF. Find the shortest path\n";
        cout << "\t Q. Quit\n";


        cout << "Enter your command : ";
        cin >> input;
        input = tolower(input);

        switch(input){
            case 'p':{
                ptr->display();
                break;
            };
            case 'e':{
                int temp1,temp2;
                cout << "Enter the vertices : ";
                cin >> temp1 >> temp2;
                if (ptr->addEdge(temp1,temp2)){
                    cout << "Edge added!\n";
                }else{
                    cout << "Error! Please make sure that you have entered the right values!\n";
                };
                break;
            };
            case 'a':{
                if (ptr->addVertice()){
                    cout << "Added!\n";
                };
                break;
            };
            case 'f':{
                int temp1,temp2;
                cout << "Enter the two vertices : ";
                cin >> temp1 >> temp2;
                ptr->search(temp1,temp2);


                break;
            };
            case 'q':{
                cout << "Thank you!\n";
                break;
            }
            default:{
                cout << "Invalid input!\n";
                break;
            }



        }


    }while (input != 'q');



    return 0;
}


