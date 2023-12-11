:: Compilo código objeto
g++ -Wall -std=c++14 -I..\include -c ..\src\Client.cpp
g++ -Wall -std=c++14 -I..\include -c ..\src\WspMessenger.cpp
g++ -Wall -std=c++14 -I..\include -c ..\src\IgMessenger.cpp
g++ -Wall -std=c++14 -I..\include -c ..\src\FbMessenger.cpp
g++ -Wall -std=c++14 -I..\include -c ..\src\Item.cpp
g++ -Wall -std=c++14 -I..\include -c ..\src\Product.cpp
g++ -Wall -std=c++14 -I..\include -c ..\src\Rent.cpp
g++ -Wall -std=c++14 -I..\include -I..\include\vendors\catch -c Test.cpp 

:: Compilo el Binario
g++ -I.\include Client.o WspMessenger.o IgMessenger.o FbMessenger.o Item.o Product.o Rent.o Test.o -o Test.exe

:: Limpio los códigos objeto
DEL .\*.o

:: Ejecuto
Test.exe