g++ -O0 -g3 -Wall -c -fmessage-length=0  -o "obj/main.o" "src/main.cpp"
g++ -O0 -g3 -Wall -c -fmessage-length=0  -o "obj/Operator.o" "src/Operator.cpp"
g++ -O0 -g3 -Wall -c -fmessage-length=0  -o "obj/Tensor.o" "src/Operator.cpp"
g++ -o DLF "obj/Operator.o" "obj/Tensor.o" "obj/main.o" 


