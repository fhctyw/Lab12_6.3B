#include <iostream>
using namespace std;

struct Elem
{
	Elem* next,
		* prev;
	int info;
};

void enqueue(Elem*& first, Elem*& last, int info)
{
	Elem* tmp = new Elem;
	tmp->info = info;
	tmp->next = nullptr;
	if (last != nullptr)
		last->next = tmp;
	tmp->prev = last;
	last = tmp;
	if (first == nullptr)
		first = tmp;
}

int dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->next;
	int info = first->info;
	delete first;
	first = tmp;
	if (first == nullptr)
		last = nullptr;
	else
		first->prev = nullptr;
	return info;
}

void print(const Elem* first)
{
	if (first == nullptr)
		cout << endl;
	else
	{
		cout << first->info << " ";
		print(first->next);
	}
}

int count(Elem* first, int info)
{
	if (first == nullptr)
		return 0;
	else
	{
		if (first->info == info)
			return 1 + count(first->next, info);
	}
	count(first->next, info);
}

int main()
{
	Elem* first = nullptr, * last = nullptr;
	for (int i = 0; i < 10; i++)
		enqueue(first, last, rand() % 11);

	print(first);
	int info;
	cout << "search: "; cin >> info;
	cout << count(first, info) << endl;
	print(first);

	for (size_t i = 0; i < 10; i++)
		dequeue(first, last);

	return 0;
}