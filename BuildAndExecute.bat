:: Compilo código objeto
g++ -Wall -std=c++11 -I.\include -c .\src\Client.cpp
g++ -Wall -std=c++11 -I.\include -c .\src\WspMessenger.cpp
g++ -Wall -std=c++11 -I.\include -c .\src\IgMessenger.cpp
g++ -Wall -std=c++11 -I.\include -c .\src\FbMessenger.cpp
g++ -Wall -std=c++11 -I.\include -c .\src\Item.cpp
g++ -Wall -std=c++11 -I.\include -c .\src\Product.cpp
g++ -Wall -std=c++11 -I.\include -c .\src\Rent.cpp
g++ -Wall -std=c++11 -I.\include -c main.cpp 

:: Compilo el Binario
g++ -I.\include Client.o WspMessenger.o IgMessenger.o FbMessenger.o Item.o Product.o Rent.o main.o -o app.exe

:: Limpio los códigos objeto
DEL .\*.o

:: Ejecuto
app.exe