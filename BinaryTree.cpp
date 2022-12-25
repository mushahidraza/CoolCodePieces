//PROGRAM CODE FOR BINARY TREE

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

template <class T>
class BinaryTree;

// Class of BT Nodes

template <class T>
class TNode
{
	private:
	T data;
	TNode <T> *left;
	TNode <T> *right;
	friend class BinaryTree<T>;
	
	public:
	TNode()
	{
		left = NULL;
		right = NULL;
	}
	
	TNode(T data)
	{
		this->data = data;
		left = NULL;
		right= NULL;
	}
		
};

//Class of BinaryTree

template <class T>
class BinaryTree
{
	private:
	TNode<T> *root;
	
	TNode<T>* Copy_Tree(TNode<T> *_root)
	{
		TNode<T> *new_ptr, *new_left, *new_right;
		
		if (_root == NULL)
			return _root;
			
		if(_root->left != NULL)
			new_left = Copy_Tree(_root->left);
		else 
			new_left = NULL;
		
		if(_root->right != NULL)
			new_right = Copy_Tree(_root->right);
		else new_right = NULL;
		
		new_ptr = new TNode<T> (_root->data);
		new_ptr->left = new_left;
		new_ptr->right = new_right;
		return (new_ptr);
	}
	
	void Delete_Tree (TNode<T> *_root)
	{
		if(_root)
		{
			Delete_Tree(_root->left);
			Delete_Tree(_root->right);
			_root->left=NULL;
			_root->right=NULL;
			delete _root;
			root=NULL;
		}
	}
	
	public:
	
	BinaryTree() { root=NULL;	}
	
	BinaryTree(const BinaryTree<T> &rhs) { root = Copy_Tree(rhs.root); }
	
	~BinaryTree()
	{
		if(root)
			Delete_Tree(root);
		root = NULL;
	}
	
	BinaryTree<T> operator = (const BinaryTree<T> &rhs)
	{
		if(this->root != rhs.root)
			this->root = Copy_Tree(rhs.root);
		return rhs;
	}
			
	void Insert_Data(T data)
	{	
		if (root == NULL)
			root = new TNode<T> (data);
	
		else
		{
			TNode<T> *current = NULL;
			Queue <TNode<T>*> Q;
			Q.EnQueue(root);
			while (!Q.is_empty())
			{
				current = Q.DeQueue();			
				if(current->left != NULL)
				{
					Q.EnQueue(current->left);
				}
				else
				{
					current->left = new TNode <T> (data);
					return;
				}
					
				if(current->right != 0)
				{
					Q.EnQueue(current->right);
				}
				else
				{
					current->right = new TNode <T> (data);
					return;
				}
			}
		}
	}	
	
	bool Search(TNode<T>*_root, T data)
	{
		if(_root == NULL)
			return false;
		else if (_root->data == data)
			return true;
		else
			return (Search(_root->left, data) || Search(_root->right, data));
	}
	
	bool IsBST(TNode<T> *_root)  
	{  
		if(Is_BST_Until(_root, INT_MIN, INT_MAX))
	    return true;  
	    return false;
	}  
	
	int Is_BST_Until(TNode<T>* node, int min, int max)  
	{  
    	if (node==NULL)  
    	    return true;  
              
    	if (node->data < min || node->data > max)  
    	    return false;  
      
	    return(
	        Is_BST_Until(node->left, min, node->data-1) && // Allow only distinct values  
	        Is_BST_Until(node->right, node->data+1, max)); // Allow only distinct values  
	}
		
	void DisplayTree(TNode<T> *_root)
	{
		if(_root != NULL)		//In Order
		{
			DisplayTree(_root->left);
			cout<<_root->data<<" ";		//Displays Tree In Order
			DisplayTree(_root->right);
		}	
	}
	
	TNode<T>* Get_Root() { return (root); }	//Getter Function Of Root
};


//DRIVER PROGRAM
int main ()
{
	BinaryTree <int> bt;
	bt.Insert_Data(1);
	bt.Insert_Data(2);
	bt.Insert_Data(3);
	bt.Insert_Data(4);
	bt.Insert_Data(5);
	bt.Insert_Data(6);
	bt.Insert_Data(7);
	bt.Insert_Data(8);
		
	bt.DisplayTree(bt.Get_Root());
	cout<<endl;
	BinaryTree <int> bt2;
	bt2=bt;
	bt2.DisplayTree(bt2.Get_Root());
	if(bt.Search(bt.Get_Root(),5))
		cout<<endl<<"YES!"<<endl;
	else
		cout<<endl<<"NO!"<<endl;
}
