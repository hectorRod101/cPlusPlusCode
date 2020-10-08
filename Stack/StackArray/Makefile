objects = stackArray.o stackArrayFunc.o

main.exe: $(objects)
		g++ -o main.exe $(objects)

stackArray.o:		stackArray.h
stackArrayFunc.o: 	stackArray.h

.PHONY: clean
clean:
		rm main.exe $(objects)
