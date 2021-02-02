#include "catch.hpp"
#include "TDDKata.h"

TEST_CASE("An empty string returns zero", "[TDDKKata]") {
	REQUIRE(TDDKata("") == 0);
}

TEST_CASE("A single number returns the value", "[TDDKKata]") {
	REQUIRE(TDDKata("1") == 1);
	REQUIRE(TDDKata("5") == 5);
	REQUIRE(TDDKata("100") == 100);
}

TEST_CASE("Two numbers, comma delimited, returns the sum", "[TDDKKata]") {
	REQUIRE(TDDKata("0,1") == 1);
	REQUIRE(TDDKata("25,5") == 30);
	REQUIRE(TDDKata("5,10") == 15);
}

TEST_CASE("Two numbers, newline delimited, returns the sum", "[TDDKKata]") {
	REQUIRE(TDDKata("0\1") == 1);
	REQUIRE(TDDKata("25\5") == 30);
	REQUIRE(TDDKata("5\10") == 15);
}

TEST_CASE("Three numbers, delimited either way, returns the sum", "[TDDKKata]") {
	REQUIRE(TDDKata("3,5,2") == 10);
	REQUIRE(TDDKata("10,20,30") == 60);
	REQUIRE(TDDKata("3\n5\n2") == 10);
	REQUIRE(TDDKata("10\n20\n30") == 60);
}
