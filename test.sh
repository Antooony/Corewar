#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

	make asm;
	var=${1%.s}
	./asm $var.s
	ressources/asm $var.s
	if diff $var.cor $var.cor.me
	then
		echo ${GREEN}OK${NC}
		rm $var.cor $var.cor.me 
	else
		echo ${RED}KO${NC}
	fi
	# Segfault dans ft_check sur fluttershy.cor
	# Erreur sur les nombre negatifs