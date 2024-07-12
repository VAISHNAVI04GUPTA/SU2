#include "catch.hpp"

#include <sstream>
#include <stdio.h>
#include <utility>
#include "../../../Common/include/CConfig.hpp"
#if defined(HAVE_PYBIND11)
#include "../../../external/pybind11/include/pybind11/embed.h"
#define USE_PYBIND11
#endif

#ifdef USE_PYBIND11

TEST_CASE("Embed_pybind11", "[python_embedding]")
{   
    Embed_Pybind result;

    int x_var=2;
    int y_var=3;
   
    int val_var;
    
    
    result.calculate(x_var,y_var, &val_var);
    CHECK(val_var==Approx(6));

}
#endif