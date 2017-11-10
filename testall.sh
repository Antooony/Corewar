path=$1
list=`ls $path*.s`

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

	make asm
	for file in $list
	do
		var=${file%.s}
		disp=`echo $file | rev | cut -d'/' -f 1 | rev`
		./asm $var.s > /dev/null
		ressources/asm $var.s > /dev/null
		if [ -f $var.cor ] && [ -f $var.cor.me ]
		then
			if diff $var.cor $var.cor.me #> /dev/null 2> /dev/null
			then
				echo $disp ${GREEN}OK${NC}
			else
				echo $disp ${RED}KO${NC}
			fi
		elif [ -f $var.cor ]
		then
			echo $disp ${RED}ERROR${NC}
		elif [ -f $var.cor ]
		then
			echo $disp ${RED}ERROR${NC}
		else
			echo $disp ${GREEN}OK${NC}
		fi
		rm $var.cor $var.cor.me 2> /dev/null
	done
