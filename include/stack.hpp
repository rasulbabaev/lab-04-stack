#pragma once

template <typename T>
struct Node 
{
	Node *next;
	T value;
};

template <typename T>
class Stack
{
public:
	Stack()
	{
		
		_head = new Node<T>;
		_head->next = nullptr;
	}

	~Stack()
	{
		// Пока не дойдем до фиктивного конца, удаляй элементы
		while (_head->next != 0)
		{
			Node<T> *next = _head->next;
			delete _head;
			_head = next;
		}

		// Удалить фиктивный конец
		delete _head;
	}

	void push(const T& value)
	{
		Node<T>* cur = new Node<T>;
		cur->value = value;
		cur->next = _head;
		_head = cur;
	}

	void pop()
	{
		// Если в верхушке стека не фиктивный конец, то удаляем удаляем верхушку стека
		if (_head->next != 0)
		{
			Node<T> *temp = _head->next;
			delete _head;
			_head = temp;
		}
		else
			throw std::exception("Stack is empty");
	}

	const T& head() const
	{
		if (_head->next != 0)
			return _head->value;
		else
			throw std::exception("Stack is empty");
	}

private:
	Node<T> *_head;
};
