//Program Code of Singly Linked List
#include<iostream>
using namespace std;

template <class T>
class SinglyLinkedList;

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
	
	SinglyLinkedList()
	{
		this->head = NULL;
	}
	
	~SinglyLinkedList()
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
		
	void Insert_at_End(T data)
	{
    	if (!head) 
		{
			head = new Node<T>();
			head->data= data;
			head->next= NULL;
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
	
	
	void BubbleSort()
	{
		if(head)
		{
			Node<T> *current, *forward; 
			T	temp; 
			bool swapped = false;
			for(current=head; current!=NULL; current=current->next)
			{
				swapped = false;
				for(forward=head; forward->next!=NULL; forward=forward->next)
				{
					if(forward->data > forward->next->data)
					{
						swapped = true;
						SwapNodes(forward, forward->next);
//						temp = forward->data;
//						forward->data = forward->next->data;
//						forward->next->data = temp;
					}
				}
				if (swapped == false)
				break;
			}
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

//Driver Program
int main ()
{
	SinglyLinkedList <int> list;
	
	
	list.Insert_at_Head(6);
	list.Insert_at_End(1);
	list.Insert_at_End(5);
	list.Insert_at_End(3);
	list.Insert_at_End(4);
	list.Insert_at_End(2);
	list.Insert_at_End(9);
	
	list.Display();
	list.Reverse_List();
	list.Display();
	exit(0);
}
