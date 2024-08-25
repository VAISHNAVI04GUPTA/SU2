import pysu2
from mpi4py import MPI
from math import sin
import pySU2_bindings # type: ignore
def main():
  comm=MPI.COMM_WORLD
  # Initialize the corresponding driver of SU2, this includes solver preprocessing.
  try:
    SU2Driver = pysu2.CSinglezoneDriver('config.cfg', 1,comm)
  except TypeError as exception:
    print('A TypeError occured in pysu2.CDriver : ', exception)
    raise
  
  def CustomTD_T_function(T):
    p = 101325.0
    rho = p / (200*sin(T) * T)
    return float(rho)
  try:
    
    pySU2_bindings.SetTDState_T_function(CustomTD_T_function)
  except TypeError as exception:
    print('A TypeError occured in pysu2.CDriver : ', exception)
    raise
  
  



if __name__ == '__main__':
  main()