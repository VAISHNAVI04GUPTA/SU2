import sys
sys.path.append('../../../build/Common/src/embedder')

import calc
def factorial(a):
    l=[]
    if not isinstance(a, int):
        raise TypeError("Expected an integer input")
    f=1
    for i in range(1,a):
        if(a%i==0):
            l.append(i)


    
    return l[-1]

ins3 = calc.Embed_Pybind()
result=ins3.calculate(4,6,factorial)
print("Highest factor:",result)