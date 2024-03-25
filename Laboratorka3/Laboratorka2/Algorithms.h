#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <chrono> 
#include <limits> 

using namespace std;

// В cpp уже запилил более детальные комменты, можете читать и становится единым целым с Дейстрой и Беллманом-Фордом
// А вот коментов для новых алгоритмов нима, мож потом допишу

const int rozmir = 11;
// Да, дубликат, но так уж получилось, что структуре тоже над размерность знать( 
// мб коль будет время на допилку кода, то сделаю получше


struct ShortestPathResult { // А вот и наша структура - считайте эт мешком с переменными, или мешком с массивом переменных. 
    // Позволяет за раз вернуть пачку данных с функции, да и в целом удобная штука, чтоб лишний раз не городить огороды (гыгы, тавтология)
    double distances[rozmir]; // Сюда пишем расстояния в км (Их вывод над реализовывать)
    int previous[rozmir]; // Шо сюда так и не понял толком, но вещь нужная для вывода маршрутов. Максим обьяснял принцип, но я его забыл :(
    
};


class Graph {
private:
    short V; // Размерность
    int execution_time = 0; // Время, затраченное на исполнение
    std::vector<std::vector<int>> adj; // Граф вектором пишем
    double graph[rozmir][rozmir]; // Матрица наша

    void fillOrder(int v, std::vector<bool>& visited, std::stack<int>& Stack);
    void DFSUtil(int v, std::vector<bool>& visited, std::string& result);
    void tarjanDFS(int u, std::vector<int>& disc, std::vector<int>& low, std::stack<int>& st, std::vector<bool>& stackMember, std::string& sccs, int& time);
    Graph getTranspose();
    int MinDistance(double dist[], bool sptSet[]);

public:
    Graph(short V);
    void addEdge(int v, int w);
    void addTable(double gra[rozmir][rozmir]);
    ShortestPathResult BellmanFord(int src); // Перенес сюда первые два алгоритма
    ShortestPathResult Dijkstra(int src);
    std::string SccKosaraju();
    std::string SccTarjan();
    int GetTime(); // Выводит время в микросеках
};


// Пример использования 

//Graph g(razmer);
//g.addTable(graph);
//cout << "Strongly Connected Components using Kosaraju's Algorithm:\n";
//string sccs = g.getSccKosaraju();
//cout << sccs << endl;
//cout << "\nStrongly Connected Components using Tarjan's Algorithm:\n";
//string sccs2 = g.getSccTarjan();
//cout << sccs2 << endl;
//
//ShortestPathResult result = g.BellmanFord(10);
//ShortestPathResult result2 = g.Dijkstra(10);