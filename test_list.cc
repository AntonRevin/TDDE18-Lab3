// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#define CATCH_CONFIG_MAIN
#include <random>
#include "List.h"
#include "catch.hpp"

#include "iostream"

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE("Create an empty list") {
    List l{};

    REQUIRE(l.is_empty() == true);
    REQUIRE(l.size() == 0);
}

TEST_CASE("Create a non-empty list") {
    List l{};
    l.insert(1);
    REQUIRE(l.is_empty() == false);
    REQUIRE(l.size() == 1);
    List l2{};
    l2.insert(-1);
    REQUIRE(l2.is_empty() == false);
    REQUIRE(l2.size() == 1);
}

TEST_CASE("to_string + order") {
    List l{};
    REQUIRE(l.to_string() == "{ }");
    l.insert(1);
    REQUIRE(l.to_string() == "{ 1 }");
    l.insert(2);
    REQUIRE(l.to_string() == "{ 1 2 }");
    l.insert(-2);
    REQUIRE(l.to_string() == "{ -2 1 2 }");
}

TEST_CASE("Insert duplicates and order") {
    List l{};
    l.insert(1);
    l.insert(1);
    REQUIRE(l.to_string() == "{ 1 1 }");
    List l2{};
    l2.insert(5);
    l2.insert(1);
    l2.insert(99);
    l2.insert(0);
    REQUIRE(l2.to_string() == "{ 0 1 5 99 }");
}

TEST_CASE("remove") {
    List l{};
    l.insert(1);
    l.insert(1);
    l.insert(20);
    l.remove(1);
    REQUIRE(l.to_string() == "{ 1 20 }");
    l.remove(20);
    REQUIRE(l.to_string() == "{ 1 }");
    l.insert(2);
    l.remove(1);
    REQUIRE(l.to_string() == "{ 2 }");
    l.remove(2);
    REQUIRE(l.to_string() == "{ }");
    REQUIRE(l.is_empty() == true);
    // remove from an empty list
    l.remove(0);
    REQUIRE(l.is_empty() == true);
}

TEST_CASE("Deep-Copy Assignment") {
    List l{};
    l.insert(1);
    l.insert(2);
    l.insert(3);
    List l2{};
    l2 = l;
    REQUIRE(l.is_empty() == false);
    REQUIRE(l2.is_empty() == false);
    REQUIRE(l.to_string() == "{ 1 2 3 }");
    REQUIRE(l2.to_string() == "{ 1 2 3 }");
    List l3{};
    l = l3;
    REQUIRE(l.is_empty() == true);
    REQUIRE(l3.is_empty() == true);
}

TEST_CASE("Deep-Copy constructor") {
    List l{};
    l.insert(1);
    l.insert(2);
    l.insert(3);
    List l2{l};
    REQUIRE(l.is_empty() == false);
    REQUIRE(l2.is_empty() == false);
    REQUIRE(l.to_string() == "{ 1 2 3 }");
    REQUIRE(l2.to_string() == "{ 1 2 3 }");
    List l3{};
    List l4{l3};
    REQUIRE(l3.is_empty() == true);
    REQUIRE(l4.is_empty() == true);
}

TEST_CASE("Move Assignment") {
    List l{};
    l.insert(2);
    l.insert(1);
    l.insert(3);
    List l2{};
    l2 = std::move(l);
    REQUIRE(l.is_empty() == true);
    REQUIRE(l2.to_string() == "{ 1 2 3 }");
}

TEST_CASE("Move constructor") {
    List l{};
    l.insert(2);
    l.insert(1);
    l.insert(3);
    List l2(std::move(l));
    REQUIRE(l.is_empty() == true);
    REQUIRE(l2.to_string() == "{ 1 2 3 }");
}

TEST_CASE("Clean") {
    List l{};
    l.insert(2);
    l.insert(1);
    l.insert(3);
    l.clean();
    REQUIRE(l.is_empty() == true);
}