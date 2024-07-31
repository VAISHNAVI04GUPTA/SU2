
#include "../../../subprojects/pybind11/include/pybind11/embed.h"
#include "../../../subprojects/pybind11/include/pybind11/pybind11.h"
#include <iostream>
#include <utility>
#include "../../../Common/include/embedder/embed_pybind.hpp"


namespace py = pybind11;
using namespace std;

int Embed_Pybind::calculate(int x_var, int y_var,pybind11::function func) {
    int prod=x_var*y_var;
    int result;
    try {
        result = func(prod).cast<int>(); // Call the Python function
        
    } catch (const py::error_already_set& e) {
        std::cerr << "Python error: " << e.what() << std::endl;
    }
    exit_code=0;
    return result;
}

PYBIND11_MODULE(calc,m){
    py::class_<Embed_Pybind>(m, "Embed_Pybind")
        .def(py::init<>())
        .def("calculate",&Embed_Pybind::calculate,"A function performing arithmetic calculation",
             py::arg("x_var"),py::arg("y_var"),py::arg("func"));
}