#define CATCH_CONFIG_MAIN
#include "CMakeProject_Catch2.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Empty")
{
    List list;
    REQUIRE(list.Empty() == true);
    list.PushBack(5);
    REQUIRE(list.Empty() == false);
    list.PopBack();
    REQUIRE(list.Empty() == true);
}

TEST_CASE("Size")
{
    List list;
    REQUIRE(list.Size() == 0);
    list.PushBack(5);
    list.PushBack(5);
    list.PushBack(5);
    REQUIRE(list.Size() == 3);
}

TEST_CASE("Clear")
{
    List list;
    list.PushBack(5);
    list.PushBack(6);
    list.PushBack(7);
    REQUIRE(list.Empty() == false);
    list.Clear();
    REQUIRE(list.Empty() == true);
}

TEST_CASE("PushBack")
{
    List list;
    list.PushBack(5);
    list.PushBack(10);
    REQUIRE(list.Size() == 2);
}

TEST_CASE("PushFront")
{
    List list;
    list.PushFront(2);
    list.PushFront(1);
    REQUIRE(list.Size() == 2);
}

TEST_CASE("PopBack on Empty List")
{
    List list;
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
}

TEST_CASE("PopFront on Empty List")
{
    List list;
    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
}

TEST_CASE("Sequential Operations")
{
    List list;

    list.PushBack(5);
    list.PushBack(6);
    list.PushFront(7);

    REQUIRE(list.Size() == 3);

    REQUIRE(list.PopFront() == 7);
    REQUIRE(list.Size() == 2);

    REQUIRE(list.PopBack() == 6);
    REQUIRE(list.Size() == 1);

    REQUIRE(list.PopBack() == 5);
    REQUIRE(list.Empty() == true);
}

TEST_CASE("Push and Pop")
{
    List list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    REQUIRE(list.PopFront() == 1);
    REQUIRE(list.PopFront() == 2);
    REQUIRE(list.PopFront() == 3);

    list.PushFront(5);
    list.PushFront(6);
    REQUIRE(list.PopBack() == 5);
    REQUIRE(list.PopBack() == 6);
}

TEST_CASE("Clear and Push")
{
    List list;
    list.PushBack(1);
    list.PushBack(2);
    list.Clear();
    REQUIRE(list.Empty());
    REQUIRE(list.Size() == 0);

    list.PushBack(3);
    list.PushFront(4);
    REQUIRE(list.Size() == 2);
    REQUIRE(list.PopFront() == 4);
    REQUIRE(list.PopFront() == 3);
}

TEST_CASE("Pop Empty")
{
    List list;
    list.PushBack(10);
    list.Clear();
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
}