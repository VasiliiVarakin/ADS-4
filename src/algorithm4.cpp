#include <iostream>
#include <list>

using namespace std;

#include <cassert>
 

template<typename T>
class TPQueue
class TPQueue : private list<T>
{
public:
    TPQueue() {};          // конструктор
    ~TPQueue() {};         // деструктор

    void push(const T &); // добавить элемент в очередь
    T pop();              // удалить элемент из очереди
    T get() const;        // прочитать первый элемент
    bool isEmpty() const; // пустая ли очередь?
};

// функция добавления элемента в очередь
template<typename T>
void TPQueue<T>::push(const T & item) {
        // if this item is first in queue
    if (this->empty()) {
        this->push_back(item);

        return;
    }
        // if this item should be middle in queue
    for (auto iter = this->begin(); iter != this->end(); iter++) {
        if (iter->prior < item.prior) {
            this->insert(iter, item);
            return;
        }
    }
        // if last
    this->push_back(item);
}

// функция удаления элемента из очереди
template<typename T>
T TPQueue<T>::pop() {
    T elem = this->front();
    this->pop_front();

    return elem;
}

// функция чтения элемента на первой позиции
template<typename T>
T TPQueue<T>::get() const {

    return this->front();
}

// функция проверки очереди на пустоту
template<typename T>
bool TPQueue<T>::isEmpty() const {
    return this->empty();
}

 
struct SYM
{
	char ch;
	int  prior;
};
    char ch;
    int prior;
};


