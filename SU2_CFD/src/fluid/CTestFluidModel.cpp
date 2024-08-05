#include "../../include/fluid/CTestFluidModel.hpp"
#include <iostream>
#include "../../../subprojects/pybind11/include/pybind11/embed.h"
#include "../../../subprojects/pybind11/include/pybind11/pybind11.h"
using namespace std;

namespace py = pybind11;
/*TestFluidModel::TestFluidModel(101325,300,1.13) 
{
    
    R_gas = P_in / (T_in * rho_in);
    cout << "Defining a new fluid model with gas constant " << scientific << R_gas << endl;

}
*/
double R_gas=2.82;
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

void TestFluidModel::SetTDState_rhoT( double rho_in,double T_in ){
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



PYBIND11_MODULE(density,m){
    py::class_<TestFluidModel>(m, "TestFluidModel")
        .def(py::init<>())
        .def("SetTDState_Custom",&TestFluidModel::SetTDState_Custom,"A function performing arithmetic calculation to find the density.",
             py::arg("P_in"),py::arg("T_in"),py::arg("func"))
        .def("SetTDState_Prho",&TestFluidModel::SetTDState_Prho,"A function performing arithmetic calculation to find the density.",
             py::arg("P_in"),py::arg("rho_in"))
        .def("SetTDState_PT",&TestFluidModel::SetTDState_PT,"A function performing arithmetic calculation to find the density.",
             py::arg("P_in"),py::arg("T_in"))
        .def("SetTDState_rhoT",&TestFluidModel::SetTDState_rhoT,"A function performing arithmetic calculation to find the density.",
             py::arg("rho_in"),py::arg("T_in"))
        .def("GetTemperature",&TestFluidModel::GetTemperature)
        .def("GetPressure",&TestFluidModel::GetPressure)
        .def("GetDensity",&TestFluidModel::GetDensity);
 
        
}