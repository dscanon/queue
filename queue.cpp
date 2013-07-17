#include<iostream>
using namespace std;
template <class T>
class Queue
{
public :
	Queue();
	~Queue();
	int size();
	bool isEmpty();
	void clear();
	void enqueue(T value);
	T dequeue();
	T peek();
	void expandCapacity();
private :
	static const int INITIAL_CAPACITY = 10;
	T *data;
	int capacity;
	int head;
	int tail;
};

template <class T>
Queue<T> :: Queue()
{
	capacity = INITIAL_CAPACITY;
	data = new T[capacity];
	head = tail = 0;
	
}

template <class T>
Queue<T> :: ~Queue()
{
	delete [] data;
}

template <class T>
int Queue<T> :: size() 
{
	return (tail + capacity - head) % capacity;
}

template <class T>
bool Queue<T> :: isEmpty() 
{
	return head == tail;
}

template <class T>
void Queue<T> :: clear()
{
	head = tail = 0;
}

template <class T>
void Queue<T> :: enqueue(T value)
{
	if (size() == capacity - 1) expandCapacity();
	data[tail] = value;
	tail = (tail + 1) % capacity;
}

template <class T>
T Queue<T> :: dequeue() 
{
	if (isEmpty()) cerr << "dequeue: Attempting to dequeue an empty queue";
	T result = data[head];
	head = (head + 1) % capacity;
	return result;
}

template <class T>
T Queue<T> :: peek() 
{
	if (isEmpty()) cerr << "peek: Attempting to peek at an empty queue";
	return data[head];
}

template <class T>
void Queue<T> :: expandCapacity() {
	int count = size();
	capacity *= 2;
	T *oldArray = data;
	data = new T[capacity];
	for (int i = 0; i < count; i++) {
		data[i] = oldArray[(head + i) % capacity];
	}
	head = 0;
	tail = count;
	delete [] oldArray;
}

int main()
{
	Queue<int> list;
	list.enqueue(1);
	list.enqueue(2);
	cout << "Size = " << list.size() << endl;
	cout << "Dequeue => " << list.dequeue() << endl;
	cout << "Peek => " << list.peek() << endl;
	list.clear();
	if (list.isEmpty())list.enqueue(3);
	return 0;
}