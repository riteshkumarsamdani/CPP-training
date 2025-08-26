This branch contains code for calculator in which the implementation for dynamic linking (implicit and explicit) is there.
To run make executable file for every header file we run command on terminal as:
    g++ -c Addition.cpp Subtract.cpp Multiplication.cpp Division.cpp InputUtil.cpp -fPIC
this will create .o file which is object file.
then to make shared library:
    c++ -shared -o libmath.so Addition.o Subtract.o Multiplication.o Division.o InputUtil.o
this will create libmath.so shared library.
to make executable file for Implicit linking
    g++ -o ImplicitCalc CalculatorImplicit.cpp -L. -lmath
this will create executable file as ImplicitCalc
now to run code : ./ImplicitCalc
this will give output of code.

to make executable file for explicit linking:
    g++ CalculatorExplicit.cpp -ldl -o ExplicitCalc
this will create executable file as ExplicitCalc
now to run code: ./ExplicitCalc
this will give output of code.