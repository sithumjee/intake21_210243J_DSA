#include <iostream>
using namespace std;


int main() {
    int vertices=6;
    int graph[6][6] = { { 0, 3, 0, 0, 0, 1 },
                        { 3, 0, 2, 1, 10, 0 },
                        { 0, 2, 0, 3, 0, 5 },
                        { 0, 1, 3, 0, 5, 0 },
                        { 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0 } };

    int selected[6];
    int edges = 0;

    for (int i = 0; i < vertices; i++)
        selected[i] = false;

    // Mark the first vertex as selected
    selected[0] = true;

    cout << "Edge      Weight" << endl;

    while (edges < vertices - 1) {
        int Minimum_Weight = 100000;
        int x = 0;
        int y = 0;

        for (int i = 0; i < vertices; i++) {
            if (selected[i]) {
                for (int j = 0; j < vertices; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (Minimum_Weight > graph[i][j]) {
                            Minimum_Weight = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " <--> " << y << " : " << graph[x][y] <<endl;
        selected[y] = true;
        edges++;
    }

    return 0;
}


