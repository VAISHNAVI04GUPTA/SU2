#include "../../include/fluid/CTestFluidModel.hpp"
#include <iostream>
#include "../../../subprojects/pybind11/include/pybind11/embed.h"
#include "../../../subprojects/pybind11/include/pybind11/pybind11.h"
using namespace std;

namespace py = pybind11;
CTestFluidModel::CTestFluidModel(double P_in, double T_in, double rho_in) 
{
    
    R_gas = P_in / (T_in * rho_in);
    cout << "Defining a new fluid model with gas constant " << scientific << R_gas << endl;

}
CTestFluidModel::~CTestFluidModel()=default;

void CTestFluidModel::SetTDState_Prho(double P_in, double rho_in) {
    P = P_in;
    rho = rho_in;
    T = P / (R_gas * rho);
}


void CTestFluidModel::SetTDState_PT(double P_in, double T_in) {
    P = P_in;
    T = T_in;
    rho = P / (R_gas * T);
}

void CTestFluidModel::SetTDState_rhoT( double rho_in,double T_in ){
    T = T_in;
    rho = rho_in;
    P = R_gas * T * rho;
}


double CTestFluidModel::SetTDState_Custom(double P_in, double T_in, pybind11::function func) {
    double val;
    P = P_in;
    T = T_in;
    double Prog_var=P-T;
    double Enth_Total=P+T;
    double Mix_frac=P*T;
    // Ensure that the function is called and cast properly
    try {
         val= func(Prog_var,Enth_Total,Mix_frac).cast<double>();  // Ensure the Python function returns an int
        
    } catch (pybind11::cast_error &e) {
        // Handle the cast error
        throw std::runtime_error("Unable to cast Python function return to int: " + std::string(e.what()));
    }

    double sum= val*val;
    return sum;
}




PYBIND11_MODULE(query,m){
    py::class_<CTestFluidModel>(m, "CTestFluidModel")
        .def(py::init<double, double, double>())
        .def("SetTDState_Custom",&CTestFluidModel::SetTDState_Custom,"A function performing arithmetic calculation to find the density.",
             py::arg("P_in"),py::arg("T_in"),py::arg("func"))
        .def("SetTDState_Prho",&CTestFluidModel::SetTDState_Prho,"A function performing arithmetic calculation to find the density.",
             py::arg("P_in"),py::arg("rho_in"))
        .def("SetTDState_PT",&CTestFluidModel::SetTDState_PT,"A function performing arithmetic calculation to find the density.",
             py::arg("P_in"),py::arg("T_in"))
        .def("SetTDState_rhoT",&CTestFluidModel::SetTDState_rhoT,"A function performing arithmetic calculation to find the density.",
             py::arg("rho_in"),py::arg("T_in"))
        .def("GetTemperature",&CTestFluidModel::GetTemperature)
        .def("GetPressure",&CTestFluidModel::GetPressure)
        .def("GetDensity",&CTestFluidModel::GetDensity);
 
        
}