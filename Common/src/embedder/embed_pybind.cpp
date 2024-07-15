#include "../../../subprojects/pybind11/include/pybind11/embed.h"
#include <iostream>
#include <utility>
#include "../../../Common/include/embedder/embed_pybind.hpp"

namespace py = pybind11;
using namespace std;

int Embed_Pybind::calculate(int x_var, int y_var,int* val_var) {
    py::scoped_interpreter guard{}; // Start the interpreter and keep it alive
    
    py::module sys = py::module::import("sys");
    sys.attr("path").attr("append")(".");
    
    try {
        
        py::module py_module = py::module::import("module"); // Import the Python module
        py::object result = py_module.attr("multiply")(x_var,y_var); // Call the Python function
        *val_var= result.cast<int>();
    } catch (const py::error_already_set& e) {
        std::cerr << "Python error: " << e.what() << std::endl;
    }
    exit_code=0;
    return exit_code;
}

