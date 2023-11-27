## Compilo código objeto
g++ -Wall -std=c++11 -I./include -c ./src/Client.cpp
g++ -Wall -std=c++11 -I./include -c ./src/Employee.cpp
g++ -Wall -std=c++11 -I./include -c ./src/Article.cpp
g++ -Wall -std=c++11 -I./include -c ./src/Order.cpp
g++ -Wall -std=c++11 -I./include -c main.cpp 

## Compilo el Binario
g++ -I./include Article.o Client.o Order.o Employee.o main.o -o app.bin

## Limpio los códigos objeto
rm ./*.o

## Ejecuto
./app.bin