VPATH = %.cpp Source : %.h Include

PTE : Main.o Object.o
	g++ -o PTE Main.o Object.o
