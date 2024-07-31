#pragma once
#ifndef EMBED_PYBIND_HPP
#define EMBED_PYBIND_HPP

#include "../../../subprojects/pybind11/include/pybind11/pybind11.h"
#include <Python.h>
class Embed_Pybind{
    public:
        
        int calculate(int x_var, int y_var, pybind11::function func);
        
    private:
        int exit_code;
};

#endif //EMBED_PYBIND_HPP