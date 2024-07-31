#include "catch.hpp"
//#include "../../../external/pybind11/include/pybind11/python3.8/Python.h"

#include <sstream>
#include <stdio.h>
#include <utility>
#include "../../../Common/include/CConfig.hpp"
#if defined(HAVE_PYBIND11)
#include "../../../Common/include/embedder/embed_pybind.hpp"
#define USE_PYBIND11
#endif
#include "../../../subprojects/pybind11/include/pybind11/embed.h"
#include "../../../subprojects/pybind11/include/pybind11/pybind11.h"

#ifdef USE_PYBIND11

TEST_CASE("Embed_pybind11", "[python_embedding]")
{   

    namespace py = pybind11;
    using namespace std;
    
    py::scoped_interpreter guard{}; // Start the interpreter and keep it alive
    
    py::module sys = py::module::import("sys");
    sys.attr("path").attr("append")(".");
    
    

    
    Embed_Pybind result;

    int x_var=2;
    int y_var=3;
   
    int val_var;
    factorial= pybind11::function func;
    
    result.calculate(x_var,y_var,factorial);
    CHECK(val_var==Approx(6));



}
#endif