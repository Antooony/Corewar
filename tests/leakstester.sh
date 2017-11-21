var=`top -l 1 | grep $1 | cut -d" " -f1`
leaks $1
kill $var