import calc
def factorial(a):
    l=[]
    if not isinstance(a, int):
        raise TypeError("Expected an integer input")
    f=1
    for i in range(1,a):
        if(a%i==0):
            l.append(i)


    
    return l[1]

mbdr = calc.Embed_Pybind()
x_var = 42
y_var = 2

result=mbdr.calculate(x_var,y_var,factorial)
print("Highest factor:",result)