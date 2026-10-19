#include "catch.hpp"
#include "SMCDoubleList.hpp"
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <movie.h>

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA, const std::string& fileNameB);

// Your tests -- only add sections
TEST_CASE("Student tests", "[student]")
{
	// Complete tests are worth 2 points for each test
 

	SECTION("Default constructor, size, and destructor")
	{
		smcList<int> list;
		REQUIRE(list.size() == 0); //size should be 0
	}

	SECTION("Push_front, front, back")
	{
		smcList<int> list;
		list.push_front(1);
		list.push_front(5);
		list.push_front(10); //push 3 elements
		REQUIRE(list.front() == 10); //check first in the list
		REQUIRE(list.back() == 1); //check last in the list
		REQUIRE(list.size() == 3); //check list size
	}

	SECTION("Push_front, front, back, pop_front")
	{
		smcList<int> list;

		list.push_front(3); //push 2 elements 
		list.push_front(6);
		list.pop_front(); //pop 1
		REQUIRE(list.front() == 3); //check front
		REQUIRE(list.size() == 1); //check size
	}

	SECTION("Push_back, front, back")
	{
		smcList<int> list;

		list.push_back(1);
		list.push_back(2);
		list.push_back(3); //push 3 elemtns

		REQUIRE(list.front() == 1); //check front
		REQUIRE(list.back() == 3); //check back
		REQUIRE(list.size() == 3); //check size
	}

	SECTION("Push_back, front, back, pop_back")
	{
		smcList<int> list;

		list.push_back(1);
		list.push_back(2); //push 2 elements
		REQUIRE(list.front() == 1); //check front
		REQUIRE(list.back() == 2); //check back
		list.pop_back(); 

		REQUIRE(list.size() == 1); //check size
	}

	SECTION("Push_back, clear")
	{
		smcList<int> list;
		list.push_back(1);
		list.push_back(2); //push 2 elements
		list.clear();
		REQUIRE(list.size() == 0); //size should be 0
	}

	SECTION("Push_back, front, back, pop_back, copy constructor")
	{
		smcList<int> list;
		list.push_back(1);
		list.push_back(2); //push 2 elements
		REQUIRE(list.front() == 1);
		REQUIRE(list.back() == 2);

		smcList<int> copy(list); //make a copy
		REQUIRE(copy.front() == 1);
		REQUIRE(copy.back() == 2);
		copy.pop_back();
		REQUIRE(copy.size() == 1); //size should be 1 after pop back
	}

	SECTION("Push_back, front, back, pop_back, assignment")
	{
		smcList<int> list;
		list.push_back(1);
		list.push_back(2);
		REQUIRE(list.front() == 1);
		REQUIRE(list.back() == 2); //check front and back

		smcList<int> copy;
		copy = list; //assign copy to list
		REQUIRE(copy.front() == 1);
		REQUIRE(copy.back() == 2);
		REQUIRE(copy.size() == 2);
	}

	SECTION("Back, front, pop_front, pop_back, exceptions")
	{


	}

	SECTION("Push_front, front, back, begin, iterator dereference, copy constructor")
	{
		smcList<int> list;
		list.push_front(1);
		list.push_front(2); //push 2 elements

		REQUIRE(list.front() == 2);
		REQUIRE(list.back() == 1); //check front and back

		smcList<int>::Iterator i = list.begin(); //iterator starting at the beginning of list
		REQUIRE(*i == 2); 
		smcList<int> copy(list);  //copy of list

    	REQUIRE(copy.front() == 2);
   		REQUIRE(copy.back() == 1);
		REQUIRE(copy.size() == 2);
	}

	SECTION("List: begin, end; Iterator: dereference, assignment, comparison")
	{
		smcList<int> list;
		list.push_back(1);
		list.push_back(2);

		smcList<int>::Iterator i = list.begin();
		smcList<int>::Iterator i2 = i;
		REQUIRE(i == i2);
		REQUIRE(*i2 == 1); 
	}

	SECTION("List: begin, end; Iterator: dereference, increment")
	{
		smcList<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3); //push 3 elements

		smcList<int>::Iterator i = list.begin(); //i starts at beginning
		REQUIRE(*i == 1); //dereference i should be 1
		++i;
		REQUIRE(*i == 2); 
		++i;
		REQUIRE(*i == 3); //check if i increments appropriately
	}

	SECTION("List: begin, end; Iterator: dereference, increment, decrement")
	{
		smcList<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3); //push 3 elements

		smcList<int>::Iterator i = list.begin(); //i starts at beginning
		++i;
		++i;
		REQUIRE(*i == 3);
		--i;
		REQUIRE(*i == 2);
		--i;
		REQUIRE(*i == 1);
	}

	SECTION("List: insert with iterator at begin, middle, and one away from end")
	{
		smcList<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);

		smcList<int>::Iterator i = list.begin();
		list.insert(i, 0);
		REQUIRE(list.front() == 0);
		REQUIRE(list.size() == 4);

		i = list.begin();
		++i;
		++i;

		list.insert(i, 5);
		REQUIRE(list.toString() == "{0,1,5,2,3}");
	}

	SECTION("List: erase with iterator at begin, middle, and one away from end")
	{
		smcList<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3); //push 3 elements

		smcList<int>::Iterator i = list.begin();
		list.erase(i); //erase
		REQUIRE(list.front() == 2);
		REQUIRE(list.size() == 2);

		list.push_back(4);
		i = list.begin();
		++i;
		++i;
		list.erase(i); // list was {2,3,4}; erasing the tail leaves {2,3}
		REQUIRE(list.back() == 3);
		REQUIRE(list.size() == 2);
	}
}

TEST_CASE("Student movie", "[student]")
{
	SECTION("Bad constructor")
	{
		REQUIRE_THROWS_AS(MoviePlayer("input/does_not_exist.ani"), std::invalid_argument);
	}

	SECTION("Creating scene 2")
	{
		MoviePlayer player("input/scene2.ani");
		REQUIRE(player.getNumFrames() == 69); // 36 unique frames expanded by repeat counts
		REQUIRE(player.getFrameSize() == 13);
		REQUIRE(player.getCurrFrameNum() == 1);
	}

	SECTION("Checking frames, scene 2")
	{
		MoviePlayer player("input/scene2.ani");
		std::string first = player.getCurrFrame();
		REQUIRE(std::count(first.begin(), first.end(), '\n') == 13);

		player.goBack(); // can't move before the first frame
		REQUIRE(player.getCurrFrameNum() == 1);

		for (unsigned i = 0; i < 100; i++)
		{
			player.goFwrd(); // can't move past the last frame
		}
		REQUIRE(player.getCurrFrameNum() == player.getNumFrames());

		player.rewind();
		REQUIRE(player.getCurrFrameNum() == 1);
		REQUIRE(player.getCurrFrame() == first);
	}

	SECTION("Copy and delete frames")
	{
		MoviePlayer player("input/scene2.ani");
		unsigned start = player.getNumFrames();
		player.copyCurrFrame();
		REQUIRE(player.getNumFrames() == start + 1);
		player.delCurrFrame();
		REQUIRE(player.getNumFrames() == start);
	}

	SECTION("Full movie loads")
	{
		MoviePlayer player("input/starwar.ani");
		REQUIRE(player.getNumFrames() == 15475);
	}
}
