#!/bin/bash

echo
echo '---------------------------------------'
echo '2 VALUES'
echo '---------------------------------------'
echo

for i in {0..1}
do
	for j in {0..1}
	do
		if [ $j != $i ]
		then
			printf "[$i $j]"
			result=`./push_swap $i $j $k | ./checker $i $j $k`
			if [ $result = 'OK' ]
			then
				echo -e '\e[32mOK'
			else
				echo -e '\e[31mKO'
			fi
			printf '\e[0m'
		fi
	done
done

echo
echo '---------------------------------------'
echo '3 VALUES'
echo '---------------------------------------'
echo

for i in {0..2}
do
	for j in {0..2}
	do
		if [ $j != $i ]
		then
			for k in {0..2}
			do
				if [ $k != $i ] && [ $k != $j ]
				then
					printf "[$i $j $k]"
					result=`./push_swap $i $j $k | ./checker $i $j $k`
					if [ $result = 'OK' ]
					then
						echo -e '\e[32mOK'
					else
						echo -e '\e[31mKO'
					fi
					printf '\e[0m'
				fi
			done
		fi
	done
done

echo
echo '---------------------------------------'
echo '4 VALUES'
echo '---------------------------------------'
echo

for i in {0..3}
do
	for j in {0..3}
	do
		if [ $j != $i ]
		then
			for k in {0..3}
			do
				if [ $k != $i ] && [ $k != $j ]
				then
					for l in {0..3}
					do
						if [ $l != $i ] && [ $l != $j ] && [ $l != $k ]
						then
							printf "[$i $j $k $l]"
							result=`./push_swap $i $j $k $l | ./checker $i $j $k $l`
							if [ $result = 'OK' ]
							then
								echo -e '\e[32mOK'
							else
								echo -e '\e[31mKO'
							fi
							printf '\e[0m'
						fi
					done
				fi
			done
		fi
	done
done

echo
echo '---------------------------------------'
echo '5 VALUES'
echo '---------------------------------------'
echo

for i in {0..4}
do
	for j in {0..4}
	do
		if [ $j != $i ]
		then
			for k in {0..4}
			do
				if [ $k != $i ] && [ $k != $j ]
				then
					for l in {0..4}
					do
						if [ $l != $i ] && [ $l != $j ] && [ $l != $k ]
						then
							for m in {0..4}
							do
								if [ $m != $i ] && [ $m != $j ] && [ $m != $k ] && [ $m != $l ]
								then
									printf "[$i $j $k $l $m]"
									result=`./push_swap $i $j $k $l $m | ./checker $i $j $k $l $m`
									if [ $result = 'OK' ]
									then
										echo -e '\e[32mOK'
									else
										echo -e '\e[31mKO'
									fi
									printf '\e[0m'
								fi
							done
						fi
					done
				fi
			done
		fi
	done
done
