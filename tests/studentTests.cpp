#include "catch.hpp"

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA, const std::string& fileNameB);

// Your tests -- only add sections
TEST_CASE("Student tests", "[student]")
{
	// Complete tests are worth 2 points for each test
 
	
	SECTION("Default constructor, size, and destructor")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("Push_front, front, back")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("Push_front, front, back, pop_front")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("Push_back, front, back")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("Push_back, front, back, pop_back")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("Push_back, clear")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("Push_back, front, back, pop_back, copy constructor")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("Push_back, front, back, pop_back, assignment")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("Back, front, pop_front, pop_back, exceptions")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("Push_front, front, back, begin, iterator dereference, copy constructor")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("List: begin, end; Iterator: dereference, assignment, comparison")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("List: begin, end; Iterator: dereference, increment")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("List: begin, end; Iterator: dereference, increment, decrement")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("List: insert with iterator at begin, middle, and one away from end")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("List: erase with iterator at begin, middle, and one away from end")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}
}

TEST_CASE("Student movie", "[student]")
{
	SECTION("Bad constructor")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("Creating scene 2")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}

	SECTION("Checking frames, scene 2")
	{
		// TODO: Tests go here
		REQUIRE(true);
	}
}
