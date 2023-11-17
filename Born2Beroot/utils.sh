#!/bin/sh

source print_bar.sh

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

#FONCTIONS
disk()
{
let diskmax=$(df -h | grep sdb1 | awk '{print $2}' | sed 's/.$//')
let diskmin=$(df -h | grep sdb1 | awk '{print $3}' | sed 's/.$//')/1000
echo $(printBar $diskmin $diskmax 7) $(df -h | grep sdb1 | awk '{print $5}')
}

mem()
{
let memmax=$(free -m | grep Mem | awk '{print $2}')/100
let memuse=$(free -m | grep Mem | awk '{print $3}')/1000
echo $(printBar $memuse $memmax 7 ) $(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }') 
}

internet()
{
wget -q --spider http://google.com

if [ $? -eq 0 ]; then
    printf "${GREEN}Internet:${NC} ONLINE"
else
    print "${GREEN}Internet:${NC} OFFLINE"
fi
}

Packages()
{
if command -v apt >/dev/null 2>&1; then
    package_manager="apt"
elif command -v yum >/dev/null 2>&1; then
    package_manager="yum"
elif command -v pacman >/dev/null 2>&1; then
    package_manager="pacman"
elif command -v zypper >/dev/null 2>&1; then
    package_manager="zypper"
else
    package_manager="unknown"
fi

if command -v dpkg >/dev/null 2>&1; then
    # Count the number of installed packages
    num_packages=$(dpkg --get-selections | grep -v deinstall | wc -l)

    printf "${GREEN}Packages:${NC} $num_packages ($package_manager)\n"
else
    echo "dpkg is not available. This script is designed for Debian-based systems."
fi
}
opsys()
{
if command -v lsb_release >/dev/null 2>&1; then
    os_name=$(lsb_release -si)
    printf "${GREEN}OS:${NC} $os_name\n"
else
    echo "lsb_release is not available. Unable to determine the operating system."
fi
}
cpu()
{
if [ -e "/proc/cpuinfo" ]; then
    # Get the CPU name using grep and awk
    cpu_name=$(grep -m1 "model name" /proc/cpuinfo | awk -F: '{print $2}' | xargs)
    printf "${GREEN}CPU:${NC} $cpu_name\n"
else
    echo "/proc/cpuinfo not found. Unable to determine CPU name."
fi
}
gpu()
{
if command -v lspci >/dev/null 2>&1; then
    # Get GPU information using lspci
    gpu_info=$(lspci | grep -i vga)
    
    if [ -n "$gpu_info" ]; then
        printf "${GREEN}GPU:${NC} $gpu_info\n"
    else
        echo "No GPU information found."
    fi
else
    echo "lspci is not available. Unable to determine GPU information."
fi
}



terminal_name=$(tty)
kernel=$(uname -r)
host=$(hostname)
#MemUsed = Memtotal + Shmem - MemFree - Buffers - Cached - SReclaimable


echo "====HARDWARE INFORMATION===="
cpu
gpu
printf "${GREEN}RAM:${NC} %s/%s\n" "$(df -h | grep sdb1 | awk '{print $3}')" "$(free -m | grep Mem | awk '{print $2}')"


echo "====SOFTWARE INFORMATION===="
opsys
printf "${GREEN}Host:${NC} $host\n"
printf "${GREEN}Kernel:${NC} $kernel\n"
printf "${GREEN}Shell:${NC} $terminal_name\n" 
Packages


echo "====SYSTEM INFORMATION===="
printf "${GREEN}Architecture:${NC} $(uname -o -p )\n"
printf "${GREEN}Date:${NC} $(date)\n"
printf "${GREEN}Last Reboot:${NC} $(last reboot | head -n 1 | awk '{print $5, $6, $7, $8}')\n"
printf "${GREEN}Uptime:${NC} $(uptime -p)\n"
printf "${GREEN}Locale:${NC} $(locale | grep "LANG=" | awk -F= '{print $2}')\n"
echo "====INTERNET INFORMATION===="
internet
printf "\n${GREEN}IP: ${NC}$(ip -4 addr show dev eth0 | awk '/inet / {print $2}')\n"
printf "${GREEN}MAC: ${NC}$(ip address | grep ether | head -n 1 | awk '{print $2}')\n"
echo "====SERVICES STATUS===="
if systemctl is-active --quiet "ssh"; then printf "${GREEN}SSH:${NC} Running\n" ; else printf "${GREEN}SSH:${NC} Not Running\n"; fi
if systemctl is-active --quiet "ufw"; then printf "${GREEN}UFW:${NC} Running\n" ; else printf "${GREEN}UFW:${NC} Not Running\n"; fi
echo "============================"
