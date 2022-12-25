//Program Code of Queue

#include<iostream>
using namespace std;

template <class T>
class SinglyLinkedList;

//SinglyLinkedList Code
template <class T>
class Node
{
	private: 
		T data;  
    	Node <T> *next;  
    
    public:
	
    	Node()
    	{
			this->next = NULL;	
		}
    	
		Node(T data)
    	{
			this->data=data;
			this->next= NULL;  	
		}	
		friend class SinglyLinkedList<T>;
};


template <class T>
class SinglyLinkedList
{
	private:
	Node<T> *head;
	bool is_empty;
	
	public:
	
	SinglyLinkedList()		//Constructor
	{
		this->head = NULL;
		is_empty = true;
	}
	
	~SinglyLinkedList()		//Destructor
	{
		if(head)
			delete head;	
		head=NULL;
	}
	
	void Insert_at_Head(T data)
	{
		if (!head) 
		{
			head = new Node<T>();
			head->data= data;
			head->next= NULL;
			is_empty = false;
			return;
		}
		
		Node<T> *n = new Node<T> (data);
		n->data=head->data;
		head->data= data;  
		n->next=head->next; 
		head->next= n;
	}
	
	T Delete_from_Head()
	{
		T temp;
		if(head)
		{
			if(head->next == NULL)
				is_empty=true;
			
			temp = head->data;
			head=head->next;
			return temp;
		}
		else
		{
			cout<<"Error: Queue Is Empty"<<endl;
			is_empty = true;
			return 0;
		}
		
	}
	
	void Insert_at_End(T data)
	{
    	if (!head) 
		{
			head = new Node<T>();
			head->data= data;
			head->next= NULL;
			is_empty = false;
			return;
		}
		
		Node<T> *current = head;
    	while (current->next!=0)
    	{
			current=current->next;
		}
		Node<T> *n = new Node<T> (data);
		current->next=n;
		n->next=0;
		is_empty = false;
	}
	
	bool IS_EMPTY()
	{
		return is_empty;
	}
};


//Queue Implemented Using Singly Linked List

template <class T>
class Queue
{
	SinglyLinkedList<T> *que;
	
	public:
	Queue()
	{
		que = new SinglyLinkedList <T> ();			
	}
	
	~Queue()
	{
		if(que)
			delete que;
		que=NULL;
	}
	
	void EnQueue(T data)
	{
		que->Insert_at_End(data);
	}
	
	T DeQueue()
	{
		T temp;
		temp = que->Delete_from_Head();
		return temp;
	}
	
	T Look ()
	{
		T temp;
		temp = que->Show_Head();
		return temp;	
	}
	
	bool is_empty()
	{
		if(que->IS_EMPTY())
			return true;
		else
			return false;
	}
		
};


int main ()
{
	Queue <int> q;
	q.EnQueue(1);
	q.EnQueue(2);
	q.EnQueue(3);
	q.EnQueue(4);
	cout<<q.DeQueue()<<endl;
	cout<<q.DeQueue()<<endl;
	cout<<q.DeQueue()<<endl;
	cout<<q.DeQueue()<<endl;
	cout<<q.DeQueue()<<endl;
}
