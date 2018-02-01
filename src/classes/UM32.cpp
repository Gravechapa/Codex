#include "../headers/UM32.hpp"

 operator_fn UM32::_operators[] =
 {
     UM32::mov
 };

UM32::UM32(std::string name)
{

    _operators[0](this);
}

void UM32::load_programm(std::string name)
{
    std::ifstream file(name, std::ifstream::in | std::ifstream::binary);
    if (!file.is_open())
        {
            throw std::runtime_error("Can't open file");
        }

}

void UM32::mov(UM32* self)
{
    uint32_t reg_c = self->_regs[*self->_instruction_pointer & 0b111];
    if (reg_c != 0)
        {
            self->_regs[*self->_instruction_pointer >> 6 & 0b111] = self->_regs[*self->_instruction_pointer >> 3 & 0b111];
        }
}
