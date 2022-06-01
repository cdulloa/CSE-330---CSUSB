// Set.cpp 
// after Mark A. Weiss, Chapter 4, Dr. Kerstin Voigt 
#ifndef SET_H 
#define SET_H 
#include <assert.h> 
#include <iostream> 
#include <stack> 
using namespace std;      
template <typename C> 
class Set 
{  
public:    
	Set( ) : root{ nullptr }    
	{    
	}

	~Set( )    
	{        
		makeEmpty();    
	}    

	bool isEmpty( ) const    
	{        
		return root == nullptr;    
	}     

	const C & findMin( ) const    
	{        
		assert(!isEmpty());        
		return findMin( root )->element;    
	}    

	const C & findMax( ) const    
	{        
		assert(!isEmpty());        
		return findMax( root )->element;    
	}    

	bool contains( const C & x ) const    
	{        
		return contains( x, root );    
	}      
	
	void print( ) const    
	{       
		if( isEmpty( ) )            
			cout << "Empty tree" << endl;        
		else            
			print( root );    
	}    
	
	void makeEmpty( )    
	{        
		makeEmpty( root );    
	}        
	
	void insert( const C & x ) 
	{ 
	insert(x, root); 
	}         

	void remove(const C& x) 
	{ 
	remove(x, root); 
	}  
private:        
	struct BinaryNode 
	{ 
		C element;        
		BinaryNode* left;        
		BinaryNode* right;       
		BinaryNode(const C& d, BinaryNode* lt, BinaryNode* rt) 
			: element(d), left(lt), right(rt) 
		{ } 
	};    

BinaryNode* root;      

public:    class iterator 
{
	public:        
		iterator() : current(nullptr) 
		{}       

		C& operator *() 
		{ 
			return current->element; 
		}        
		// prefix increment ++itr        
		iterator & operator++()        
		{            
			if (current == nullptr)                
				return *this;            
			if (current->right != nullptr)            
			{                
				current = current->right;                
				while (current->left != nullptr)                
				{                   
					antes.push(current);                    
					current = current->left;                
				}            
			}            
			else            
			{                
				if (!antes.empty())                
				{                    
					current = antes.top();                    
					antes.pop();                
				}                
				else                    
					current = nullptr;           
			}            
			return *this;        
		}        

bool operator ==(const iterator & rhs) const        
{            
	return current == rhs.current;       
}        

bool operator !=(const iterator & rhs) const       
{            
	return !(*this == rhs);        
}    

private:        
	BinaryNode* current;
	stack<BinaryNode*> antes;        
	iterator(BinaryNode* p, stack<BinaryNode*> st) : current(p), antes(st) 
	{}            
	
	friend class Set<C>;
};  
	  iterator begin() const 
	  { 
		  BinaryNode* lmost = root;        
		  stack<BinaryNode*> nstack;        
		  
		  while (lmost->left != nullptr) 
		  { 
			  nstack.push(lmost);            
			  lmost = lmost->left; 
		  }        
		  
		  return iterator(lmost, nstack); 
	  }    
	  
	  iterator end() const 
	  { 
		  stack<BinaryNode*> emptystack;        
		  return iterator(nullptr, emptystack); 
	  }

  private:    
	  
	  // Internal method to find the smallest item in a subtree t.    
	  // Return node containing the smallest item.        
	  BinaryNode* findMin( BinaryNode* t ) const    
	  {        
		  if( t == nullptr )            
			  return nullptr;        
		  if( t->left == nullptr )            
			  return t;        
		  return findMin( t->left );    
	  }        
	  
	  // Internal method to find the largest item in a subtree t.    
	  // Return node containing the largest item.    
	  BinaryNode* findMax( BinaryNode* t ) const    
	  {        
		  if( t != nullptr )            
			  while( t->right != nullptr )                
				  t = t->right;        
		  return t;    
	  }    
	  
	  // Internal method to test if an item is in a subtree.    
	  // x is item to search for.    
	  // t is the node that roots the subtree.        
	  bool contains( const C & x, BinaryNode* t ) const    
	  {        
		  if( t == nullptr )            
			  return false;        
		  else if( x < t->element )            
			  return contains( x, t->left );        
		  else if( x > t->element )            
			  return contains( x, t->right );        
		  else            
			  return true;    // Match    
	  }    
	  
	  void print( BinaryNode* t) const    
	  {        
		  if( t != nullptr )        
		  {            
			  print( t->left);            
			  cout << t->element << " - ";            
			  print( t->right);        
		  }    
	  }        
	  
	  void makeEmpty( BinaryNode* & t ) 
	  { 
		  if (t != nullptr) 
		  { 
			  makeEmpty(t->left);            
			  makeEmpty(t->right);            
			  delete t; 
		  }        
		  t = nullptr; 
	  }        
	  
	  // Internal method to insert into a subtree.    
	  // x is the item to insert.    
	  // t is the node that roots the subtree.    
	  // Set the new root of the subtree.        
	  void insert( const C & x, BinaryNode* & t )    
	  {        
		  if( t == nullptr )            
			  t = new BinaryNode( x, nullptr, nullptr );        
		  else if( x < t->element )            
			  insert( x, t->left );        
		  else if( x > t->element )            
			  insert( x, t->right );        
		  else            
			  ;  // Duplicate; do nothing    
	  }        
	  
	  // Internal method to remove from a subtree.    
	  // x is the item to remove.    
	  // t is the node that roots the subtree.    
	  // Set the new root of the subtree.        
	  void remove( const C & x, BinaryNode* & t )    
	  {        
		  if( t == nullptr )            
			  return;   // Item not found; do nothing        
		  if( x < t->element )            
			  remove( x, t->left );       
		  else if( x > t->element )           
			  remove( x, t->right );       
		  else if( t->left != nullptr && t->right != nullptr ) // Two children        
		  {            
			  t->element = findMin( t->right )->element;            
			  remove( t->element, t->right );        
		  }       
		  else        
		  {            
			  BinaryNode* oldNode = t;            
			  if ( t->left == nullptr )               
				  t = t->right;            
			  else              
				  t = t->left;           
			  delete oldNode;        
		  }   
	  } 
}; 
#endif
