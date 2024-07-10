#include <utility>
#include "../../../Common/include/embedder/embed_python.hpp"

using namespace std;
/*Embed_Python(){

};
*/

double Embed_Python::square(double x_var, double* val_var){

    double  sq=x_var * x_var;

    *val_var=sq;

    exit_code=0;
    return exit_code;
    
}

double Embed_Python::addition(double a_var,double b_var, double* ans_var){
  
  double  sum= a_var+b_var;

  *ans_var=sum;

  exit_code=0;
  return exit_code;
    
}