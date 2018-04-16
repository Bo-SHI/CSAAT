#! /bin/bash

trap bashtrap INT
clear;

bashtrap()
{
    echo "CTRL+C Detected!...executing bash trap!"
}

for i in `seq 1 10`; do
    echo "${i}/10 to exit"
    sleep 1
done
echo "Exit Bash Trap Example"
