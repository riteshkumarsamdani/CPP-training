This branch contains Music Playlist.
to run code first clone the branch.
go to directory: cd CPP-training/assignments/week8/MusicSystem
to compile all .cpp file we use command:
    g++ -Iinclude -c  src/*.cpp -fPIC
this will create .o file for all .cpp file except main Main.cpp file.
now to make its library we use command:
    g++ -shared -o lib/libmusicPlaylist.so *.o
this will add all functionality of .o file into single library.
now to compile final executable file:
    g++ -std=c++17 -Iinclude -Ipub -I lib/InputHandler/ src/App/Main.cpp -lsfml-audio -llib/input -llib/musicPlaylist -o MusicPlaylist
input.so is already there which will take care of iuputs.
this will create app file which is executable file.
now we will give command to where to look librfary to out compiler by:
    export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
finally to run code we use ./musicPlaylist
now program is running and we can use music System.
for menu bar shown at runtime refer to output screenshot.

for testing use command to compile:
    g++ -std=c++17 -I include -I pub -I ~/googletest/googletest/include     -I ~/googletest/googlemock/include test/*.cpp src/*.cpp ~/googletest/build/lib/libgmock*.a     ~/googletest/build/lib/libgtest*.a  -lsfml-audio -o MusicTests

for running all test : ./MusicTest