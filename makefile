.PHONY: loops recursives recursived loopd all clean

loops: libclassloops.a
recursives: libclassrec.a
recursived: libclassrec.so
loopd: libclassloops.so
all: libclassloops.a libclassrec.so libclassloops.so mains maindloop maindrec
clean:
	rm -f *.o *.a *.so mains maindloop maindrec


#create liberaries:
libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
	ranlib libclassloops.a

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
	ranlib libclassrec.a

libclassrec.so: basicClassification.o advancedClassificationLoop.o
	gcc -shared -o libclassrec.so basicClassification.o advancedClassificationLoop.o

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	gcc -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o


#main programs
mains: main.o libclassrec.a
	gcc -Wall -g -o mains main.o libclassrec.a

maindloop: main.o
	gcc -Wall -g -o maindloop main.o ./libclassloops.so

maindrec: main.o
	gcc -Wall -g -o maindrec main.o ./libclassrec.so


#create o files:
basicClassification.o: basicClassification.c NumClass.h
	gcc -Wall -g -fPIC -c basicClassification.c -o basicClassification.o

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -Wall -g -fPIC -c advancedClassificationLoop.c -o advancedClassificationLoop.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -Wall -g -fPIC -c advancedClassificationRecursion.c -o advancedClassificationRecursion.o

main.o: main.c NumClass.h
	gcc -Wall -g -c main.c -o main.o