import pysu2
from mpi4py import MPI

def main():
  comm=MPI.COMM_WORLD
  # Initialize the corresponding driver of SU2, this includes solver preprocessing.
  try:
    SU2Driver = pysu2.CDriver('config.cfg', 1,comm)
  except TypeError as exception:
    print('A TypeError occured in pysu2.CDriver : ', exception)
    raise
  
  def CustomTD_T_function(T):
    p = 101325
    rho = p / (287.0 * T)
    return rho

  p=SU2Driver.SetTDState_T_function(CustomTD_T_function)
  print(p)


if __name__ == '__main__':
  main()