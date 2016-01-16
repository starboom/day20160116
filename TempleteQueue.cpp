#include <iostream>
using namespace std;

#define SIZE 100

template <class T>
class queue
{
public:
	queue()
	{
		Tail = -1;
		Head = 0;
	}


// //进队
// void  PushQueue(Queue *qe,int data)
// //出队
// void PopQueue(Queue *qe)
// //返回队首值
// int  GetQueueFrontValue(Queue * qe)*/

	bool IsQueueFull()
	{
		if(this -> Head == SIZE - 1)
		{
			cout << "IsQueueFull" << endl;
			return true;
		}
		else
		{
			cout << "Not IsQueueFull" << endl;
			return	false;
		}
	}
	bool IsQueueEmpty()
	{
		if(this -> Tail == 0 && this -> Head == -1)
		{
			cout << "IsQueueEmpty" << endl;
			return true;
		}
		else
		{
			cout << "Not IsQueueEmpty" << endl;
			return false;
		}
	}
	int PushQueue(T value)
	{
		if(!IsQueueFull())
		{
			this -> Tail++;

			this -> data[Tail] = value;
			return 1;
		}
		else
		{
			cout << "Push Failed" << endl;
			return -1;
		}
	}	

	int PopQueue()
	{
		if(IsQueueEmpty() == false)
		{
			cout << "the " << this -> data[Head] << " is poped" << endl;
			Tail--;
			int i;
			for(i = 0;i < Tail+1;i++)
			{
				this -> data[i] = this -> data[i+1];
			}
			return 1;
		}
		else
		{
			cout << "Pop Failed" << endl;
			return -1;
		}
	}
	int ShowQueue()
	{
		if(IsQueueEmpty() == false)
		{
			int i;
			cout << "the Queue is " << endl;
			for(i = 0;i < Tail+1;i++)
			{
				cout << this -> data[i] << endl;
			}
			return 1;
		}
		else
		{
			cout << "No Queue Create" << endl;
		}
	}



	~queue()
	{

	}
	
private:
	int Tail;
	int Head;
	T data[SIZE];
};

int main(int argc, char const *argv[])
{
	queue<int> q1;

	q1.IsQueueEmpty();
	q1.IsQueueFull();
	q1.PushQueue(223232);
	q1.PushQueue(34);
	q1.PushQueue(54);
	q1.PushQueue(3432);
	q1.PushQueue(232);
	q1.PushQueue(213);
	q1.PushQueue(12);
	q1.PushQueue(213);
	q1.PushQueue(243);
	q1.PushQueue(243);
	q1.PushQueue(243);
	q1.PushQueue(243);
	q1.PushQueue(243);
	q1.PushQueue(243);
	q1.PushQueue(243);
	q1.ShowQueue();
	q1.PopQueue();
	q1.PopQueue();
	q1.PopQueue();
	q1.PopQueue();
	q1.ShowQueue();


	return 0;
}

