This branch contains the code for matrix operation: addition, multiplication.
to run code first clone the branch.
go to directory: cd CPP-training/assignments/week3/MatrixAssignment
to compile all .cpp file we use command:
    g++ -Iinclude -c  src/*.cpp -fPIC
this will create .o file for all .cpp file except main App.cpp file.
now to make its library we use command:
    g++ -shared -o lib/libmatrix.so *.o
this will add all functionality of .o file into single library.
now to compile final executable file:
    g++ -o app -I include src/App/App.cpp -Llib -lmatrix
this will create app file which is executable file.
now we will give command to where to look librfary to out compiler by:
    export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
finally to run code we use ./app
now program is running and we can perform our operation.