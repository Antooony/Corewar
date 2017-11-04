#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

	make asm;
	var=${1%.s}
	./asm $var.s
	ressources/asm $var.s
	if [ -f $var.cor ] && [ -f $var.cor.me ]
	then
		if diff $var.cor $var.cor.me
		then
			echo ${GREEN}OK${NC}
			rm $var.cor $var.cor.me
		else
			echo ${RED}KO${NC}
		fi
	else
		echo ${GREEN}OK${NC}
	fi