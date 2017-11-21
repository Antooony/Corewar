RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

	../tests/asm_zaz $1.s 1> /dev/null 2>/dev/null
	if [ -e $1.cor ]
	then
		../msa $1.cor 1> /dev/null 2>/dev/null
	else
		echo "${GREEN}[OK]${NC} $1.s !.cor"
		rm -f $1.cor $1_r.s $1_r.cor $1_r.txt $1.txt
		exit
	fi
	if [ -e $1_r.s ]
	then
		../tests/asm_zaz $1_r.s 1> /dev/null 2>/dev/null
	else
		echo "${RED}[KO] ${NC} $1.s !_r.s"
		rm -f $1.cor $1_r.cor $1_r.txt $1.txt
		exit
	fi
	if [ ! -e $1_r.cor ]
	then
		echo "${RED}[KO] ${NC} $1.s !_r.cor"
		rm -f $1.cor $1_r.cor $1_r.txt $1.txt
		exit
	fi
	hexdump -C $1.cor > $1.txt
	hexdump -C $1_r.cor > $1_r.txt
	if [ -f $1.txt ] && [ -f $1_r.txt ]
	then
		if diff $1.txt $1_r.txt 1> /dev/null 2>/dev/null
		then
			echo "${GREEN}[OK] ${NC}$1.s"
		else
			echo "${RED}[KO] ${NC}$1.s"
		fi
	fi

rm $1.cor $1_r.s $1_r.cor $1_r.txt $1.txt