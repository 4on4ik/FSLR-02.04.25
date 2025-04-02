#include <algorithm> 
#include <iostream>
#include <unistd.h>    

class SetCollection {
private:
    int size;
    int* data;

public:
    // Конструктор
    SetCollection(int n);

    // Деструктор
    ~SetCollection();

    // Методы класса
    void Iterate();
    int Delete_Elements();
    int Sorting();
    void AddElement(int position, int value);
    bool RemoveElement(int position);
    bool Contains(int element);
    int GetSize();
    int FindMax();
    int FindMin();
    int* GetAddress();
    bool operator=(const SetCollection& other);
    SetCollection operator+(const SetCollection& other);
};
