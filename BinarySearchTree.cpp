//PROGRAM CODE FOR BINARY SEARCH TREE
#include<fstream>
#include<iostream>
using namespace std;

template <class T>
class BinarySearchTree;

template <class T>
class NodeHolder;


// Class of BST Nodes

template <class T>
class TNode
{
	private:
	T data;
	TNode <T> *left;
	TNode <T> *right;
	friend class BinarySearchTree<T>;
	
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

//Class of BinarySearchTree

template <class T>
class BinarySearchTree
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
			delete _root;
		}
	}
	
	public:
	
	BinarySearchTree() { root=NULL;	}
	
	BinarySearchTree(const BinarySearchTree<T> &rhs) { root = Copy_Tree(rhs.root); }
	
	~BinarySearchTree()
	{
		if(root)
			Delete_Tree(root);
		root = NULL;
	}
	
	TNode<T>* operator = (const BinarySearchTree <T> &rhs)
	{
		if(root != rhs.root)
			return Copy_Tree(rhs.root);
	}
	
	void Delete_Node(T data)
	{
		TNode<T> *current = root, *prev=NULL;
	
		while ((current != NULL) && (current->data != data))
		{
			/* Looping To Get To Corrent Node */		
			prev = current;				//hold the value of parent node of p so data can be added
			if (data >= current->data)
				current = current->right;
			else
				current = current->left;
		}	
						
		if (current == NULL)
				return;				
		else 
		{
			if (current->left == NULL && current->right==NULL)		//Case 1 : Leaf Node
			{
				if(current == root)
				{
					root = NULL;
					return;
				}
				
				if(prev->left->data == data)
					prev->left = NULL;
				else
					prev->right = NULL;
			}
			
			else if(current->left == NULL)							//Case 2a: Node Has One Child
			{
				if(current == root)
				{
					root=root->right;
					return;	
				}
				
				if(prev->left->data == data)
					prev->left = current->right;
				else
					prev->right = current->right;
			}
			
			else if(current->right == NULL)							//Case 2b: Node Has Only One Child
			{
				if(current == root)
				{
					root=root->left;
					return;	
				}
				
				if(prev->left->data == data)
					prev->left = current->left;
				else
					prev->right = current->left;
			}
			
			else if(current->right != NULL && current->left != NULL)	//Case 3: Node Has 2 Children
			{
				TNode<T> *Min = Get_Min(current->right);
				Delete_Node(Min->data);
				if (current == root)		//If Root is to be deleted
				{
					Min->left=root->left;
					Min->right=root->right;
					root=Min;
					return;
				}
				
				if(prev->left->data == data)
				{
					prev->left = Min;
					Min->right = current->right;
					Min->left = current->left;
				}
				else
				{
					prev->right = Min;
					Min->right = current->right;
					Min->left = current->left;
				}
			}			
		}
		return;
	}
	
	TNode<T>* Get_Max(TNode<T> *_root)
	{
		TNode<T> *current = _root;
		if(root)
		{
			while (current->right != NULL)
				current=current->right;
			return current;
		}
		else
		return 0;
	}

	TNode<T>* Get_Min(TNode<T> *_root)
	{	
		TNode<T> *current = _root;
		if(_root)
		{
			while (current->left != NULL)
				current=current->left;
			return current;
		}
		else
		return 0;
	}
		
	void Insert_Data(T data)
	{	
		TNode<T> *new_node = new TNode<T> (data);
		if(root)
		{
			TNode<T> *current = root;
			TNode<T> *parent = NULL;
			while (current != NULL)
			{
				parent = current;
				if (data >= current->data)
					current = current->right;
				else
					current = current->left;
			}
			if(data >= parent->data)
				parent->right = new_node;
			else
				parent->left = new_node;
		}
		else
			root = new_node;			 
	}	
	
	bool Search(TNode<T>*_root, T data)
	{
		if (_root == NULL)
			return false;
		if (_root->data == data)
			return true;
		if (_root->data > data)
			Search(_root->left, data);
		else
			Search(_root->right, data);
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
			cout<<_root->data<<" ";	//Displays Tree In Order
			DisplayTree(_root->right);
		}	
	}
	
	NodeHolder<T> Get_Largest(TNode<T>* _root)
	{
		NodeHolder<T> dummy;
		if (_root)
		{
			NodeHolder<T> temp1,temp2;
			temp1.KeepNode(_root);
			temp2.KeepNode(_root);
			TNode<T>*current = _root;
			while(current)
			{
				temp1.Insert(current->data);
				current=current->right;
			}
//			temp1.Display();
			
			current = _root;
			while(current != NULL)
			{
				temp2.Insert(current->data);
				current=current->left;
			}
//			temp2.Display();
//			NodeHolder<T> temp3;
//			temp3 = temp2;
//			temp3.Display();
		
			NodeHolder<T> temp3 = Get_Largest (_root->right);
			//temp3.Display();
			NodeHolder<T> temp4 = Get_Largest (_root->left);
			//temp4.Display();
			
			if((temp1.size>=temp2.size) && (temp1.size>=temp3.size) && (temp1.size>=temp4.size))
			return temp1;
			
			if((temp2.size>=temp1.size) && (temp2.size>=temp3.size) && (temp2.size>=temp4.size))
			return temp2;
			
			if((temp3.size>=temp1.size) && (temp3.size>=temp2.size) && (temp3.size>=temp4.size))
			return temp3;
			
			if((temp4.size>=temp1.size) && (temp4.size>=temp2.size) && (temp4.size>=temp3.size))
			return temp4;
		}
		else 
			return dummy;
	}
	
	int No_of_LeafNodes (TNode<T> *_root)
	{
		int nodes=0;	
		if(_root)
		{
			nodes += No_of_LeafNodes (_root->left);
			nodes += No_of_LeafNodes (_root->right);
			if(_root->right == NULL  && _root->left == NULL)
				return 1;
			return nodes;
		}
		else
			return nodes;		
	}
	
	int Get_Height(TNode<T> *_root)
	{
		int hleft=0;
		int hright=0;
		if(_root)
		{
			hleft = Get_Height (_root->left);
			hright = Get_Height (_root->right);
			if (hleft>=hright)
				return hleft+1;
			else
				return hright+1;
		}
		else
		return 0;
	}
	
	void Read_File()
	{
		ifstream input;
		T temp;
		input.open("input.txt");
		if (input.is_open())
		{
			while(! input.eof())
			{
				input>>temp;
				this->Insert_Data(temp);
			}
		}
		else
			cout<<"Error: File Couldn't Be Opened!"<<endl;
	}
	
	void Write_File(NodeHolder<T> &obj)
	{
		ofstream output;
		T temp;
		output.open("output.txt");
		if (output.is_open())
		{
			output<<obj.size+1;
			output<<"\n";
			for(int i=0;i<=obj.size;i++)
			{
				output<<obj.data[i]<<" ";
			}
		}
		else
			cout<<"Error: File Couldn't Be Opened!"<<endl;
	}
	
	TNode<T>* Get_Root() { return (root); }	//Getter Function Of Root
};

template<class T>
class NodeHolder
{
	public:
	TNode<T> *Temp;
	T *data;
	int size;
		NodeHolder()
		{
			size = -1;
			Temp = NULL;
			data = new T;
		}
		
		void Insert(T data)
		{
			size++;
			this->data[size] = data;
		}
		
		void Display()
		{
			for (int i=0; i<=size ;i++)
			{
				cout<<this->data[i]<<" ";
			}
			cout<<endl;
		}
		
		void KeepNode(TNode<T> *_root)
		{
			Temp=_root;
		}
		
		void operator = (NodeHolder<T> &rhs)
		{
			if (this != &rhs)
			{
				this->data = rhs.data;
				this->size = rhs.size;
				this->Temp = rhs.Temp;
			}
			return;
		}
};


//DRIVER PROGRAM
int main ()
{
	BinarySearchTree <int> bst;
	bst.Read_File();
//	bst.Insert_Data(7);
//	bst.Insert_Data(4);
//	bst.Insert_Data(12);
//	bst.Insert_Data(9);
//	bst.Insert_Data(6);
//	bst.Insert_Data(5);
//	bst.Insert_Data(2);
//	bst.Insert_Data(3);
//	bst.Insert_Data(19);
//	bst.Insert_Data(15);
//	bst.Insert_Data(20);
//	bst.Insert_Data(8);
//	bst.Insert_Data(11);
	NodeHolder<int> Largest = bst.Get_Largest(bst.Get_Root());
	Largest.Display();
	bst.Write_File(Largest);
//	bst.DisplayTree(bst.Get_Root());	
}
