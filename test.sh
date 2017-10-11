#!/bin/bash

	make asm;
	./asm ressources/champs/examples/$1.s > test;
	./a.out ressources/champs/examples/$1.cor > res;
	./a.out test > res2; diff res res2
