#include "parser.hpp"
#include "scanner.hh"
#include "driver.hh"

#include <iostream>
#include <fstream>

#include <cstring>

int main( int  argc, char* argv[]) {
    Driver * driver = new Driver;
    Scanner * scanner = new Scanner(std::cin, std::cout);
    yy::Parser * parser = new yy::Parser(*scanner, *driver);

    parser->parse();

    std::string output = driver->getForme().toSVG();
    std::cout << driver->getForme().toSVG() << std::endl;
    
    driver->getForme().writeToSvgFile(output);

    return 0;
}
