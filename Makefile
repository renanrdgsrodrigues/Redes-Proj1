PORTA0 = 51110
PORTA1 = 51111
PORTA2 = 51112
PORTA3 = 51113
PORTA4 = 51114
PORTA5 = 51115

FLAGS = -o2 -Wall
	
all: server.c client0.c client1.c socketsFunction.c
	gcc server.c socketsFunction.c -pthread $(FLAGS) -o server
	gcc client0.c socketsFunction.c $(FLAGS) -o client0	
	gcc client1.c socketsFunction.c $(FLAGS) -o client1
	gcc client2.c socketsFunction.c $(FLAGS) -o client2
	gcc client3.c socketsFunction.c $(FLGAS) -o client3		
	gcc client4.c socketsFunction.c $(FLGAS) -o client4		
	gcc client5.c socketsFunction.c $(FLGAS) -o client5		


clean: 
	@rm -rf *.o *~ *.dat server client0 client1 client2 client3 client4 client5

run:
	(./client0 localhost $(PORTA0)) & (./client1 localhost $(PORTA1)) & (./client2 localhost $(PORTA2)) & (./client3 localhost $(PORTA3)) & (./client4 localhost $(PORTA4)) & (./client5 localhost $(PORTA5))

	
	
