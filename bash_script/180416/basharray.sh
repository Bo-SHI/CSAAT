#! /bin/bash
declare -a Array

exec 10<&0

exec < $1

let count=0

while read LINE; do
    Array[${count}]=${LINE}
    ((count++))
done

echo Number of elements: ${#Array[@]}

echo ${Array[@]}

exec 0<&10 10<&-
