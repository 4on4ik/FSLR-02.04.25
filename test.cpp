#include "SetCollection.hpp"

using namespace std;

int main() {
    int n;
    cout << "Введите количество элементов множества" << endl;
    cin >> n; // Размер множества
    SetCollection sc1(n); // Создание множества
    sc1.AddElement(5,9); //Добавление элементов в множество
    sc1.AddElement(4,9);
    sc1.AddElement(4,2);
    sc1.AddElement(1,5);// Добавление двух одинаковых элементов на разные позиции 
    sc1.Iterate();
    sleep(3);
    sc1.Delete_Elements();
    sc1.Sorting();
    sc1.Iterate();//Сортировка и удаление одинаковых элементов
    sleep(3);
    sc1.RemoveElement(4);//удаление числа на 4-ой позиции
    sc1.Sorting();
    sc1.Delete_Elements();
    sc1.Iterate();
    sc1.Contains(9);//Проверка содержания 9 в массиве 
    sc1.FindMax();// нахождение максимального значения
    sc1.FindMin();// нахождение минимального значения
    sc1.GetAddress();//Получение адреса первого элемента
    sleep(3);
    int s;
    cout << "Введите размер второго массива" << endl;
    cin >> s;
    SetCollection sc2(s); // Создание второго множества
    sc2.AddElement(5,9); //Добавление элементов в множество
    sc2.AddElement(4,9);
    sc2.AddElement(4,2);
    sc2.AddElement(1,5);
    sc2.Delete_Elements();
    sc2.Sorting();
    sc2.RemoveElement(4);
    sc2.Sorting();
    sc2.Delete_Elements();
    sc1.Iterate();
    sc2.Iterate();//Выводим оба множества и сравниваем
    sc2.operator=(sc1);
    sc2.AddElement(2,7);//Если добавим новый элемент, то множества уже не будут равны
    sc2.operator=(sc1);

    //Самое тяжелое и финальное: Сложение коллекций
    SetCollection combined = sc1 + sc2;
    combined.Iterate();

    return 0;
}
