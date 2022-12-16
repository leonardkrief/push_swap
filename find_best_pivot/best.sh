#!/bin/bash

x=1;
avg_best_sort=0;
avg_best_pivot=0;
size=$(($2-$1));
while [[ "$x" -le $3 ]]
do
	echo -n "($x) ";
	ARG=$(shuf -i $1-$2 -n $((size)) | tr ":\n" " ");
	ARG=$(./push_swap $ARG);
	avg_best_pivot=$((avg_best_pivot+`echo $ARG | awk '{print $6}'`));
	avg_best_sort=$((avg_best_sort+`echo $ARG | awk '{print $9}'`));
	x=$((x+1))
done
echo ""
x=$((x-1))
printf "\nfinal best pivot = "
printf %.5f "$((100000 * avg_best_pivot / (size*x)))e-5"
printf " * $size";
printf "\nfinal best sort = "
printf %.5f "$((100000 * avg_best_sort / (size*x)))e-5"
printf " * $size\n";