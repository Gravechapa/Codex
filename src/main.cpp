#include "UM32.hpp"
#include <iostream>
#include <limits>

int main()
{
    std::cout << "Input 'y' for test" << std::endl;
    std::cout.flush();
    char symbol;
    std::cin >> symbol;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    UM32 universal_machine;
    if (symbol == 'y')
        {
            universal_machine.load_program("sandmark.umz");
            universal_machine.run();
        }
    universal_machine.load_program("codex.umz");
    universal_machine.run();
    return 0;
}
