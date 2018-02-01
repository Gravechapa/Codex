#include "UM32.hpp"
#include <iostream>

int main()
{
    std::cout << "Input 'y' for test" << std::endl;
    char symbol;
    std::cin >> symbol;
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
