LPS331: main.o LPS331.o I2C_bus.o
	g++ main.o LPS331.o I2C_bus.o -o LPS331

main.o: main.o
	g++ -c main.cpp -o main.o
	
LPS331.o: LPS331.o
	g++ -c LPS331.cpp -o LPS331.o

I2C_bus.o: I2C_bus.o
	g++ -c I2C_bus.cpp -o I2C_bus.o
		
clean:
	rm -f *.o




