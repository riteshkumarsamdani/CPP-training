This branch contains code for parsing of file using third party library.
to run code first clone the branch.
go to directory: cd CPP-training/assignments/week6/Parsing_using_3rd_party_libarary
to compile all .cpp file we use command:
    g++ -Iinclude -c  src/*.cpp lib/external/tinyxml2/tinyxml2.cpp -fPIC
this will create .o file for all .cpp file except main App.cpp file.
now to make its library we use command:
    g++ -shared -o lib/libparser.so *.o
this will add all functionality of .o file into single library.
now to compile final executable file:
    g++ -o app -Iinclude -Ilib/nlohmann -Ilib/tinyxml2 -Ilib/rapidcsv src/App/Main.cpp -Llib -lparser -linputHandler
inputHandler.so is already there which will take care of iuputs.
this will create app file which is executable file.
now we will give command to where to look librfary to out compiler by:
    export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
finally to run code we use ./app
now program is running and we can give file path to parse it.
