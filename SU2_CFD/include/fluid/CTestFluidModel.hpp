#pragma once

#include <vector>
#include "../../../Common/include/containers/CLookUpTable.hpp"
#if defined(HAVE_PYBIND11)


#define USE_PYBIND11
#endif
#include "CFluidModel.hpp"
#include "../../../subprojects/pybind11/include/pybind11/pybind11.h"
class TestFluidModel final: public CFluidModel
{
private:
    double P; // pressure value
    double T; // temperature value
    double rho; // density value

    double R_gas; // fluid gas constant
public:

    TestFluidModel(double P_in, double T_in, double rho_in) ;

    ~TestFLuidModel();

    void SetTDState_PT(double P, double T) override;

    void SetTDState_Prho(double P, double rho) override;

    void SetTDState_Trho(double T, double rho) override;

    double SetTDState_Custom(double P, double T, pybind11::function func);
    
    double GetTemperature() const {return T;}
    double GetPressure() const {return P;}
    double GetDensity() const {return rho;}
    
};