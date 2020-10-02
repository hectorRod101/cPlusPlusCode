objects = singleLL.o singleLLFunc.o

main.exe: $(objects)
		g++ -o main.exe $(objects)

singleLL.o: singleLL.h
singleLLFunc.o: singleLL.h

.PHONY: clean
clean:
		rm main.exe $(objects)