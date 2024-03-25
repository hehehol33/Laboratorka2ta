#include "Algorithms.h" // А эт файл заголовка, единственный случай в этой программе, когда он используется по назначению

Graph::Graph(short V) : V(V) {
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::addTable(double gra[rozmir][rozmir]) {
    for (short i = 0; i < V; i++) {
        for (short j = 0; j < V; j++) {
            graph[i][j] = gra[i][j];
            if (graph[i][j] != 0) {
                addEdge(i, j);
            }
        }
    }
    V = rozmir;
}

ShortestPathResult Graph::BellmanFord(int src) {
    auto start = std::chrono::high_resolution_clock::now();
    ShortestPathResult result;
    double dist[rozmir]; // Тут пишем минимальные расстояния от точки к вершинам
    int prev[rozmir];    // Пишем какие вершины были на пути

    // Пишем все расстояния как бесконечность, а пред вершинки в -1
    for (int i = 0; i < V; i++) {
        dist[i] = std::numeric_limits<double>::max(); // Все в инфинити
        prev[i] = -1; // Все в пред
    }

    dist[src] = 0; // Растояния от выбраной точки к ней же буде 0

    //Бегаем по ребрах V-1 раз
    for (int count = 0; count < V - 1; count++) {
        // Пробегаем все ребра графа
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                // Если есть ребро с u до v и можна расстояние уменьшить до v, обновляем расстояние и пред вершинку
                if (graph[u][v] != 0 && dist[u] != std::numeric_limits<double>::max() && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v]; // Растояние
                    prev[v] = u; // Пред вершинка
                }
            }
        }
    }
    return result;
}

ShortestPathResult Graph::Dijkstra(int src) {
    auto start = std::chrono::high_resolution_clock::now();
    ShortestPathResult result;
    double dist[rozmir]; // Сюда пишем минимальные расстояния от точки к вершинам
    bool sptSet[rozmir]; // Массив куда мы пишем, включена ли вершина в дерево самых коротких путей
    int prev[rozmir]; // А сюда пишем по классике какие вершины были на нашем пути

    // Initialize all distances as "infinity", and vertices in the shortest path tree as "not included" 
    // Пишем все расстояния как бесконечность, и вершины в дереве кратчайших путей как "неучтенные"
    for (int i = 0; i < V; i++) {
        dist[i] = std::numeric_limits<double>::max(); // Бесконечность
        sptSet[i] = false; // Не учтенные
        prev[i] = -1; // Все будем считать пред вершинкой
    }

    dist[src] = 0; // От себя к себе расстояние не должно быть никакого
    // В жизни так же, как в программе, поэтому не отдаляйтесь от самого себя, ведь самое ценное, что у тебя есть, это ты сам

    // Ищем самый короткий перебором ребер V -1 разок
    for (int count = 0; count < V - 1; count++) {
        int u = MinDistance(dist, sptSet); // Ищет вершину с минимальным расстоянием среди неучтенных в дереве кратчайших путей
        sptSet[u] = true; // Учитываем найденную в список кратчайших среди кратчайших путей на диком западе, короче только мой сон

        // Обновляем значения
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] != 0 && dist[u] != std::numeric_limits<double>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v]; // Пишем растояние
                prev[v] = u; // и пред вершинку 
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now(); // Заканчиваем считать время
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); // Вычитаем времячко
    result.executiontime = (duration.count() / 1000); // Пишем в переменную внутри структуры

    // Пишем результаты в структуру
    for (int i = 0; i < V; i++) {
        result.distances[i] = dist[i];
        result.previous[i] = prev[i];

    }
    return result; // Возвращаем структурочку мою ненаглядную
}

string Graph::SccKosaraju() {
    ShortestPathResult result;
    string sccs; // Змінна для зберігання всіх з'єднаних рядків
    stack<int> Stack;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            fillOrder(i, visited, Stack);
        }
    }

    Graph transposed = getTranspose();

    fill(visited.begin(), visited.end(), false);

    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v]) {
            string result = "";
            transposed.DFSUtil(v, visited, result);
            // З'єднуємо рядки і додаємо розділювач
            if (!sccs.empty()) {
                sccs += "\n"; // Розділювач, наприклад, символ нового рядка
            }
            sccs += result; // Додаємо поточний рядок до sccs
        }
    }

    return sccs;
}

string Graph::SccTarjan() {
    string sccs; // Змінна для зберігання всіх з'єднаних рядків
    vector<int> disc(V, -1), low(V, -1);
    stack<int> st;
    vector<bool> stackMember(V, false);
    int time = 0;

    for (int i = 0; i < V; ++i) {
        if (disc[i] == -1) {
            tarjanDFS(i, disc, low, st, stackMember, sccs, time);
        }
    }

    return sccs;
}

void Graph::fillOrder(int v, vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i]) {
            fillOrder(i, visited, Stack);
        }
    }

    Stack.push(v);
}

void Graph::DFSUtil(int v, vector<bool>& visited, string& result) {
    visited[v] = true;
    result += to_string(v) + " ";

    for (int i : adj[v]) {
        if (!visited[i]) {
            DFSUtil(i, visited, result);
        }
    }
}

void Graph::tarjanDFS(int u, vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& stackMember, string& sccs, int& time) {
    disc[u] = low[u] = ++time;
    st.push(u);
    stackMember[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            tarjanDFS(v, disc, low, st, stackMember, sccs, time);
            low[u] = min(low[u], low[v]);
        }
        else if (stackMember[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        string scc = "";
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            stackMember[v] = false;
            scc += to_string(v) + " ";
            if (v == u) break;
        }
        // Додаємо рядок scc до змінної sccs
        if (!sccs.empty()) {
            sccs += "\n"; // Розділювач, наприклад, символ нового рядка
        }
        sccs += scc; // Додаємо поточний рядок scc до sccs
    }
}

Graph Graph::getTranspose() {
    Graph transpose(V);
    for (int v = 0; v < V; ++v) {
        for (int i : adj[v]) {
            transpose.adj[i].push_back(v);
        }
    }
    return transpose;
}

int Graph::MinDistance(double dist[], bool sptSet[]) { // Считаем каким макаром мы пройдем меньше всего, для чего просим массив с расстояниями, который генерируем, и массив учтенных вершин
    double min = std::numeric_limits<double>::max(); // Ставим в максималочку минималочку, от ирония)
    int minIndex = -1; // Устанавливаем минимальный индекс, для нашего случая -1
    for (int v = 0; v < V; v++) { // Пробегаемся по вершинкам
        if (!sptSet[v] && dist[v] <= min) { // Если это у нас не учтенка и расстояние меньше, чем уже найденое
            min = dist[v]; // Запишем новую минимальную дистанцию
            minIndex = v; // Ну и индекс, дабы все знали коротышку
        }
    }
    return minIndex; // Берем его и идем хвастать назад в Дейкстру 
}