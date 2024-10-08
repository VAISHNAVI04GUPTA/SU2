#pragma once

#include <vector>

#if defined(HAVE_PYBIND11)


#define USE_PYBIND11
#endif

#include "../../../subprojects/pybind11/include/pybind11/pybind11.h"
/*!
 * \class CTestFluidModel
 * \brief Template class for fluid model definition using ideal gas laws for
 * fluid dynamic state definition.
 * \author: E.C.Bunschoten.
 */
class CTestFluidModel 
{
private:
    double P; // pressure value
    double T; // temperature value
    double rho; // density value
    double P_in; // pressure value
    double T_in; // temperature value
    double rho_in;
    double R_gas; // fluid gas constant
public:

    CTestFluidModel(double P_in, double T_in, double rho_in) ;

    ~CTestFluidModel(void);

    void SetTDState_PT(double P, double T) ;

    void SetTDState_Prho(double P, double rho) ;

    void SetTDState_rhoT( double rho,double T) ;

    double SetTDState_Custom(double P, double T, pybind11::function func);
    
    double GetTemperature() const {return T;}
    double GetPressure() const {return P;}
    double GetDensity() const {return rho;}
    
};