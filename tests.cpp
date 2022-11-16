#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Task A"){
    CHECK(minutesSinceMidnight( {10, 0} ) == 600);
    CHECK(minutesUntil( {10, 30}, {13, 40} ) == 190);
}

TEST_CASE("Task B"){
    Time before = addMinutes({8, 10}, 75);
    Time after = {9, 25};
    
    CHECK((before.h == after.h && before.m == after.m));
}