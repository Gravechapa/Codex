#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <exception>
class UM32;
typedef void (*operator_fn) (UM32*);

class UM32
{

public:
    UM32(std::string file);
    void load_programm(std::string file);

private:

    static void mov(UM32* self);

    static operator_fn _operators[];
    std::vector<uint32_t> _regs = std::vector<uint32_t>{8, 0};
    std::vector<uint32_t> _programm();
    std::unordered_map<uint32_t, uint32_t> _memory();
    std::queue<uint32_t> _freed_memory();

    uint32_t* _instruction_pointer = nullptr;

};
