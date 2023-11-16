#!/bin/bash

source print_bar.sh

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'



mem()
{
let memmax=$(free -m | grep Mem | awk '{print $2}')/1000
let memuse=$(free -m | grep Mem | awk '{print $3}')/1000
echo $(printBar $memuse $memmax 7 ) $(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }') 
}

disk()
{
    let diskmax=$(df -h | grep sda1 | awk '{print $2}' | sed 's/.$//')
    let diskmin=$(df -h | grep sda1 | awk '{print $3}'| sed 's/.$//')/100
    echo $(printBar $diskmin $diskmax 7) $(df -h | grep sda1 | awk '{print $5}')
}

disk
#$(df -h | grep sda1 | awk '{print $3}')" "$(df -h | grep sda1 | awk '{print $2}')" "$(df -h | grep sda1 | awk '{print $5}')