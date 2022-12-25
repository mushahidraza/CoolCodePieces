//Program Code of Stack
#include<iostream>
using namespace std;

template <class T>
class SinglyLinkedList;

template <class T>
class Stack;



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
	
	public:
	
	SinglyLinkedList()		//Constructor
	{
		this->head = NULL;
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
			temp = head->data;
			head=head->next;
			return temp;
		}
		else
		{
			cout<<"Error: Stack Is Empty"<<endl;
			return 0;
		}
		
	}

	T Show_Head()
	{
		T temp;
		if(!head)
		{
			temp = head->data;
			return temp;
		}
		else
		{
			cout<<"Error: Stack Is Empty"<<endl;
			return 0;
		}
		
	}
		
	void Display()
	{
		if (head)
		{
			Node<T> *current = head;
    		cout<<"LINKED-LIST:"<<endl;
			cout<<current->data<<" -> ";
			current=current->next;
			while (current != NULL) 
    		{
    			cout<<current->data<<" -> ";
				current=current->next;
			}
			cout<<"NULL"<<endl<<endl;
			return;
		}
		cout<<"Error: Head Not Yet Initialized!"<<endl;
	}
		
	void Reverse_List()
	{
		Node<T> *current = head;
		SinglyLinkedList<T> *new_list;
		new_list = new SinglyLinkedList <T> ();
		while (current != NULL)
		{
			new_list->Insert_at_Head(current->data);
			current=current->next;
		}
		head = new_list->head;
	}
};

//Stack Implemented Using Singly Linked List

template <class T>
class Stack
{
	SinglyLinkedList<T> *stk;
	
	public:
	Stack()
	{
		stk = new SinglyLinkedList <T> ();			
	}
	
	~Stack()
	{
		if(stk)
			delete stk;
		stk=NULL;
	}
	
	void Push(T data)
	{
		stk->Insert_at_Head(data);
	}
	
	T Pop()
	{
		T temp;
		temp = stk->Delete_from_Head();
		return temp;
	}
	
	T Peek ()
	{
		T temp;
		temp = stk->Show_Head();
		return temp;	
	}
		
};

int main ()
{
	Stack <int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	
	cout<<s.Pop()<<endl;
	cout<<s.Pop()<<endl;
	cout<<s.Pop()<<endl;
	cout<<s.Pop()<<endl;
}
