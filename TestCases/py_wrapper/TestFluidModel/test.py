



import density 
from math import sin 

# Initiate test fluid model
fluid_model_test = density.TestFluidModel()

# Example calculation, computing the density based on pressure and temperature
fluid_model_test.SetTDState_PT(2e5, 400)
print(fluid_model_test.GetDensity())

# Custom function to compute density based on pressure and temperature.
# This is just a demonstrator! Don't expect accurate predictions from this 
# function.
def customPTfunction(P_in, T_in):
    rho = P_in / (200*sin(T_in) * T_in)
    return float(rho)

# Goal: pass the customPTfunction to the fluid_model_test to compute the density.
result=fluid_model_test.SetTDState_Custom(101325,300, customPTfunction)
print("Custom density calculation value: %.3e" % result)