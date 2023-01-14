all:derle bagla calistir
derle:
	gcc -c -I "./include" ./src/Test.c -o ./lib/Test.o
	gcc -c -I "./include" ./src/Kisi.c -o ./lib/Kisi.o
	gcc -c -I "./include" ./src/Dosya.c -o ./lib/Dosya.o
	gcc -c -I "./include" ./src/Oyun.c -o ./lib/Oyun.o
bagla:
	gcc ./lib/Test.o ./lib/Kisi.o ./lib/Dosya.o ./lib/Oyun.o -o ./bin/program
calistir:
	./bin/program