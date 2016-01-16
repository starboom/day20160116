#include <iostream>
using namespace std;


#define SIZE 100
template <class T>
class Stack
{
public:
	/*
		init stack
	*/
	Stack() 
	{
		top = -1; 
	}
	/*
		whether stack is full>
	*/
	bool IsStackFull()
	{
		if(this -> top == SIZE)
		{
			cout << "the stack is full" << endl;
			return true;
		}
		else
		{
			cout << "the stack is not full" << endl;
			return false;
		}
	}
	bool IsStackEmpty()
	{
		if(this -> top == -1)
		{
			cout << "the stack is empty" << endl;
			return true;
		}
		else
		{
			cout << "the stack is not empty" << endl;
			return false;
		}
	}
	int PushStack(T value)
	{
		// int value;
		// int BackButton;
		if(IsStackFull() == false)
		{
			// int i;
			// cout << "Push in" << endl;
			// for(i = 0;i < SIZE;i++)
			// {
			// 	cin >> value;
			(this -> top)++;
			this -> data[this -> top] = value;
			// }
			return 1;
		}
		else
		{
			cout << "Push Failed" << endl;
			return -1;
		}

	}
	int PopStack()
	{
		if(IsStackEmpty() == false)
		{
			cout << "Pop Success!" << endl;
			cout << this -> data[this -> top] << " is Poped" << endl;
			this -> top--;
			return 1;
		}
		else
		{
			cout << "Pop Failed" << endl;
			return -1;
		}

	}
	int ShowStack()
	{
		if(IsStackEmpty() == false)
		{
			int i;
			cout << "the stack is " << endl;
			for(i = top ;i >= 0;i--)
			{
				cout << this -> data[i];
				cout << endl;
			}
			return 1;
		}
		else
		{
			cout << "the stack is empty" << endl;
			return -1;
		}

	}

	~Stack()
	{

	}
private:
	T data[SIZE];
	int top;
};

int main(int argc, char const *argv[])
{
	Stack<int> S1;
	S1.IsStackFull();
	S1.IsStackEmpty();
	S1.PushStack(11);
	S1.PushStack(2);
	S1.PushStack(41);
	S1.PushStack(551);
	S1.PushStack(2);
	S1.PushStack(311);
	S1.PushStack(131);
	S1.ShowStack();

	S1.PopStack();
	S1.ShowStack();

	Stack<char> S2;
	S2.IsStackFull();
	S2.IsStackEmpty();
	S2.PushStack('a');
	S2.PushStack('b');
	S2.PushStack('e');
	S2.PushStack('r');
	S2.PushStack('y');
	S2.PushStack('o');
	S2.PushStack('i');
	S2.ShowStack();

	S2.PopStack();
	S2.ShowStack();



	return 0;
}