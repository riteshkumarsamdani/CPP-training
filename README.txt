This branch contains Banking management system.
to run code first clone the branch.
go to directory: cd CPP-training/assignments/week5/BankingSystem
to compile all .cpp file we use command:
    g++ -Iinclude -c  src/*.cpp -fPIC
this will create .o file for all .cpp file except main App.cpp file.
now to make its library we use command:
    g++ -shared -o lib/libbank.so *.o
this will add all functionality of .o file into single library.
now to compile final executable file:
    g++ -o app -I include src/App/App.cpp -Llib -lbank -linput
input.so is already there which will take care of iuputs.
this will create app file which is executable file.
now we will give command to where to look librfary to out compiler by:
    export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
finally to run code we use ./app
now program is running and we can use banking system.
for menu bar shown at runtime refer to output screenshot.
