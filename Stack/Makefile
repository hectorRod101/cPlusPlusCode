objects = stack.o stackFunc.o

main.exe: $(objects)
			g++ -o main.exe $(objects)

stack.o: 		stack.h
stackFunc.o:	stack.h

.PHONY: clean
clean:
		rm main.exe $(objects)