#include <algorithm>
#include <iostream>
#include <unistd.h>

using namespace std;

class SetCollection {
    private:
        int size;
        int* data;
        
    public:
        SetCollection(int n): size(n), data(new int[n]) {
            if (data != nullptr){
                cout << "Создано множество размером " << n << " элементов" << endl;
                cout << " " << endl;
                for (int i = 0; i < size; ++i) {
                    data[i] = 0;
                }
            } else {
                cerr << "Ошибка: Невозможно выделить память." << endl;
                size = 0;
            }
            // Создание коллекции типа массив, без возможности вмешательства в код
        }
    
    ~SetCollection() {
        if (data != nullptr) {
            delete[] data;
        }
    }
    
    public:
        void Iterate(){
            if (data == nullptr) {
                cerr << "Ошибка: Множество не создано." << endl;
                return;
            }else{
                cout << "Элементы множества:" << endl;
                for (int i = 0; i < size; ++i) {
                    if (data[i] != 0) {
                        cout << data[i] << " ";
                    }
                }
                cout << " " << endl;
            }
        cout << endl;
        }
    public:
        int Delete_Elements(){
            if (data == nullptr) {
                cerr << "Ошибка: Множество не создано." << endl;
                return 0;
            }

            if (size <= 1) {
                return size; // Нет смысла удалять дубликаты, если меньше двух элементов
            }

            int k = 1; // Индекс для записи уникальных элементов

            for (int  i = 1; i < size; i++) {
                if (data[i] != data[k - 1]) {
                    data[k++] = data[i];
                }
            }

            // Теперь у нас writeIndex - это количество уникальных элементов
            int oldSize = size;
            size = k;

            // Создаем новый массив нужного размера
            int* newData = new int[size];

            // Копируем уникальные элементы
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }

            // Освобождаем старый массив
            delete[] data;

            // Присваиваем новому массиву
            data = newData;

            cout << "В массиве больше нет повторов :)" << endl;
            cout << " " << endl;
            return 0;
        };
    public:
        int Sorting(){
            //Реализация сортировки массива
            if (data == nullptr) {
                cerr << "Ошибка: Множество не создано." << endl;
                return 0;
            }

            // Используем функцию sort из STL для сортировки массива
            sort(data, data + size);

            cout << "Массив отсортирован." << endl; 
            cout << " " << endl;
            return 0;
        }
    
    public:
        void AddElement(int position, int value){
            //Добавление элемента в список с сортировкой и удаление дубликатов
            if (position < 0 || position >= size) {
                cerr << "Ошибка: Позиция вне диапазона." << endl;
                return;
            }

             // Проверяем, занят ли элемент на позиции
            if (data[position] != 0) {
            // Если элемент на позиции уже существует, сдвигаем все элементы вправо
                int* newData = new int[size + 1];

            // Копируем элементы до позиции вставки
                for (int i = 0; i < position; ++i) {
                    newData[i] = data[i];
                }

                // Вставляем новый элемент
                newData[position] = value;

                // Копируем элементы после позиции вставки
                for (int i = position; i < size; ++i) {
                    newData[i + 1] = data[i];
                }

                // Освободим старую память
                delete[] data;

                // Присвоим новый массив и увеличим размер
                data = newData;
                size += 1;

                cout << "Элемент " << value << " успешно вставлен на позицию " << position << "." << endl;
            } else {
             // Если позиция свободна, просто вставляем элемент
                data[position] = value;
                cout << "Элемент " << value << " успешно вставлен на позицию " << position << "." << endl;
            }
            cout << " " << endl;
        }
    public:
        bool RemoveElement(int position){
            //Удаление элемента с подключением сортировки
            if (data == nullptr) {
                cerr << "Ошибка: Множество не создано." << endl;
                return false;
            }

            if (position < 0 || position >= size) {
                cerr << "Ошибка: Позиция вне допустимого диапазона." << endl;
                return false;
            }



            // Обнуляем элемент на указанной позиции
            data[position] = 0;
            cout << "Элемент на позиции " << position << " удалён." << endl;
            return true;  
        }
    public:
        bool Contains(int element){
            //Проверка наличия элемента в массиве с помощью перебора
            if (data == nullptr) {
                cerr << "Ошибка: Множество не создано." << endl;
                return false;
            }

            for (int i = 0; i < size; ++i) {
                if (data[i] == element) {
                    cout << "Элемент " << element << " есть в массиве" << endl;
                    return true;
                }
            }
            cout << "Данного элемента в массиве не наблюдается :(" << endl;
            cout << " " << endl;
            return false;
        }
    public:
        int GetSize(){
            //Нахождение size массива
            cout << "Размер массива = " << size << endl;
            cout << " " << endl;
            return size;
        }
    public:
        int FindMax(){
            //Нахождение максимального элемента массива
            if (data == nullptr) {
                cerr << "Ошибка: Множество не создано." << endl;
                return 0;
            }
            int maxValue = 0;
            for (int i = 0; i < size; ++i){
                if (maxValue < data[i]){
                    maxValue = data[i];
                }
            }
            cout << "Максимальный элемент множетсва: " << maxValue << endl;
            cout << " " << endl;
            return maxValue;
            
        }
    public:
        int FindMin(){
            //Нахождение минимального элемента массива
            if (data == nullptr){
                cerr << "Ошибка: Множество не создано" << endl;
                return 0;
            }

            int minValue = 2147483646;

            for (int i = 0; i < size; ++i){
                if (minValue > data[i] and data[i]!=0){
                    minValue = data[i];
                }
            }
            cout << "Минимальный элемент множетсва:" << minValue << endl;
            cout << " " << endl;
            return minValue;   
        }
    public:
        int* GetAddress(){
            //Возвращение первого элемента массива для нахождения других
            if (data == nullptr) {
                cerr << "Ошибка: Множество не создано." << endl;
                return nullptr;
            }

            return data;
        }
    public:
        bool operator=(const SetCollection& other){
            if (this->size != other.size){
                cout << "Множества не равны" << endl;
                return false;
            }
            for (int i =0; i < this->size; i++){
                if (this -> data[i] != other.data[i]){
                    cout << "Множества не равны" << endl;
                    return false;
                }
            }
            cout << "Множества равны" << endl;
            return true;
        }

    public:
        SetCollection operator+(const SetCollection& other) {
            // Объединение двух множеств
            int total_size = size + other.size;
            int* result_data = new int[total_size];

            // Копирование первого множества
            for (int i = 0; i < size; ++i) {
                result_data[i] = data[i];
            }

            // Копирование второго множества
            for (int i = 0; i < other.size; ++i) {
                result_data[size + i] = other.data[i];
            }

            // Создаем новое множество с объединенными элементами
            SetCollection result(total_size);
            result.data = result_data;
            result.size = total_size;

            // Сортировка объединенного множества
            result.Sorting();

            // Удаление дубликатов
            result.Delete_Elements();

            return result;
        }
};

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
