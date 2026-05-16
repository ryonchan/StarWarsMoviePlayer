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
		mSize = 0;
		mHead = nullptr;
		mTail = nullptr;
		Node* newNode = other.mHead; //create node that points to head node in "other"
		while (newNode != nullptr) 
		{
			push_back(newNode -> mData); //pushback data from every node
			newNode = newNode -> mNext; //set temp to next node
		}
	}

	// Function: Destructor
	// Purpose: Cleans up memory when the list falls out of scope
	// Input: None
	// Returns: Nothing
	~smcList()
	{
		clear(); //calls clear function
	}

	// Function: clear
	// Purpose: Deletes every node in this list, sets size to 0, and head/tail to null
	// Input: None
	// Returns: Nothing
	void clear()
	{
		while(mSize > 0)
		{
			pop_front(); //remove every element until list size is 0
		}
	}

	// Assignment Operator
	// Function: Assignment Operator
	// Purpose: Clear this list, and then make a deep copy of other
	// Input: Other list to copy (const reference)
	// Returns: *this
	smcList& operator=(const smcList& other)
	{
		clear();
		Node* newNode = other.mHead; //create temp that points to head node in "other"
		while(newNode != nullptr)
		{
			push_back(newNode -> mData); //push_back temp's data into the list
			newNode = newNode -> mNext; //advance temp to next node
		}
		return *this;
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
		Node* newNode = new Node(); //create a new node
		newNode -> mData = value; //equate node's mData to value
		newNode -> mNext = mHead; //equate new node's next to mHead
		newNode -> mPrev = nullptr; //equate new node's prev to nullptr
		if (mSize == 0)
		{
			mTail = newNode; //if size is 0, tail is new node
		}
		else
		{
			mHead -> mPrev = newNode; //otherwise, set prev of current head to new node
		}
		mHead = newNode; //equate new node memory to mHead
		mSize += 1; //increase mSize by 1
	}

	// Function: front
	// Purpose: Gets the value of the node at the front of the list
	// Input: None
	// Returns: Value of the node at the front of the list
	T& front()
	{
		if(mSize == 0)
		{
			throw std::out_of_range("Error: List is empty!");
		}
		else
		{
			return mHead -> mData;
		}
	}

	// Function: pop_front
	// Purpose: Removes the node at the front of the list
	// Input: None
	// Returns: None
	void pop_front()
	{
		if(mSize == 0)
		{
			throw std::out_of_range("Error: List is empty!");
		}
		else if (mSize == 1) //if size is 1, delete headnode, set head/tail to null, size to 0
		{
			delete mHead; 
			mHead = nullptr;
			mTail = nullptr;
			mSize = 0;
		}
		else
		{
			Node* copy = mHead -> mNext; //make a copy of next node
			delete mHead; 
			mHead = copy; //next node becomes mHead
			mHead -> mPrev = nullptr; //mHead previous is nullptr by default
			mSize -= 1;
		}
	}

	// Function: push_back
	// Purpose: Inserts a node at the end of the linked list
	// Input: Value to store in the new node
	// Returns: Nothing
	void push_back(const T& value)
	{
		Node* newNode = new Node();
		newNode -> mData = value; //set its data to value
		newNode -> mPrev = mTail; //set its previous to current tail
		newNode -> mNext = nullptr; //set the next to null
		if (mSize == 0)
		{
			mHead = newNode;
			mTail = newNode;
		}
		else
		{ 
			mTail -> mNext = newNode; //set the next of the current tail to new node
			mTail = newNode; //set the tail to new node
		}
		mSize += 1;
	}

	// Function: back
	// Purpose: Gets the value of the node at the back of the list
	// Input: None
	// Returns: Value of the node at the front of the list
	T& back()
	{
		if(mSize == 0)
		{
			throw std::out_of_range("Error: List is empty!");
		}
		else
		{
			return mTail -> mData;
		}
	}

	// Function: pop_back
	// Purpose: Removes the node at the back of the list
	// Input: None
	// Returns: None
	void pop_back()
	{

		if (mSize == 0)
		{
			throw std::out_of_range("Error: List is empty!");
		}
		else if (mSize == 1)
		{ 
			delete mTail;
			mHead = nullptr;
			mTail = nullptr;
			mSize = 0;
		}
		else
		{
			Node* newNode = mTail -> mPrev; //temp equal to prev node before tail
			delete mTail;
			mTail = newNode; //temp is now new tail
			mTail -> mNext = nullptr;
			mSize -= 1;
		}
	}

	// Function: begin
	// Purpose: Gets an iterator for the start of the list
	// Input: None
	// Returns: Iterator pointing to beginning of list
	Iterator begin() const
	{
		return Iterator(mHead); //points to head node
	}

	// Function: end
	// Purpose: Gets an iterator for the end of the list
	// Input: None
	// Returns: Iterator pointing to end of list
	Iterator end() const
	{
		return Iterator(mTail -> mNext); //points to one past the tail node
	}

	// Function: erase
	// Purpose: Removes the item at the node pointed to by i
	// Input: Iterator pointing to a valid node to remove
	// Returns: A new iterator pointing to the node after the removed item
	Iterator erase(Iterator& i)
	{
		if(i.mCurr == nullptr) //if iterator is invalid
		{
			throw std::out_of_range("Error: Iterator is invalid!");
		}
		else if(i == begin()) //if iterator is at begin
		{
			pop_front();
			return begin();
		}
		else if(i == Iterator(mTail)) //if iterator is at the tail
		{
			pop_back();
			return end();
		}
		else
		{
			Node* after = i.mCurr -> mNext; //after pointer
			Node* before = i.mCurr -> mPrev; //before pointer
			delete i.mCurr;
			before -> mNext = after; //set before's next to after
			after -> mPrev = before; //set after's previous to before
			mSize -= 1;
			return Iterator(after);
		}
	}

	// Function: insert
	// Purpose: Inserts a list item before node pointed to by i
	// Input: Iterator pointing to a valid node to insert before
	// Returns: A new iterator pointing to the inserted value
	Iterator insert(Iterator& i, const T& val)
	{
		if(i.mCurr == nullptr) //if iterator is invalid
		{
			throw std::out_of_range("Error: Iterator is invalid!");
		}
		else if(i == begin()) //if iterator is at begin
		{
			push_front(val);
			return begin();
		}
		else if(i == end()) //if iterator is at end
		{
			push_back(val);
			return Iterator(mTail);
		}
		else
		{
			Node* after = i.mCurr; //after pointer
			Node* before = after -> mPrev; //before pointer
			Node* newNode = new Node(); //dynamically allocate new node
			newNode -> mData = val; //data to val
			newNode -> mPrev = before; //prev to before
			newNode -> mNext = after; //next to after
			before -> mNext = newNode; //for the node before, mNext should be newNode
			after -> mPrev = newNode; //for the node after, mPrev should be newNode
			mSize += 1;
			return Iterator(newNode);
		}
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