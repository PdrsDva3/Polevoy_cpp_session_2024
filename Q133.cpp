#include <iostream>
#include <vector>
#include <list>

class Graph {
private:
    int V; // Количество вершин
    std::vector<std::list<int>> adj; // Вектор списков смежности

public:
    Graph(int V); // Конструктор
    void addEdge(int v, int w); // Добавление ребра
    void DFS(int v); // Обход в глубину
    void BFS(int s); // Обход в ширину
    void DFSUtil(int v, std::vector<bool>& visited);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Добавление ребра от v к w
}

void Graph::DFS(int v) {
    std::vector<bool> visited(V, false);
    DFSUtil(v, visited);
}

void Graph::DFSUtil(int v, std::vector<bool>& visited) {
    visited[v] = true;
    std::cout << v << " ";

    for (auto x : adj[v])
        if (!visited[x])
            DFSUtil(x, visited);
}

void Graph::BFS(int s) {
    std::vector<bool> visited(V, false);
    std::list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty()) {
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();

        for (auto x: adj[s])
            if (!visited[x]) {
                queue.push_back(x);
                visited[x] = true;
            }
    }
}

/*
 * в общем я ХУЙ ЗНАЕТ как это русифицировать, никакой танец с бубном не помог
 * попробуйте еще ченить если хотите
*/
int main(){
    Graph g(4); // Создание графа с 4 вершинами
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Обход в глубину (начиная с вершины 2): " << std::endl;
    g.DFS(2);

    std::cout << "Обход в ширину (начиная с вершины 2): ";
    g.BFS(2);

    return 0;
}