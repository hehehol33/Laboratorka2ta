#include "Algorithms.h" // А эт файл заголовка, единственный случай в этой программе, когда он используется по назначению


int MinDistance(double dist[], bool sptSet[]) { // Считаем каким макаром мы пройдем меньше всего, для чего просим массив с расстояниями, который генерируем, и массив учтенных вершин
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

ShortestPathResult Dijkstra(double graph[V][V], int src) { // Просим дорогого пользователя выбрать вершину графа, с которой будем гулять, и т-ща программиста скормить матрицу расстояний
    auto start = std::chrono::high_resolution_clock::now();
    ShortestPathResult result;
    double dist[V]; // Сюда пишем минимальные расстояния от точки к вершинам
    bool sptSet[V]; // Массив куда мы пишем, включена ли вершина в дерево самых коротких путей
    int prev[V]; // А сюда пишем по классике какие вершины были на нашем пути

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

ShortestPathResult BellmanFord(double graph[V][V], int src) { // Просим многоуважаемого пользователя выбрать вершину от которой пойдем, и т-ща программиста выдать матрицу расстояний
    auto start = std::chrono::high_resolution_clock::now();
    ShortestPathResult result;
    double dist[V]; // Тут пишем минимальные расстояния от точки к вершинам
    int prev[V];    // Пишем какие вершины были на пути

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

    auto end = std::chrono::high_resolution_clock::now(); // Заканчиваем считать время
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); // Вычитаем времячко
    result.executiontime = (duration.count() / 1000); // Пишем в переменную

    // Зберігаємо результати в структурі
    for (int i = 0; i < V; i++) {
        result.distances[i] = dist[i];
        result.previous[i] = prev[i];
    }

    return result; // Возвращаем структуру ее новому счастливому владельцу
}
