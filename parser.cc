#include "parser.hh"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

bool in_range(uint8_t lower, uint8_t upper, uint8_t test){
    return(test >= lower || test <= upper);
}

void Parser::output(uint16_t width, uint8_t color){
    // output_ << std::to_string(width) <<", "<< std::to_string(color)<<"\n";
    std::string c = std::to_string(color);
    uint16_t i = 0;
    while(i<width){
        output_ << c << " " << c << " " << c << "\n";
        i++;
    }
}

void Parser::parse(){
    while (input_.peek() != EOF){
        byte_ = (uint8_t)input_.get();
        if (byte_ == 0){
            parse_multibyte();
        }
        else {
            output(1, byte_);
        }

    }
}

void Parser::parse_multibyte(){
    byte_ = (uint8_t)input_.get();
    if (byte_==0 || input_.peek() == EOF){
        state_ = EXIT;
        std::cout << "EXIT"<<"\n";
    }
    if(in_range(1,63, byte_)){//base short
        output(byte_ ,0);
    }
    if(in_range(64,127,byte_)){//base long
        width_ = (byte_-64) * 256;
        byte_ = (uint8_t)input_.get(); //64-255
        width_ = width_ + byte_;
        output(width_, 0);
    }
    if(in_range(128, 191, byte_)){ //color_ short
        width_ = byte_ - 128; //3-63
        color_ = (uint8_t)input_.get(); //1-255
        output(width_, color_);
    }
    if(in_range(192, 255, byte_)){//color_ long
        width_ = (byte_-192) * 256;
        byte_ = (uint8_t)input_.get(); //64-255
        width_ = width_ + byte_; 
        color_ = (uint8_t)input_.get(); //1-255
        output(width_, color_);
    }
}
