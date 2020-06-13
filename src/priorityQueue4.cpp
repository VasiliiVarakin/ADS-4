#include <cassert>

template<typename T>
class TPQueue
{private:
    T *arr;          // массив с данными
    int* preoritets;
    int size;        // максимальное количество элементов в очереди (размер массива)
    int begin,       // начало очереди
        end;         // конец очереди
    int count;       // счетчик элементов
{
private:
	T* arr;         
	int size;   
	int begin,      
		end;      
	int count;     
public:
    TQueue(int);          // конструктор по умолчанию
    ~TQueue();                 // деструктор
	TPQueue(int = 100);          
	~TPQueue();               

    void push(const T &, int preoritet); // добавить элемент в очередь
    T poop();              // удалить элемент из очереди
    T get() const;        // прочитать первый элемент
    bool isEmpty() const;      // пустая ли очередь?
    bool isFull() const;       // заполнен ли массив?
	void push(const T&); 
	T pop();              
	T get() const;      
	bool isEmpty() const;     
	bool isFull() const;
};
// конструктор по умолчанию

template<typename T>
TQueue<T>::TQueue(int sizeQueue = 100) :
    size(sizeQueue),
    begin(0), end(0), count(0)
TPQueue<T>::TPQueue(int sizeQueue) :
	size(sizeQueue),
	begin(0), end(0), count(0)
{
    // дополнительный элемент поможет нам различать конец и начало очереди
    arr = new T[size + 1];
    preoritets = new int[size + 1];
	arr = new T[size + 1];
}

// деструктор класса Queue
template<typename T>
TQueue<T>::~TQueue()
TPQueue<T>::~TPQueue()
{
    delete [] arr;
    delete [] preoritets;
	delete[] arr;
}


// функция добавления элемента в очередь
template<typename T>
void TQueue<T>::push(const T & item, int preoritet)
void TPQueue<T>::push(const T& item)
{
    // проверяем, ести ли свободное место в очереди
    assert( count < size );
	assert(count < size);

    arr[end] = item;
    preoritets[end++] = preoritet;
    count++;
	arr[end] = item;

    // проверка кругового заполнения очереди
    if (end > size)
        end -= size + 1; // возвращаем end на начало очереди
	for (int i = end; i > 0; i--)
	{
		if (arr[i].prior > arr[i - 1].prior)
		{
			T temp = arr[i - 1];
			arr[i - 1] = arr[i];
			arr[i] = temp;
		}
	}
	count++;
	end++;

	if (end > size)
		end -= size + 1;
}

// функция удаления элемента из очереди

template<typename T>
T TQueue<T>::poop()
T TPQueue<T>::pop()
{
    // проверяем, есть ли в очереди элементы
    assert( count > 0 );
	assert(count > 0);

    int max = 0;
    for(int i=0; i<count; ++i){
        if(preoritets[i] > preoritets[max]){
            max = i;
        }
    }
    preoritets[max] = 0;
    T item = arr[max];
	T item = arr[begin++];
	count--;

    // проверка кругового заполнения очереди
    if (begin > size)
        begin -= size + 1; // возвращаем begin на начало очереди
	if (begin > size)
		begin -= size + 1; 

    return item;
	return item;
}

// функция чтения элемента на первой позиции
template<typename T>
T TQueue<T>::get() const
T TPQueue<T>::get() const
{
    // проверяем, есть ли в очереди элементы
    assert( count > 0 );
    return arr[begin];
	assert(count > 0);
	return arr[begin];
}

// функция проверки очереди на пустоту
template<typename T>
bool TQueue<T>::isEmpty() const
bool TPQueue<T>::isEmpty() const
{
  return count==0;
	return count == 0;
}

// функция проверки очереди на заполненность
template<typename T>
bool TQueue<T>::isFull() const
bool TPQueue<T>::isFull() const
{
  return count==size;
	return count == size;
}

struct SYM
{
	char ch;
