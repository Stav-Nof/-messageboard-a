#include "doctest.h"
#include "Board.hpp"
#include <string>

using namespace ariel;
using namespace std;

Board board;
TEST_CASE("Test post and read"){
    
    
    board.post(1, 1, Direction::Vertical, "kneset");
    board.post(8, 2, Direction::Horizontal, "bibi");
    board.post(8, 3, Direction::Vertical, "israel");
    board.post(4, 4, Direction::Vertical, "hello");
   
    CHECK(board.read(/*row*/ 1, /*column*/ 1, Direction::Vertical, 2) == string("kn"));
    CHECK(board.read(/*row*/ 2, /*column*/ 1, Direction::Vertical, 2) == string("ne"));
    CHECK(board.read(/*row*/ 3, /*column*/ 1, Direction::Vertical, 3) == string("ese"));
    CHECK(board.read(/*row*/ 4, /*column*/ 1, Direction::Vertical, 1) == string("s"));
    CHECK(board.read(/*row*/ 5, /*column*/ 1, Direction::Vertical, 2) == string("et"));
    CHECK(board.read(/*row*/ 6, /*column*/ 1, Direction::Vertical, 3) == string("t__"));
    
    CHECK(board.read(/*row*/ 8, /*column*/ 2, Direction::Horizontal, 2) == string("bi"));
    CHECK(board.read(/*row*/ 8, /*column*/ 2, Direction::Horizontal, 4) == string("bibi"));
    CHECK(board.read(/*row*/ 8, /*column*/ 3, Direction::Horizontal, 1) == string("i"));
    CHECK(board.read(/*row*/ 8, /*column*/ 1, Direction::Horizontal, 3) == string("_bi"));
    
    CHECK(board.read(/*row*/ 8, /*column*/ 3, Direction::Vertical, 2) == string("is"));
    CHECK(board.read(/*row*/ 8, /*column*/ 3, Direction::Vertical, 7) == string("israel_"));
    CHECK(board.read(/*row*/ 7, /*column*/ 3, Direction::Vertical, 3) == string("_is"));
    
    CHECK(board.read(/*row*/ 4, /*column*/ 1, Direction::Horizontal, 4) == string("k__h"));
    CHECK(board.read(/*row*/ 5, /*column*/ 1, Direction::Horizontal, 4) == string("e__e"));
    CHECK(board.read(/*row*/ 6, /*column*/ 1, Direction::Horizontal, 4) == string("t__l"));
    
    CHECK(board.read(/*row*/ 4, /*column*/ 4, Direction::Vertical, 1) == string("h"));
    CHECK(board.read(/*row*/ 5, /*column*/ 4, Direction::Vertical, 3) == string("ell"));
    CHECK(board.read(/*row*/ 8, /*column*/ 4, Direction::Vertical, 2) == string("o_"));
    
    CHECK(board.read(/*row*/ 8, /*column*/ 1, Direction::Horizontal, 5) == string("_bioi"));
    
} 
    
