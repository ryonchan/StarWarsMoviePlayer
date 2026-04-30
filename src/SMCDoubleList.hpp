// Copyright (c) 2025 Nathan Greenfield. All rights reserved
#pragma once

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
			// TODO: Fill in
		}

		Iterator(Node* inCurr)
		{
			// TODO: Fill in
		}

		Iterator(const Iterator& src)
		{
			// TODO: Fill in
		}

		// Assignment
		Iterator& operator=(const Iterator& src)
		{
			// TODO: Fill in
			return *(new Iterator); // FIX RETURN VALUE
		}

		// Incrementors / Decrementors
		// ++i
		Iterator& operator++()
		{
			// TODO: Fill in
			return *(new Iterator); // FIX RETURN VALUE
		}

		// i++
		Iterator operator++(int)
		{
			// TODO: Fill in
			return *(new Iterator); // FIX RETURN VALUE
		}

		// --i
		Iterator& operator--()
		{
			// TODO: Fill in
			return *(new Iterator); // FIX RETURN VALUE
		}

		// i--
		Iterator operator--(int)
		{
			// TODO: Fill in
			return *(new Iterator); // FIX RETURN VALUE
		}

		// Dereference
		T& operator*() const
		{
			// TODO: Fill in
			return *(new T()); // FIX RETURN VALUE
		}

		Node* operator->() const
		{
			// TODO: Fill in
			return *(new Node); // FIX RETURN VALUE
		}

		// Comparison
		bool operator==(const Iterator& rhs) const
		{
			// TODO: Fill in
			return false; // FIX RETURN VALUE
		}

		bool operator!=(const Iterator& rhs) const
		{
			// TODO: Fill in
			return false; // FIX RETURN VALUE
		}
	};

	// List functions...

	// Function: Default Constructor
	// Purpose: Initializes size to 0 and head/tail to null
	// Input: None
	// Returns: Nothing
	smcList()
	{
		// TODO: Fill in
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
		// TODO: Fill in
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
		// TODO: Fill in
		return 0; // FIX RETURN VALUE
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
		// TODO: Fill in
		return os; // FIX RETURN VALUE
	}

	// Function: toString
	// Purpose: Converts list to a string
	// Input: None
	// Output: String (in the format as the ostream)
	std::string toString() const
	{
		// TODO: Fill in
		return *(new std::string); // FIX RETURN VALUE
	}

	// Function: toReverseString
	// Purpose: Outputs the list in reverse
	// Input: None
	// Output: String in reverse
	std::string toReverseString() const
	{
		// TODO: Fill in
		return *(new std::string); // FIX RETURN VALUE
	}
};