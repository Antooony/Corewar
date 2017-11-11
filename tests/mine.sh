RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m'
cp $1.s $1_zaz.s
printf ${YELLOW}
./asm_zaz $1_zaz.s > /dev/null
printf ${NC}
./asm $1.s > /dev/null
if [  ! -e $1_zaz.cor ] && [ ! -e $1.cor ]
then
	echo "$1 : ${GREEN}[OK]${NC} NO FILE CREATE"
fi

if [ -e $1.cor ] && [ -e $1_zaz.cor ] && diff $1.cor $1_zaz.cor
then
	echo "$1: ${GREEN}[OK]${NC}"
	if [ -e $1.cor ]
		then
			hexdump -C $1.cor > ok_$1.txt
			rm $1.cor $1_zaz.cor
	fi
else

	if [ -e $1.cor ] && [ -e $1_zaz.cor ]
	then
		echo $1": ${RED}[KO]${NC}"
		diff $1.cor $1_zaz.cor > diff_$1.txt
		echo "\n\n$1.cor \n" >> diff_$1.txt
		hexdump -C $1.cor >> diff_$1.txt
		echo "\n\n$1_zaz.cor\n" >> diff_$1.txt
		hexdump -C $1_zaz.cor >> diff_$1.txt
		echo "$1.s : binary diff" >> all_error.txt
	fi
fi
if [ ! -e $1.cor ] && [ -e $1_zaz.cor ]
then
	echo "J'ai une erreur que je ne devrais pas avoir ${RED}$1.s${NC}"
	echo "$1.s : error not legit" >> all_error.txt
fi
if [ -e $1.cor ] && [ ! -e $1_zaz.cor ]
then
	echo "Il me manque la detection d'une erreur sur le fichier ${RED}$1.s${NC}"
	echo "$1.s : missing an error" >> all_error.txt
fi
rm $1_zaz.s
