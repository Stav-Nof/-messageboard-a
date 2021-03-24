#include "doctest.h"
#include "Board.hpp"
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("Test empty board")
{
    Board board;
    CHECK(board.read(/*row*/ 0, /*column*/ 0, Direction::Horizontal, 0) == string(""));
    CHECK(board.read(/*row*/ 1, /*column*/ 1, Direction::Vertical, 0) == string(""));
    CHECK(board.read(/*row*/ 2, /*column*/ 2, Direction::Horizontal, 2) == string("__"));
    CHECK(board.read(/*row*/ 3, /*column*/ 3, Direction::Vertical, 3) == string("___"));
}


TEST_CASE("Test Vertical")
{
    Board board;
    board.post(1, 1, Direction::Vertical, "Vertical");
    CHECK(board.read(/*row*/ 1, /*column*/ 0, Direction::Horizontal, 2) == string("_V"));
    CHECK(board.read(/*row*/ 2, /*column*/ 0, Direction::Horizontal, 2) == string("_e"));
    CHECK(board.read(/*row*/ 3, /*column*/ 1, Direction::Horizontal, 2) == string("r_"));
    CHECK(board.read(/*row*/ 4, /*column*/ 0, Direction::Horizontal, 3) == string("_t_"));
    CHECK(board.read(/*row*/ 4, /*column*/ 1, Direction::Vertical, 2) == string("ti"));
    CHECK(board.read(/*row*/ 4, /*column*/ 1, Direction::Vertical, 3) == string("tic"));
    CHECK(board.read(/*row*/ 4, /*column*/ 1, Direction::Vertical, 4) == string("tica"));
    CHECK(board.read(/*row*/ 4, /*column*/ 1, Direction::Vertical, 5) == string("tical"));
}

TEST_CASE("Test Horizontal")
{
    Board board;
    board.post(1, 1, Direction::Horizontal, "Horizontal");
    CHECK(board.read(/*row*/ 1, /*column*/ 0, Direction::Horizontal, 2) == string("_H"));
    CHECK(board.read(/*row*/ 1, /*column*/ 0, Direction::Horizontal, 3) == string("_Ho"));
    CHECK(board.read(/*row*/ 1, /*column*/ 1, Direction::Horizontal, 5) == string("Horiz"));
    CHECK(board.read(/*row*/ 1, /*column*/ 5, Direction::Horizontal, 3) == string("zon"));
    CHECK(board.read(/*row*/ 1, /*column*/ 1, Direction::Vertical, 1) == string("H"));
    CHECK(board.read(/*row*/ 1, /*column*/ 1, Direction::Vertical, 2) == string("H_"));
    CHECK(board.read(/*row*/ 1, /*column*/ 4, Direction::Vertical, 3) == string("_i_"));
    CHECK(board.read(/*row*/ 0, /*column*/ 3, Direction::Vertical, 2) == string("_r"));
}

TEST_CASE("Test Horizontal and Vertical")
{
    Board board;
    board.post(5, 5, Direction::Horizontal, "abcde");
    board.post(3, 7, Direction::Vertical, "xyzw");
    CHECK(board.read(/*row*/ 5, /*column*/ 6, Direction::Horizontal, 2) == string("bz"));
    CHECK(board.read(/*row*/ 3, /*column*/ 6, Direction::Horizontal, 2) == string("_x"));
    CHECK(board.read(/*row*/ 6, /*column*/ 6, Direction::Horizontal, 3) == string("_w_"));
    CHECK(board.read(/*row*/ 5, /*column*/ 7, Direction::Horizontal, 4) == string("zde_"));
    CHECK(board.read(/*row*/ 2, /*column*/ 7, Direction::Vertical, 6) == string("_xyzw_"));
    CHECK(board.read(/*row*/ 5, /*column*/ 7, Direction::Vertical, 1) == string("z"));
    CHECK(board.read(/*row*/ 4, /*column*/ 6, Direction::Vertical, 3) == string("_b_"));
    CHECK(board.read(/*row*/ 5, /*column*/ 9, Direction::Vertical, 2) == string("e_"));
}