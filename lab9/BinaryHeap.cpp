#ifndef BINARY_HEAP_H 
#define BINARY_HEAP_H 
#include <assert.h> 
#include <vector> 
#include <iostream> 
using namespace std; 

// BinaryHeap class 
// 
// CONSTRUCTION: with an optional capacity (that defaults to 100) 
// 
// ******************PUBLIC OPERATIONS********************* 
// void insert( x )       --> Insert x 
// void deleteMin( )   --> Remove smallest item 
// void deleteMin(minItem)--> Remove smallest item and store the minimum in minItem 
// C findMin( )           --> Return smallest item 
// bool isEmpty( )        --> Return true if empty; else false 
// void makeEmpty( )      --> Remove all items 

template <typename C> 
class BinaryHeap 
{  public:    
	BinaryHeap( int capacity = CAP ) : items( capacity ), currentSize( 0 )    
	{   }    
	
	bool isEmpty( ) const    
	{     
		return currentSize == 0;     
	}    
	
	/**     
	* Find the smallest item in the priority queue.     
	* Return the smallest item     
	*/    
	const C & findMin( ) const    
	{        
		assert(!isEmpty());        
		return items[ 1 ];    
	}        
	/**     
	* Insert item x, allowing duplicates.     
	*/    
	void insert( const C & x )    
	{        
		if( currentSize == items.size( ) - 1 )            
			items.resize( items.size( ) * 2 );        
		
		// Percolate up        
		int hole = ++currentSize;        
		C copy = x;               
		items[ 0 ] = copy;       
		for( ; x < items[ hole / 2 ]; hole /= 2 )          
			items[ hole ] = items[ hole / 2 ];      
		items[ hole ] = items[ 0 ];    
	}        
	
	/**
	 * Remove the minimum item.     
	 */    
void deleteMin() 
{ 

	assert(!isEmpty());               

	items[1] = items[currentSize];        
	currentSize = currentSize - 1;        
	percolateDown(1); 
}    

/**     
* Remove the minimum item and place it in minItem.     
*/    
void deleteMin(C& minItem) 
{ 
assert(!isEmpty());        

minItem = items[1];        
items[1] = items[currentSize];        
currentSize = currentSize - 1;        
percolateDown(1); 
}    

void makeEmpty() 
{ 
currentSize = 0; 
}    

// prints out the print jobs in printQueue. 
void printJobs()
{
	cout << "The print jobs: ";
	// print in level Order
	for (int i = 1; i <= currentSize; i++) 
	{
		cout << items.at(i) << " ";
	}
	cout << endl;
}


static const int CAP = 100;    

private:    
	int currentSize;  // Number of elements in heap    
	vector<C> items;  // The heap array    
	
	/**     
	* Establish heap order property from an arbitrary     
	* arrangement of items. Runs in linear time.    
	*/    
	void buildHeap( )    
	{        
		for( int i = currentSize / 2; i > 0; --i )            
			percolateDown( i );    
	}    
	
	/**     
	* Internal method to percolate down in the heap.     
	* hole is the index at which the percolate begins.     
	*/    
	void percolateDown( int hole )   
	{        
		int child;       
		C tmp = items[ hole ];      
		
		for( ; hole * 2 <= currentSize; hole = child )        
		{            
			child = hole * 2;            
			if( child != currentSize && items[ child + 1 ] < items[ child ] )               
				++child;            
			if( items[ child ] < tmp )               
				items[ hole ] = items[ child ];            
			else              
				break;        
		}       
		items[ hole ] = tmp;    
	} 
}; 

#endif
