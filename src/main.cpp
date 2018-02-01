#include "UM32.hpp"

int main()
{
    UM32 universal_machine("sandmark.umz");
    universal_machine.run();
    universal_machine.load_program("codex.umz");
    universal_machine.run();
    return 0;
}
