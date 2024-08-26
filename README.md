



![](logoSU2small.png)   ![](download.png)








- ## <a name="_fmzpksup09mc"></a>Student: Vaishnavi Gupta
- ## <a name="_2zzy7xn0n07b"></a>Github: [VAISHNAVI04GUPTA](https://github.com/VAISHNAVI04GUPTA)
- ## <a name="_um9i8qsvvdje"></a>Organization: [SU2 Foundation](https://su2code.github.io/)
- ## <a name="_p5pmnz96z7s"></a>Mentors: Evert Bunschoten, Nijso Beishuizen


-----

## <a name="_npmsykf1pit7"></a>**CONTENTS**

- [**Overview**](#_l514hjebouue)
- [**Functionality**](#_wmydfbdy5110)
- [**Issues Faced**](#_cskkggnz45tv)
- [**What’s left**](#_uclww4nm4ub6)
- [**Post GSoC**](#_2x4i0gykvxpx)
- [**Closing Remarks**](#_ny239r5uxmqn)





## <a name="_847ctqdw7nal"></a><a name="_l514hjebouue"></a>**Overview**

The primary goal of this project is to enable the **use of generic Python functions within SU2** for data-driven fluid modeling applications. By linking Python functions through the SU2 Python wrapper, we aim to enhance the robustness of thermochemical look-up operations. The [Pybind11 library](https://github.com/pybind/pybind11) facilitates this integration of Python functions into SU2.

This integration enables the **Pybind11 library** to communicate with the **SU2 driver**, enabling the invocation of interpolation functions on reference data to predict the thermodynamic state of fluids. In this setup, Pybind11 serves as a crucial link, facilitating the incorporation of more accurate interpolation techniques into SU2, thus enhancing user flexibility, robustness and memory efficiency.

Pybind11 is a lightweight header-only library that enables seamless interoperability between C++ and Python. Here, it allows us to implement performance-critical components in C++ while leveraging Python's ease of use for higher-level scripting.


## <a name="_wmydfbdy5110"></a>**Functionality**

Currently, SU2 exploits the capabilities of the **Python wrapper** to couple the C++ codebase with an external structural solver. To extend this functionality into Look-up table interpolation of thermodynamic data, I have worked majorly on the following subpoints:

- Set up interpolation methods in Python using the **Scipy** library and added them to SU2 using wrapper classes. The validity of interpolation       function used can be verified from this [repo](https://github.com/VAISHNAVI04GUPTA/GSOC-SU2/tree/main/flamelet_data).
- Added Pybind11 library as a **submodule** into SU2
- Created a linkage of passing Python functions in the wrapper to be passed as arguments in C++ functions using Pybind11.
- A **Unit test case** showcasing the successful integration of Pybind11 to SU2 has also been added for new users.



The Pybind11 functionality can now be enabled in SU2 by giving the meson command *-Denable-pybind11=true* while building SU2.

The above functionality can be understood from the example Unit test case added to demonstrate the main objective : 

![](readme.drawio.png)

The [**`TestFluidModel`**](SU2_CFD/src/fluid/CTestFluidModel.cpp) class contains functions designed to compute various fluid properties, such as density, pressure, and temperature. One critical function, **`SetTDState_Custom`**, calculates the progress variable, mixture fraction, and total enthalpy of a fluid. As we aim to enhance the prediction of the Thermodynamic (TD) state, additional properties are required. To compute these properties, an interpolation algorithm is necessary to accurately predict the required data based on query points. This is where the SciPy library comes into play.

To seamlessly integrate an efficient interpolation method into C++, we utilize Python bindings of the interpolation function, implemented using Pybind11. The interpolation function, defined in the [Python wrapper](TestCases/py_wrapper/TestFluidModel/interpolation.py) file, can be passed as an argument to a corresponding C++ function.

In the Python wrapper file, we define the interpolation function, which uses SciPy's KDTree function to interpolate the dataset and return the desired properties. Subsequently, we invoke the C++ function within Python through a [module](TestCases/py_wrapper/TestFluidModel/query.cpython-38-x86_64-linux-gnu.so) created for the **`TestFluidModel`** class via Pybind11, along with its member functions. The interpolation function and other relevant values are passed as arguments to the **`SetTDState_Custom`** function. This function, in turn, returns interpolated values to the C++ code, where further calculations are performed before the final output is returned to the Python wrapper.

As a result, when the Python file is executed, we obtain the desired fluid properties and can make accurate predictions about the thermodynamic state of the fluid.

**This Test case serves as a simple example showing the successful integration of Pybind into SU2 and its implementation in using different python functions seamlessly inside C++ codebase.**





## <a name="_fvvtkaze581p"></a><a name="_9jvjk3wlvles"></a><a name="_fzfwsyb9lbh7"></a><a name="_cskkggnz45tv"></a>**Issues Faced**

It was probably debugging, wherein I spent most of my time compared to actually coding it!

I faced quite a few blockers at a later stage of the project. This was probably because I started working in depth with Pybind11 and integrating it into a large codebase for the first time.

The major issue in developing the functionality is linking the SU2 **Driver Classes** with the Python wrapper through **pysu2**, which is based on **SWIG** and uses the **mpi4py** library to run the simulations. The SU2 Driver class initializer constructor takes the **SU2\_Comm** type of arguments, a datatype defined in the mpi4py library. So, to compile the member functions of the driver class into a module, integration of the Mpi4py object into the Pybind11 library is required.

The main roadblock is linking the two Python libraries (Pybind11 and Mpi4py) and using them simultaneously in SU2. 

## <a name="_uclww4nm4ub6"></a>**What’s Left**

The next steps in this project would include working with **mpi4py object creation** or defining a custom datatype in Pybind to link the two libraries and create a module for CDriver Classes. **There might be a possibility of writing a SWIG interface file for Pybind11 to integrate the library into pysu2 easily.**

These modules can then easily be imported into wrapper files, and the member functions can be used. Inside the Driver class, the Python function argument passed into C++ can be made into a **CConfig class** object and then be universally used in the **CFluidModel classes**.

Also, a complete and well-documented tutorial and demonstration must be set up to help new and experienced users fully utilize the service this project will cater to.


## <a name="_2x4i0gykvxpx"></a>**After GSoC**

After an incredibly rewarding journey with Google Summer of Code (GSoC), I have gained invaluable experience and knowledge that extends far beyond the project itself. Working on this project has not only deepened my technical skills in C++, Python, and Pybind11 but also enriched my understanding of open-source collaboration, version control, and efficient coding practices. The challenges I faced pushed me to think critically and problem-solve effectively, fostering both professional growth and personal development. 

Though the GSoC "coding phase" has ended, I will still be *unofficially* working closely with the SU2 team to complete the last part of my proposed plan, i.e, to link the Pybind11 library with pysu2 and, through the CConfig class, make the python functions readily available in any FluidModel class. Apart from this, I look forward to reviewing the code and providing well-summarized documentation as well :)


## <a name="_ny239r5uxmqn"></a>**Closing Remarks**

Throughout this program, the support from my mentors and the open-source community has been phenomenal. Their guidance helped me navigate complex problems and refine my approach to software development. As I close this chapter, I carry forward the lessons learned and the connections made with a renewed commitment to contributing to open-source projects in the future.

Thank you to everyone who made this journey possible. I look forward to continuing my involvement in the open-source community and applying the skills and knowledge gained from this GSoC experience to future endeavors.

