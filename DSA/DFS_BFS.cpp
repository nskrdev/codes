
// Breadth First Search and Depth First Search
#include <iostream>
using namespace std;

const int MAX_VERTICES = 10;

class Graph {
private:
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
    int numVertices;

public:
    Graph(int vertices) {
        numVertices = vertices;
        for (int i = 0; i < MAX_VERTICES; ++i)
            for (int j = 0; j < MAX_VERTICES; ++j)
                adj[i][j] = 0;
    }

    void addEdge(int src, int dest) {
        adj[src][dest] = 1;
        // For undirected graph, uncomment:
        // adj[dest][src] = 1;
    }

    void bfs(int start) {
        bool visited[MAX_VERTICES] = {false};
        int queue[MAX_VERTICES];
        int front = -1, rear = -1;

        visited[start] = true;
        queue[++rear] = start;

        cout << "BFS Traversal: ";
        while (front < rear) {
            int current = queue[++front];
            cout << current << " ";

            for (int i = 0; i < numVertices; ++i) {
                if ((adj[current][i]!=0) && (visited[i]==false)) {
                    visited[i] = true;
                    queue[++rear] = i;
                }
            }
        }
        cout << endl;
    }

    void dfs(int start) {
        bool visited[MAX_VERTICES] = {false};
        int stack[MAX_VERTICES];
        int top = -1;

        stack[++top] = start;

        cout << "DFS Traversal: ";
        while (top != -1) {
            int current = stack[top--];

            if (visited[current]==false) {
                visited[current] = true;
                cout << current << " ";

                // Push adjacent vertices in reverse order
                // so that the lowest-numbered ones are processed first
                for (int i = 0; i<=numVertices - 1; ++i) {
                    if ((adj[current][i]!=0) && (visited[i]==false)) {
                        stack[++top] = i;
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int choice;
    Graph g(6); // Graph with 6 vertices (0 to 5)

    // Add edges (including cycles)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 0); // cycle
    g.addEdge(3, 1); // cycle
    g.addEdge(5, 2); // cycle

    cout << "Choose traversal method:\n";
    cout << "1. Breadth-First Search (BFS)\n";
    cout << "2. Depth-First Search (DFS)\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        g.bfs(0);
    } else if (choice == 2) {
        g.dfs(0);
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
