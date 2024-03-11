﻿#include "Algorithms.h"
#include <chrono>

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

ShortestPathResult Dijkstra(double graph[V][V], int src) {
    auto start = std::chrono::high_resolution_clock::now();
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
    auto end = std::chrono::high_resolution_clock::now(); // Кінець вимірювання часу
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); // Розраховуємо тривалість вимірювання часу

    result.executiontime = duration.count();

    // Store the results
    for (int i = 0; i < V; i++) {
        result.distances[i] = dist[i];
        result.previous[i] = prev[i];

    }


    return result;
}

ShortestPathResult BellmanFord(double graph[V][V], int src) {
    auto start = std::chrono::high_resolution_clock::now();
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

    auto end = std::chrono::high_resolution_clock::now(); // Кінець вимірювання часу
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); // Розраховуємо тривалість вимірювання часу
    result.executiontime = duration.count();

    // Зберігаємо результати в структурі
    for (int i = 0; i < V; i++) {
        result.distances[i] = dist[i];
        result.previous[i] = prev[i];
    }

    return result;
}
