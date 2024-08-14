#include "parser.hh"
#include <iostream>
#include <fstream>
#include <string>
int main(int argc, char* argv[]){
    std::string filename = argv[1];
    std::ifstream readfile(filename);
    std::ofstream writefile(filename+".ppm");
    writefile<< "P3\n544\n59\n255\n";
    Parser parser(readfile, writefile);
    parser.parse();
}