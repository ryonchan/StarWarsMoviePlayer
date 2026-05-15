// Copyright (c) 2025 Nathan Greenfield. All rights reserved
#pragma once
#include <sstream>

template <typename T>
class smcList
{
private:
	// Node only used internally to list
	struct Node
	{
		// Data in this node
		T mData;
		// Link to previous node
		Node* mPrev;
		// Link to next node
		Node* mNext;
	};

	// Pointer to the head node
	Node* mHead;
	// Pointer to the tail node
	Node* mTail;
	// Number of nodes currently in the list
	unsigned mSize;

public:
	// Iterator helper class...
	class Iterator
	{
	private:
		Node* mCurr;

	public:
		// Needed for List access
		friend class smcList;

		// Constructors
		Iterator()
		{
			mCurr = nullptr;
		}

		Iterator(Node* inCurr) //parameterized constructor
		{
			mCurr = inCurr;
		}

		Iterator(const Iterator& src) //copy constructor
		{
			mCurr = src.mCurr;
		}

		// Assignment operator
		Iterator& operator=(const Iterator& src)
		{
			mCurr = src.mCurr;
			return *this; 
		}

		// Incrementors / Decrementors
		// ++i
		Iterator& operator++()
		{
			mCurr = mCurr -> mNext;
			return *this;
		}

		// i++
		Iterator operator++(int)
		{
			Iterator copy = *this;
			mCurr = mCurr -> mNext;
			return copy; 
		}

		// --i
		Iterator& operator--()
		{
			mCurr = mCurr -> mPrev;
			return *this; 
		}

		// i--
		Iterator operator--(int)
		{
			Iterator copy = *this; //make a copy of the current object
			mCurr = mCurr -> mPrev; //shift the node pointer of current element to prev
			return copy; 
		}

		// Dereference
		T& operator*() const
		{
			return mCurr -> mData; //dereference mCurr and access
		}

		Node* operator->() const
		{
			return mCurr; // -> removes the need to put * in front of the object
		}

		// Comparison
		bool operator==(const Iterator& rhs) const //right hand side
		{
			if(this -> mCurr == rhs.mCurr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator!=(const Iterator& rhs) const
		{
			if(this -> mCurr != rhs.mCurr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	};

	// List functions...

	// Function: Default Constructor
	// Purpose: Initializes size to 0 and head/tail to null
	// Input: None
	// Returns: Nothing
	smcList()
	{
		mHead = nullptr;
		mTail = nullptr;
		mSize = 0;
	}

	// Function: Copy Constructor
	// Purpose: Initializes this list as a deep copy of other
	// Input: Other list to copy (const reference)
	// Returns: Nothing
	smcList(const smcList& other)
	{
		// TODO: Fill in
	}

	// Function: Destructor
	// Purpose: Cleans up memory when the list falls out of scope
	// Input: None
	// Returns: Nothing
	~smcList()
	{
		// TODO: Fill in
	}

	// Function: clear
	// Purpose: Deletes every node in this list, sets size to 0, and head/tail to null
	// Input: None
	// Returns: Nothing
	void clear()
	{
		mHead = nullptr;
		mTail = nullptr;
		mSize = 0;

	}

	// Assignment Operator
	// Function: Assignment Operator
	// Purpose: Clear this list, and then make a deep copy of other
	// Input: Other list to copy (const reference)
	// Returns: *this
	smcList& operator=(const smcList& other)
	{
		// TODO: Fill in
		return *(new smcList); // FIX RETURN VALUE
	}

	// Function: size
	// Purpose: Gets the current size of the linked list
	// Input: None
	// Returns: size of the list
	unsigned size() const
	{
		return mSize;
	}

	// Function: push_front
	// Purpose: Inserts a node at the front of the linked list
	// Input: Value to store in the new node
	// Returns: Nothing
	void push_front(const T& value)
	{
		// TODO: Fill in
	}

	// Function: front
	// Purpose: Gets the value of the node at the front of the list
	// Input: None
	// Returns: Value of the node at the front of the list
	T& front()
	{
		// TODO: Fill in
		return *(new T()); // FIX RETURN VALUE
	}

	// Function: pop_front
	// Purpose: Removes the node at the front of the list
	// Input: None
	// Returns: None
	void pop_front()
	{
		// TODO: Fill in
	}

	// Function: push_back
	// Purpose: Inserts a node at the end of the linked list
	// Input: Value to store in the new node
	// Returns: Nothing
	void push_back(const T& value)
	{
		// TODO: Fill in;
	}

	// Function: back
	// Purpose: Gets the value of the node at the back of the list
	// Input: None
	// Returns: Value of the node at the front of the list
	T& back()
	{
		// TODO: Fill in
		return *(new T()); // FIX RETURN VALUE
	}

	// Function: pop_back
	// Purpose: Removes the node at the back of the list
	// Input: None
	// Returns: None
	void pop_back()
	{
		// TODO: Fill in;
	}

	// Function: begin
	// Purpose: Gets an iterator for the start of the list
	// Input: None
	// Returns: Iterator pointing to beginning of list
	Iterator begin() const
	{
		// TODO: Fill in
		return *(new Iterator); // FIX RETURN VALUE
	}

	// Function: end
	// Purpose: Gets an iterator for the end of the list
	// Input: None
	// Returns: Iterator pointing to end of list
	Iterator end() const
	{
		// TODO: Fill in
		return *(new Iterator); // FIX RETURN VALUE
	}

	// Function: erase
	// Purpose: Removes the item at the node pointed to by i
	// Input: Iterator pointing to a valid node to remove
	// Returns: A new iterator pointing to the node after the removed item
	Iterator erase(Iterator& i)
	{
		// TODO: Fill in
		return *(new Iterator); // FIX RETURN VALUE
	}

	// Function: insert
	// Purpose: Inserts a list item before node pointed to by i
	// Input: Iterator pointing to a valid node to insert before
	// Returns: A new iterator pointing to the inserted value
	Iterator insert(Iterator& i, const T& val)
	{
		// TODO: Fill in
		return *(new Iterator); // FIX RETURN VALUE
	}

public:
	// Function: Output Stream Operator
	// Purpose: Prints the contents of the list to the provided stream
	// Written in the format of {x, y, ..., z}
	// Input: Stream to write to, list to write
	// Output: Stream after values are written
	friend std::ostream& operator<<(std::ostream& os, const smcList<T>& list)
	{
		os << "{";
		Iterator i = list.begin(); //i now references the first element of the list
		for(i; i != list.end(); i++)
		{
			os << *i;
			Iterator next = i; 
			next++;
			if(next != list.end())
			{
				os << ", ";
			}
		}
		os << "}";
		
		return os;
	}

	// Function: toString
	// Purpose: Converts list to a string
	// Input: None
	// Output: String (in the format as the ostream)
	std::string toString() const
	{
		std::stringstream listString;
		listString << *this; //understand this

		return listString.str();
	}

	// Function: toReverseString
	// Purpose: Outputs the list in reverse
	// Input: None
	// Output: String in reverse
	std::string toReverseString() const
	{	
		std::stringstream listString;
		listString << "{";
		Iterator i = end();
		--i;  //start at last element
		while (true)
		{
			listString << *i;
			if (i == begin())
			{
				break;
			}
			listString << ", ";
			--i;
		}
		listString << "}";

		return listString.str();
	}
};