#pragma once
#include <iostream> // Подключим пачку зависимостей
#include <limits>
#include <string>

// В cpp комменты алгоритму делал чатик гпт, так чт все в разнобой, и так се наглядность. мб в ходе допила допишу нормальные (если пойму шо как те алгоритмы вообще работают)

const int V = 11;
  // Да, дубликат, но так уж получилось, что структуре тоже над размерность знать( 
// мб коль будет время на допилку кода, то сделаю получше

struct ShortestPathResult { // А вот и наша структура - считайте эт мешком с переменными, или мешком с массивом переменных. 
    // Позволяет за раз вернуть пачку данных с функции, да и в целом удобная штука, чтоб лишний раз не городить огороды (гыгы, тавтология)
    double distances[V]; // Сюда пишем расстояния в км (Их вывод над реализовывать)
    int previous[V]; // Шо сюда так и не понял толком, но вещь нужная для вывода маршрутов. Максим обьяснял принцип, но я его забыл :(
    std::string route[V]; // А эт массив строк, в каждую строку пишем всю цепочку ходьбы по точкам
    long long executionTime;
};

int MinDistance(double dist[], bool sptSet[]); // Эта считай внутренняя, вызывать ее вам не понадобится


ShortestPathResult Dijkstra(double graph[V][V], int src); // Самые главные) Тип, как видите, структурный, так чт синтаксис при юзе такой 

//  ShortestPathResult Dijkstra_result = Dijkstra(graph, VertexVibor);

// Т.е новая структура типа ShortestPathResult с нужным вам именем (тут Dijkstra_result), значение в которую вбиваем функцией Dijkstra, 
// которой кормим график и выбранную точку (помним про счет с нуля и единички)
// Я дописывал у себя костыль в виде VertexVibor-- , можете сделать подобно, но не забывайте проверить на настоящем графе (файл графа я могу вам кинуть, если кто попросит)

ShortestPathResult BellmanFord(double graph[V][V], int src);

// Абсолютно аналогично с первым, ток пишите главное в отдельную структуру пж

// Пример юза 

//  int VertexVibor = 3;
//  VertexVibor--;
//  ShortestPathResult Dijkstra_result = Dijkstra(graph, VertexVibor);
//  ShortestPathResult BellmanFord_result = BellmanFord(graph, VertexVibor);
//  PathIntoString(Dijkstra_result, Places, VertexVibor);
//  PathIntoString(BellmanFord_result, Places, VertexVibor);


// Первые две строки мы определяем, откуда начнем
// Второй считаем все алгоритмом
// Третим считаем маршруты и пишем в стринги 
// Четвертый и пятый аналогично второму и третьему