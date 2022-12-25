/* Max Heap Program */

#include<iostream>
using namespace std;

class MaxHeap
{
		int *arr;
		int size;
		int capacity;
	
	public:
		MaxHeap(int cap)
		{
			arr = new int (cap);
			size=0;
		}
		
		void Insert(int data)
		{
			arr[size]=data;
			size++;
			down_heap();
		}
		
		int Get_Max()
		{
			int temp=arr[0];
			size--;
			up_heap();
			return temp;
		}
		
		void up_heap()
		{
			
		}
		
		void down_heap()
		{
			
		}
		
};

int main ()
{
	
}
