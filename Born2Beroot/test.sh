#!/bin/bash

source print_bar.sh
source utils.sh

mem()
{
let memmax=$(free -m | grep Mem | awk '{print $2}')/1000
let memuse=$(free -m | grep Mem | awk '{print $3}')/1000
echo "#Memory Usage:" $(printBar $memuse $memmax 7 ) $(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }')
}
