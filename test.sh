#!/bin/bash

	make asm;
	var=${1%.s}
	./asm $var.s
	ressources/asm $var.s
	if diff $var.cor $var.cor.me
	then
		rm $var.cor $var.cor.me 
	else
		echo KO
	fi
	#Segfault dans ft_check sur fluttershy.cor
	#Error sur les nombre negatifs
	#
