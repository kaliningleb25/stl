#include <iostream>
#include <vector>
using namespace std;

/* Калинин Глеб (23531/21-1)
 *
 * Написать программу, которая выполняет следующие действия (все операции должны выполняться с помощью стандартных алгоритмов):
- Заполняет вектор геометрическими фигурами. Геометрическая фигура может быть треугольником, квадратом, прямоугольником или пяти угольником.
Структура описывающая геометрическую фигуру  определена ниже,
- Подсчитывает общее количество вершин всех фигур содержащихся в векторе (так треугольник добавляет к общему числу 3, квадрат 4 и т.д.)
- Подсчитывает количество треугольников, квадратов и прямоугольников в векторе
- Удаляет все пятиугольники
- На основании этого вектора создает vector<Point>, который содержит координаты одной из вершин (любой)
 каждой фигуры, т.е. первый элемент этого вектора содержит координаты одной из вершину первой фигуры,
второй элемент этого вектора содержит координаты одной из вершину второй фигуры и т.д.
- Изменяет вектор так, чтобы он содержал в начале все треугольники, потом все квадраты, а потом прямоугольники.
- Распечатывает вектор после каждого этапа работы
 *
 */

typedef struct
{
    int x,y;
} Pointt;

typedef  struct
{
    int vertex_num;      // количество вершин, для треугольника 3, для квадрата и
    // прямоугольника 4, для пяти угольника 5
    vector<Pointt> vertexes;   // вектор содержащий координаты вершин фигуры
    // Для треугольника содержит 3 элемента
    // Для квадрата и прямоугольника содержит 4
    // элемента
    // Для пятиугольника 5 элементов
} Shape;

// Печать вектора:
void printVec(vector<Shape> shapes) {
    for (int i = 0; i < shapes.size(); i++) {
        if (shapes[i].vertex_num == 3)
            cout << "Треугольник с ";
        if (shapes[i].vertex_num == 4)
            cout << "Квадрат(прямоугольник) с ";
        if (shapes[i].vertex_num == 5)
            cout << "Многоугольник с ";
        cout << shapes[i].vertex_num << " вершинами\n";
    }
    cout << "-----------------------------------------\n";
}

int main() {
    // Вектор фигур:
    vector<Shape> shapes;

    // СОЗДАНИЕ ФИГУР И ЗАПОЛНЕНИЕ ВЕКТОРА:
    // Треугольник:
    Shape triangle;
    triangle.vertex_num = 3;
    shapes.push_back(triangle);
    // Квадрат:
    Shape square;
    square.vertex_num = 4;
    shapes.push_back(square);
    // Прямоугольник:
    Shape rectangle;
    rectangle.vertex_num = 4;
    shapes.push_back(rectangle);
    // Многоугольник
    Shape polygon;
    polygon.vertex_num = 5;
    shapes.push_back(polygon);
    // добавление треуг. в конец
    shapes.push_back(triangle);

    // Печать вектора:
    printVec(shapes);

    // Подсчет общего количества вершин всех фигур:
    int n = 0;
    for(int i = 0; i < shapes.size(); i++)
        n += shapes[i].vertex_num;
    cout << "Общее количество вершин всех фигур в векторе = " << n << "\n";

    // Печать вектора:
    printVec(shapes);

    // Подсчет количества треугольников, квадратов и многоуольников в векторе:
    int nTr = 0, nSq = 0, nPol = 0;
    for(int i = 0; i < shapes.size(); i++) {
        if (shapes[i].vertex_num == 3)
            nTr++;
        if (shapes[i].vertex_num == 4)
            nSq++;
        if (shapes[i].vertex_num == 5)
            nPol++;
    }
    cout << "Количество треугольников в векторе = " << nTr << "\n";
    cout << "Количество квадратов(прямоугольников) в векторе = " << nSq << "\n";
    cout << "Количество многоугольников в векторе = " << nPol << "\n";
    // Печать вектора:
    printVec(shapes);

    // Удаление всех многоульников:
    for(int i = 0; i < shapes.size(); i++)
        if (shapes[i].vertex_num == 5)
            shapes.erase(shapes.begin() + i);
    // Печать вектора:
    printVec(shapes);

    // Создание вектора vector<Point>, который содержит координаты одной из вершин каждой фигуры в векторе:
    Pointt pointt;

    for(int i = 0; i < shapes.size(); i++) {
        pointt.x = i;
        pointt.y = i;
        shapes[i].vertexes.push_back(pointt);
    }
    for(int i = 0; i < shapes.size(); i++) {
        if (shapes[i].vertex_num == 3)
            cout << "Координты вершины треугольника:\n x = " << shapes[i].vertexes[0].x << "\n y = " << shapes[i].vertexes[0].y << "\n";
        if (shapes[i].vertex_num == 4)
            cout << "Координты вершины квадрата(прямоугольника):\n x = " << shapes[i].vertexes[0].x << "\n y = " << shapes[i].vertexes[0].y << "\n";
        if (shapes[i].vertex_num == 5)
            cout << "Координты вершины многоугольника:\n x = " << shapes[i].vertexes[0].x << "\n y = " << shapes[i].vertexes[0].y << "\n";
    }
    // Печать вектора:
    printVec(shapes);

    // Изменяет вектор так, чтобы он содержал в начале все треугольники, потом все квадраты, а потом многоугольники.
    sort(shapes.begin(), shapes.end(), [](const Shape& a, const Shape& b) {
        return a.vertex_num < b.vertex_num;
    });
    // Печать вектора:
    printVec(shapes);

    return 0;
}