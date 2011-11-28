test.exe: *.cpp *.h
	g++ -Wall -o test.exe *.cpp

clean:
	del test.exe