objects = doubleLL.o doubleLLFunc.o

main.exe: $(objects)
		g++ -o main.exe $(objects)

doubleLL.o: 	doubleLL.h
doubleLLFunc.o: doubleLL.h

.PHONY: clean
clean:
		rm main.exe $(objects)
