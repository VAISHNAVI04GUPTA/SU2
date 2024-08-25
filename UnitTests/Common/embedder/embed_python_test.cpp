#include "catch.hpp"

#include <sstream>
#include <stdio.h>
#include <utility>
#include "../../../Common/include/CConfig.hpp"
#include "../../../Common/include/embedder/embed_python.hpp"

TEST_CASE("Embed_python", "[python_embedding]")
{   
    Embed_Python result;

    double x_var=2.2;
    double a_var=3.3;
    double b_var=4.4;
    double val_var;
    double ans_var;
    
    result.square(x_var, &val_var);
    CHECK(val_var==Approx(4.84));

    result.addition(a_var,b_var,&ans_var);
    CHECK(ans_var==Approx(7.7));


}