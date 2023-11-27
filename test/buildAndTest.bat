:: Compilo código objeto
g++ -Wall -std=c++11 -c ..\src\Client.cpp -o Client.o -I..\include
g++ -Wall -std=c++11 -c ..\src\Employee.cpp -o Employee.o -I..\include
g++ -Wall -std=c++11 -c ..\src\Article.cpp -o Article.o -I..\include
g++ -Wall -std=c++11 -c ..\src\Order.cpp -o Order.o -I..\include
g++ -Wall -std=c++11 -c Test.cpp -o Test.o -I..\include -I..\include\vendors\catch

:: Compilo el Binario
g++ -Wall -std=c++11 Client.o Employee.o Article.o Order.o Test.o -o Test.exe

:: Limpio los códigos objeto
DEL .\*.o

:: Ejecuto el binario:
Test.exe