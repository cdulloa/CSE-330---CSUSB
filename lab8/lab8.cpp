
#include "Set.cpp"

// implement print function which use iterator to print every element in a set.
template <typename C>
void print(const Set<C>& s)
{
	for (typename Set<C>::iterator i = s.begin(); i != s.end(); ++i)
		cout << *i << ", ";
	cout << endl;
}

// overload set operator + which returns a new set which is the union of two sets.
template <typename C>
Set<C> operator+(const Set<C> & s1, const Set<C> & s2)
{
	Set<C> values; 

	for (typename Set<C>::iterator i = s1.begin(); i != s1.end(); ++i)
	{
		values.insert(*i);
	}
	for (typename Set<C>::iterator i = s2.begin(); i != s2.end(); ++i)
	{
		values.insert(*i);
	}

	return values;
}

// overload set operator - which returns the set difference between two sets.
template <typename C>
Set<C> operator-(const Set<C>& s1, const Set<C>& s2)
{
	Set<C> values; 

	for (typename Set<C>::iterator i = s1.begin(); i != s1.end(); ++i)
	{
		if (!s2.contains(*i)) 
			values.insert(*i);
	}
	return values;
}

// implement set intersection function which returns the intersection of two sets.
template <typename C>
Set<C> Intersection(const Set<C>& s1, const Set<C>& s2)
{
	Set<C> values; 
	
	for (typename Set<C>::iterator i = s1.begin(); i != s1.end(); ++i)
	{
		if (s2.contains(*i)) 
			values.insert(*i);
	}
	return values;
}


int main()
{
	//declares two instances of Set to hold integer values
	Set<int> setOne;
	Set<int>setTwo;
	int val = 0;
	// prompts user to enter random sequence of integer values, 
	//insert these values into two new declared sets
	cout << "insert the values to SetOne (stop when entering 0): " << endl;
	cin >> val;
	while (val != 0)
	{
		setOne.insert(val);
		cin >> val;
	}
	cout << "print the values: " << endl;
	print(setOne); //calls the print() function to print out the values

	cout << "\ninsert the values to SetTwo (stop when entering 0): " << endl;
	cin >> val;
	while (val != 0)
	{
		setTwo.insert(val);
		cin >> val;
	}

	cout << "print the values: " << endl;
	print(setTwo); //calls the print() function to print out the values
	
	// calls three functions to return the union, 
	//the difference and the intersection of two sets, and print these sets. 
	Set<int> unionSet = setOne + setTwo;
	cout << "\n\nThe union of two sets: ";
	print(unionSet);

	Set<int> diff = setOne - setTwo;
	cout << "The difference of two sets: ";
	print(diff);

	Set<int> inter = Intersection(setOne, setTwo);
	cout << "The intersection of two sets: ";
	print(inter);

	return 0;

}
