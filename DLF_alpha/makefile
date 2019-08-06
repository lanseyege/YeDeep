cc=g++ 
CFLAGS=-O0 -g3 -Wall -c -fmessage-length=0  
obj=./obj/
src=./src/

ALL: DLF

DLF: $(obj)main.o $(obj)Operator.o $(obj)Tensor.o 	
	$(cc) -o DLF $(obj)main.o $(obj)Operator.o $(obj)Tensor.o 

$(obj)main.o: $(src)main.cpp $(src)Tensor.h
	$(cc) $(CFLAGS) $(src)main.cpp -o $(obj)main.o

$(obj)Operator.o: $(src)Operator.cpp $(src)Operator.h
	$(cc) $(CFLAGS) $(src)Operator.cpp -o $(obj)Operator.o

$(obj)Tensor.o: $(src)Tensor.cpp $(src)Tensor.h $(src)Operator.h
	$(cc) $(CFLAGS) $(src)Tensor.cpp -o $(obj)Tensor.o

clean:
	-rm $(obj)*.o

