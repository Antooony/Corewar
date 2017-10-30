path=$1
list=`ls $path*.s`

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

	for file in $list
	do
		var=${file%.s}
		./asm $var.s > /dev/null
		ressources/asm $var.s > /dev/null 
		if diff $var.cor $var.cor.me #> /dev/null 2> /dev/null
		then
			echo $var.s ${GREEN}OK${NC}
		else
			echo $var.s ${RED}KO${NC}
		fi
		rm $var.cor $var.cor.me 2> /dev/null
	done