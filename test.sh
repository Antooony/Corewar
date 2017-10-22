#!/bin/bash

	make asm;
	var=${1%.s}
	./asm $var.s
	ressources/asm $var.s
	diff $var.cor $var.cor.me
	# rm $var.cor $var.cor.me