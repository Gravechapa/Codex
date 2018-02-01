#include "../headers/UM32.hpp"

 operator_fn UM32::_operators[] =
 {
     UM32::mov,
     UM32::array_index,
     UM32::array_amendment,
     UM32::add,
     UM32::mul,
     UM32::div,
     UM32::not_and,
     UM32::halt,
     UM32::alloc,
     UM32::dealloc,
     UM32::out,
     UM32::in,
     UM32::load_program,
     UM32::orthography,
 };

UM32::UM32(std::string name)
{
    load_programm(name);
}

void UM32::run()
{
    if (_stop)
        {
            throw std::runtime_error("Machine is not ready");
        }
    while (!_stop)
        {
            _operators[*_instruction_pointer >> 28](this);
            ++_instruction_pointer;
        }
}

void UM32::stop()
{
    _programm = std::vector<uint32_t>();
    _memory = std::unordered_map<uint32_t, std::vector<uint32_t>>();
    _freed_memory = std::queue<uint32_t>();
    _regs = std::vector<uint32_t>(8, 0);
    _stop = true;
}

void UM32::load_programm(std::string name)
{
    std::ifstream file(name, std::ifstream::in | std::ifstream::binary);
    if (!file.is_open())
        {
            throw std::runtime_error("Can't open file");
        }

    file.seekg (0, file.end);
    uint32_t length = file.tellg();
    file.seekg (0, file.beg);

    uint32_t pos = 0;
    uint32_t buffer = 0;
    while (pos < length)
        {
            file.read((char*)&buffer, sizeof(uint32_t));
            _programm.push_back(boost::endian::endian_reverse(buffer));
            pos += 4;
        }
    _instruction_pointer = &_programm[0];
    _stop = false;
}

void UM32::mov(UM32* self)
{
    uint32_t reg_c = self->_regs[*self->_instruction_pointer & 0b111];
    if (reg_c != 0)
        {
            self->_regs[*self->_instruction_pointer >> 6 & 0b111] = self->_regs[*self->_instruction_pointer >> 3 & 0b111];
        }
}

void UM32::array_index(UM32* self)
{

}

void UM32::array_amendment(UM32* self)
{}

void UM32::add(UM32* self)
{
    self->_regs[*self->_instruction_pointer >> 6 & 0b111] = self->_regs[*self->_instruction_pointer >> 3 & 0b111] +
                                                                                                       self->_regs[*self->_instruction_pointer & 0b111];
}

void UM32::mul(UM32* self)
{
    self->_regs[*self->_instruction_pointer >> 6 & 0b111] = self->_regs[*self->_instruction_pointer >> 3 & 0b111] *
                                                                                                       self->_regs[*self->_instruction_pointer & 0b111];
}

void UM32::div(UM32* self)
{
    self->_regs[*self->_instruction_pointer >> 6 & 0b111] = self->_regs[*self->_instruction_pointer >> 3 & 0b111] /
                                                                                                       self->_regs[*self->_instruction_pointer & 0b111];
}

void UM32::not_and(UM32* self)
{
    self->_regs[*self->_instruction_pointer >> 6 & 0b111] = ~(self->_regs[*self->_instruction_pointer >> 3 & 0b111] &
                                                                                                       self->_regs[*self->_instruction_pointer & 0b111]);
}

void UM32::halt(UM32* self)
{
    self->stop();
}

void UM32::alloc(UM32* self)
{}

void UM32::dealloc(UM32* self)
{}

void UM32::out(UM32* self)
{
    std::cout << static_cast<unsigned char>(self->_regs[*self->_instruction_pointer & 0b111]);
}

void UM32::in(UM32* self)
{
    self->_regs[*self->_instruction_pointer & 0b111] = static_cast<unsigned char>(std::cin.get());
}

void UM32::load_program(UM32* self)
{}

void UM32::orthography(UM32* self)
{
    self->_regs[*self->_instruction_pointer >> 25 & 0b111] = *self->_instruction_pointer & 0xffffff;
}

