#pragma once
#include "../../../subprojects/pybind11/include/pybind11/pybind11.h"
#include <Python.h>
class Embed_Pybind{
    public:
        
        int calculate(int x_var, int y_var, int* val_var);
        
    private:
        int exit_code;
};