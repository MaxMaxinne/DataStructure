a.exe: DataStructure.o 
	g++ -o a.exe DataStructure.o
DataStructure.o:DataStructure.cpp  arrayList.h
	g++ -c DataStructure.cpp 