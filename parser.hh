#include <iostream>
#include <cinttypes>
enum ParseStates {
    MULTIBYTE,
    START,
    EXIT,
    BLONG,
    CLONG,
    CLONGC
};

enum TokenTypes {
    COLOR_ONE,
    COLOR_SHORT,
    COLOR_LONG, 
    BASE_SHORT, 
    BASE_LONG
    };

class Parser{
    public:
        Parser(std::istream& is, std::ostream& os): 
            input_{is}, output_{os} {}
        void parse();
    private:
        std::istream& input_;
        std::ostream& output_;
        enum ParseStates state_ = START;
        uint8_t byte_;
        uint16_t width_;
        uint8_t color_;
        void output(uint16_t width, uint8_t color);
        void parse_multibyte();
};

