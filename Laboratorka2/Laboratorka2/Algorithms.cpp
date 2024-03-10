#include "Algorithms.h"

int MinDistance(double dist[], bool sptSet[]) {
    double min = std::numeric_limits<double>::max();
    int minIndex = -1;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void PathIntoString(ShortestPathResult& result, const std::string Places[]) {
    for (int i = 0; i < V; i++) {
        //std::cout << "Shortest route from '" << Places[src] << "` to `" << Places[i] << "`: " << result.distances[i] << " km" << "\n";
        std::string route = Places[i] + " (" + std::to_string(i + 1) + ")";
        int j = i;
        while (result.previous[j] != -1)
        {
            route = Places[result.previous[j]] + " (" + std::to_string(result.previous[j] + 1) + ") <- " + route;
            j = result.previous[j];
        }
        result.route[i] = route; 
        //std::cout << "Route: " << result.route[i] << "\n\n";
    }
}

ShortestPathResult Dijkstra(double graph[V][V], int src) {
    ShortestPathResult result;
    double dist[V]; // Array to store the minimum distances from the source to the vertices
    bool sptSet[V]; // Array to store information about whether the vertex is included in the shortest path tree
    int prev[V]; // Array to store the path through the vertices

    // Initialize all distances as "infinity", and vertices in the shortest path tree as "not included"
    for (int i = 0; i < V; i++) {
        dist[i] = std::numeric_limits<double>::max();
        sptSet[i] = false;
        prev[i] = -1;
    }

    dist[src] = 0; // Distance from source to itself is 0

    // Finding shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = MinDistance(dist, sptSet); // Finding the vertex with the minimum distance among the vertices not yet included in the shortest path tree
        sptSet[u] = true; // Include the selected vertex in the shortest path tree

        // Update distances for vertices adjacent to the selected vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] != 0 && dist[u] != std::numeric_limits<double>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    // Store the results
    for (int i = 0; i < V; i++) {
        result.distances[i] = dist[i];
        result.previous[i] = prev[i];

    }


    return result;
}

ShortestPathResult BellmanFord(double graph[V][V], int src) {
    ShortestPathResult result;

    double dist[V]; // Масив для зберігання мінімальних відстаней від джерела до вершин
    int prev[V];    // Масив для зберігання попередніх вершин у шляху

    // Ініціалізуємо всі відстані як "нескінченність", а попередні вершини як -1
    for (int i = 0; i < V; i++) {
        dist[i] = std::numeric_limits<double>::max();
        prev[i] = -1;
    }

    dist[src] = 0; // Відстань від джерела до нього ж самого дорівнює 0

    // Проходимо всі ребра V-1 разів
    for (int count = 0; count < V - 1; count++) {
        // Проходимо всі ребра графа
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                // Якщо є ребро з u до v і можна зменшити відстань до v, оновлюємо відстань та попередню вершину
                if (graph[u][v] != 0 && dist[u] != std::numeric_limits<double>::max() && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    prev[v] = u;
                }
            }
        }
    }

    // Зберігаємо результати в структурі
    for (int i = 0; i < V; i++) {
        result.distances[i] = dist[i];
        result.previous[i] = prev[i];
    }

    return result;
}
