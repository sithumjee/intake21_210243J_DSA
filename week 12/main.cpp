#include <iostream>
#include<list>
#include<vector>
#include <queue>
using namespace std;



void dijkstrasAlgorithm(int src, vector<vector<int>> graph , int nodes){
    vector<int> dist(nodes, INT_MAX); //distances from the source to each city
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> min_heap; //to track the next visiting neighbour
    vector<bool> visited(nodes, false);
    min_heap.emplace(0, src);


    while (!min_heap.empty()){
        int u = min_heap.top().second;
        visited[u] = true;
        min_heap.pop();
        int weight_v;
        for(int v=0; v < nodes; v++){
            if(graph[u][v] != 0 && (!visited[v])){ //travelling to each city from the current city if they aren't visited
                weight_v= graph[u][v];
                if(dist[u] != INT_MAX && dist[u] + weight_v < dist[v]){
                    dist[v] = dist[u] + weight_v;
                    min_heap.emplace(dist[v], v);
                }
            }


        }
    }
    //display the  shortest distances
    cout << "From city " << src << " shortest distances are:" << endl;
    for(int i=0; i < 6; i++){
        if(i != src){
            cout << i << "--> " << dist[i] << endl;
        }

    }
    cout<<endl;

}



int main() {

    int cities = 6;
    vector<vector<int>> matrix = {
            {0,  10, 0,  0,  15, 5},
            {10, 0,  10, 30, 0,  0},
            {0,  10, 0,  12, 5,  0},
            {0,  30, 12, 0,  0,  20},
            {15, 0,  5,  0,  0,  0},
            {5,  0,  0,  20, 0,  0}
    };

    dijkstrasAlgorithm(0, matrix, cities);
    dijkstrasAlgorithm(1, matrix, cities);
    dijkstrasAlgorithm(2, matrix, cities);
    dijkstrasAlgorithm(3, matrix, cities);
    dijkstrasAlgorithm(4, matrix, cities);
    dijkstrasAlgorithm(5, matrix, cities);

}