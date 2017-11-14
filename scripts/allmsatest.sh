path=$1
list=`ls $path*.s`
for file in $list
do
	var=${file%.s}
	sh ./msatest.sh $var
done