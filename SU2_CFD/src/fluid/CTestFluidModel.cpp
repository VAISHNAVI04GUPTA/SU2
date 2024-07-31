#include "../../include/fluid/CTestFluidModel.hpp"
#include <iostream>
#include "../../../subprojects/pybind11/include/pybind11/embed.h"
using namespace std;

namespace py = pybind11;

TestFluidModel::TestFluidModel(double P_in, double T_in, double rho_in) 
{
    
    R_gas = P_in / (T_in * rho_in);
    cout << "Defining a new fluid model with gas constant " << scientific << R_gas << endl;

}

void TestFluidModel::SetTDState_Prho(double P_in, double rho_in) {
    P = P_in;
    rho = rho_in;
    T = P / (R_gas * rho);
}


void TestFluidModel::SetTDState_PT(double P_in, double T_in) {
    P = P_in;
    T = T_in;
    rho = P / (R_gas * T);
}

void TestFluidModel::SetTDState_Trho(double T_in, double rho_in) {
    T = T_in;
    rho = rho_in;
    P = R_gas * T * rho;
}


double TestFluidModel::SetTDState_Custom(double P_in, double T_in, pybind11::function func) {
    
    P = P_in;
    T = T_in;
    
    // Ensure that the function is called and cast properly
    try {
        double rho = func(P,T).cast<double>();  // Ensure the Python function returns an int
        return rho;
    } catch (pybind11::cast_error &e) {
        // Handle the cast error
        throw std::runtime_error("Unable to cast Python function return to int: " + std::string(e.what()));
    }
}
