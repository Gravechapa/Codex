#include "UM32.hpp"
#include <iostream>
#include <limits>
#include <string>

int main()
{
    std::cout << "Input 'y' for test" << std::endl;
    std::cout.flush();
    char symbol;
    std::cin >> symbol;
    UM32 universal_machine;
    if (symbol == 'y')
        {
            universal_machine.load_program("sandmark.umz");
            universal_machine.run();
        }
    std::cout << "Input file name" << std::endl;
    std::cout.flush();
    std::string name;
    std::cin >> name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    universal_machine.load_program(name);
    universal_machine.run();
    return 0;
}
