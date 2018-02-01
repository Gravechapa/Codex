#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <exception>
#include <boost/endian/conversion.hpp>
class UM32;
typedef void (*operator_fn) (UM32*);

class UM32
{

public:
    UM32(){}
    UM32(std::string file);
    void load_program(std::string file);
    void run();
    void stop();


private:

    static void mov(UM32* self);
    static void array_index(UM32* self);
    static void array_amendment(UM32* self);
    static void add(UM32* self);
    static void mul(UM32* self);
    static void div(UM32* self);
    static void not_and(UM32* self);
    static void halt(UM32* self);
    static void alloc(UM32* self);
    static void dealloc(UM32* self);
    static void out(UM32* self);
    static void in(UM32* self);
    static void load_program(UM32* self);
    static void orthography(UM32* self);

    static operator_fn _operators[];
    std::vector<uint32_t> _regs = std::vector<uint32_t>(8, 0);
    std::vector<std::vector<uint32_t>> _memory;
    std::queue<uint32_t> _freed_memory;
    uint32_t _memory_counter = 1;
    bool _stop = true;

    int32_t _instruction_pointer = 0;

};
