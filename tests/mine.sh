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
	printf "%-10.10s : ${GREEN}[OK]${NC} NO FILE CREATED\n" "$1"
fi

if [ -e $1.cor ] && [ -e $1_zaz.cor ] && diff $1.cor $1_zaz.cor 1> /dev/null 2> /dev/null
then
	printf "%-10.10s : ${GREEN}[OK]${NC}\n" "$1"
	if [ -e $1.cor ]
		then
			hexdump -C $1.cor > ok_$1.txt
			rm $1.cor $1_zaz.cor
	fi
else

	if [ -e $1.cor ] && [ -e $1_zaz.cor ]
	then
		printf  "%-10.10s : ${RED}[KO]${NC} binary diff\n" "$1"
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
	printf "%-10.10s : ${RED}[KO]${NC} error on valid file\n" "$1"
	echo "$1.s : error not legit" >> all_error.txt
fi
if [ -e $1.cor ] && [ ! -e $1_zaz.cor ]
then
	printf "%-10.10s : ${RED}[KO]${NC} must be an error\n" "$1"
	echo "$1.s : missing an error" >> all_error.txt
fi
rm $1_zaz.s
