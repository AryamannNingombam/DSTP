#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <memory>
#include "../Edge.h"
#define INF INT_MAX



using namespace std;
class Edge;

using pr = pair<int,Edge>;

using vec = vector<Edge>;
using pairing = vector<pr>;







ostream &operator<<(ostream &os,const Edge &e){
    os <<e.second << ':' << e.weight;
    return os;
}

bool operator<(const Edge &lhs,const Edge &rhs){
    return lhs.weight < rhs.weight;
}
bool operator>(const Edge &lhs,const Edge &rhs){
    return lhs.weight > rhs.weight;
}

bool compare(const pr &p1,const pr &p2){
    return p1.second < p2.second;
}





 bool customCompare(const pr a1,const pr a2){
    return a1.second  > a2.second;
};
class Graph{
    protected:
    int size;
    vector<vec> v;
    vector<int> values;
    public:
    Graph(int n){
        this->size = n;
        this->v.resize(n);

    };
     bool addEdge(int first,int second,int weight)
{

    this->v[first].push_back(Edge(second,weight));
    return true;

};

void display(){
    for (int i{};i<this->size;i++){
        cout << i << "->";
        for (auto edges : this->v[i]){
            cout << edges << '|';
        };
        cout << '\n';
    };
    return;
};


//Main logic
vector<int> runAlgorithm(int first){
    //Making heap for extracting the edge having the least weight;
    pairing heap;
    //resizing the values vector for using if it was used earlier, this
    //vector is used to store the distances of the vertice 'first' from the other points;
    values.resize(this->size,INF);

    //the distance of the 'first' vertice would be zero from itself
    this->values[first ] = 0;
    
    for (auto i : this->v[first]){
        //pushing all the edges associated with vertice 'first' into the heap;
        heap.push_back({first,i});
        //setting the distance of the edges to the weight of the edge;
        // i.second is the second vertice
        //;i.weight is the weight of the edge;
        this->values[i.second] =i.weight;
        
    };

    //sorting the heap to extract the minimum value of the edge from the heap; sorted in 
    //descending order;
    sort(heap.begin(),heap.end(),customCompare);
    //run the loop while the heap is not empty;  
    while (!heap.empty()){


        
        
        //Getting the last element(smallest) from the heap;type-> {firstInt,Edge};
        auto temp = heap.back();heap.pop_back();
        

      
        //running a for loop for all the edges of the second vertice in the edge selected;
        //here temp.second.second would be the vertice index and temp.second.weight would
        //be the weight of the edge;
        //{firstIndex,Edge} // structure of the temp;
        for (auto i : this->v[temp.second.second]){
            //adding the weight of the second vertice to the edges of
            //the second vertice;
            i.weight += this->values[temp.second.second];
            //if the weight is lesser than the current stored weight
            //(more optimal path found);
            if (i.weight < this->values[i.second]){
                //updating the value of the weight to the more optimized one;
                //here i.second would be the second vertice of one of the edges associated
                //with the temp's second vertice;
                this->values[i.second]  = i.weight;
                //WE WOULD PUSH ONLY IF THE VALUE IS UPDATED;
                //or the while loop would never end;
                heap.push_back({temp.second.second,i});
            }
        };
        //sorting the value again for extracting the min value;
sort(heap.begin(),heap.end(),customCompare);
   
    }
    

    //returning the distances(optimal) of the inputted vertice from the other respective 
    //vertices;

    return this->values;






}









    
};










int main(){
    int c1,c2;
    int size,tempWeight;
    cout << "Enter the number of vertexes in the graph : ";
    cin >> size;
    auto ptr = make_unique<Graph>(size);
    char input;
    do{
        cout << "You have the following options : \n";
        cout << "\tA. Add an edge.\n";
        cout << "\tP. Print all the edges\n";
        cout << "\tS. Start the algorithm\n";
        cout << "\tQ. Quit\n";
        cout << "Enter the command : ";
        cin >> input;
        input= tolower(input);
        switch (input){
            case 'a':{
                cout << "Enter the edges and the weight of the edge : ";
                cin >> c1 >> c2 >> tempWeight;
                if (ptr->addEdge(c1,c2,tempWeight)){
                    cout << "Edge added!\n";

                }else{
                    cout << "Error!!\n";
                }
                
                break;
            }
            case 'p':{
                ptr->display();
                break;
            }
            case 's':{ 
                int temp;
                cout << "Enter the number : ";
                cin >> temp;
                vector<int> result = ptr->runAlgorithm(temp);
                for (int i{};i<size;i++){
                    cout << "Distance of " << i << " from " << temp << " : " << result[i] << '\n';
                };
                break;

          
            }
            case 'q':{
                break;
            }
            default:{
                cout << "INVALID!!\n";
                break;
            }
        }


    }while (input != 'q');
    cout << "Thank you!!\n";


    return 0;
}//a 0 1 10 a 1 3 5 a 3 0 3 a 1 2 7 a 0 7 7 a 7 4 5 a 7 6 4 a 2 5 4 a 5 4 3 a 5 6 5 a 6 4 2 a 4 2 6

//A 0 1 6 a 0 2 6 a 1 4 4 a 3 1 2 a 3 4 4 a 2 3 5 a 2 4 1 a 0 3 3