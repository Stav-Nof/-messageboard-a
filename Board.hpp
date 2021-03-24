#include "Direction.hpp"
#include <stdexcept>
#include <iostream>

namespace ariel{
    
    class Board{
        public:
        Board();
        static std::string post(unsigned int row, unsigned int column, Direction d,const std::string& s);
        static std::string read(unsigned int row, unsigned int column ,Direction d,unsigned int s);
        void show();
        ~Board();
    };
}