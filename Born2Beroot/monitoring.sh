#!/bin/bash

#OTHERS USEFULS SCRIPTS
source utils.sh

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

set -u

usage() {
  printf "Usage: $0 [-a <architecture>] [-c <cpu] ... [--all]"
}

while [ $# -gt 0 ]; do
  case "$1" in
    -a|--architecture)
      printf "${GREEN}Architecture:${NC} $(uname -a)"
      ;;
    -c|--cpu-physical)
      printf "${GREEN}CPU physical:${NC} $(nproc --all)"
      ;;
    -vc|--vcpu)
      "${GREEN}vCPU:${NC} $(cat /proc/cpuinfo | grep processor | wc -l)"
      ;;
    -m|--memory-usage)
      printf "${GREEN}Memory Usage:${NC} $(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }')"
      ;;
    -d|--disk-usage)
      printf "${GREEN}Disk Usage:${NC} $(df -h | grep sda1 | awk '{print $3}')/$(df -h | grep sda1 | awk '{print $2}') ($(df -h | grep sda1 | awk '{print $5}'))"
      ;;
    -cl|--cpu-load)
      printf "${GREEN}CPU load:${NC} $(top -bn1 | awk '/Cpu/ { print $2}')%"
      ;;
    -lb|--last-boot)
      printf "${GREEN}Last boot:${NC} $(last reboot | head -n 1 | awk '{print $5, $6, $7, $8}')"
      ;;
    -lvm|--lvm-use)
	  if lsblk | grep -q "lvm"; then printf "${GREEN}LVM use:${NC} yes"; else printf "${GREEN}LVM use:${NC} no"; fi
      ;;
    -tc|--tcp-connections)
      printf "${GREEN}Connection TCP:${NC} $(ss -neopt state established | wc -l)"
      ;;
    -ul|--user-log)
      printf "${GREEN}User log:${NC} $(users | wc -w)"
      ;;
    -n|--network)
      printf "${GREEN}Network:${NC} IP $(ip -4 addr show dev eno1 | awk '/inet / {print $2}') $(ip address | grep ether | head -n 1 | awk '{print $2}')"
      ;;
    -s|--sudo)
      printf "${GREEN}Sudo:${NC} $(journalctl -q _COMM=sudo | grep COMMAND | wc -l)"
      ;;
    --all)
      echo "#Architecture: $(uname -a)"
      echo "#CPU physical: $(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)"
      echo "#vCPU: $(grep "^processor" /proc/cpuinfo | wc -l)"
	    echo "#Memory Usage: $(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }')"
      echo "#Disk Usage: $(df -h | grep sda1 | awk '{print $3}')/$(df -h | grep sda1 | awk '{print $2}') ($(df -h | grep sda1 | awk '{print $5}'))"
      echo "#CPU load: $(top -bn1 | awk '/Cpu/ { print $2}')%"
      echo "#Last boot: $(last reboot | head -n 1 | awk '{print $5, $6, $7, $8}')"
      if lsblk | grep -q "lvm"; then echo "#LVM use: yes"; else echo "#LVM use: no"; fi
      echo "#Connection TCP: $(ss -neopt state established | wc -l)"
      echo "#User log: $(users | wc -w)"
      echo "#Network: IP $(ip -4 addr show dev eth0 | awk '/inet / {print $2}') $(ip address | grep ether | head -n 1 | awk '{print $2}')"
      echo "#Sudo: $(journalctl -q _COMM=sudo | grep COMMAND | wc -l)"
      ;;
    --allc)
      printf ${GREEN}$(whoami)${NC}@${GREEN}$(hostname)${NC}
	  printf "\n----------------------\n"
      printf "${GREEN}Architecture:${NC} $(uname -a)\n"
      printf "${GREEN}CPU physical:${NC} $(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)\n"
      printf "${GREEN}vCPU:${NC} $(grep "^processor" /proc/cpuinfo | wc -l)\n"
      printf "${GREEN}MemoryUsage:${NC} " && mem
      printf "${GREEN}Disk Usage: ${NC}%s/%s (%s)" "$(df -h | grep sda1 | awk '{print $3}')" "$(df -h | grep sda1 | awk '{print $2}')" "$(df -h | grep sda1 | awk '{print $5}')"
      printf "\n${GREEN}CPU load: ${NC}%s" "$(top -bn1 | awk '/Cpu/ { print $2}')"
      printf "\n${GREEN}Last boot: %s %s${NC}\n" "$(last reboot | head -n 1 | awk '{print $5, $6, $7, $8}')"
      if lsblk | grep -q "lvm"; then printf "${GREEN}LVM use:${NC} yes\n"; else printf "${GREEN}LVM use:${NC} no\n"; fi
      printf "${GREEN}Connection TCP:${NC} $(ss -neopt state established | wc -l)\n"
      printf "${GREEN}User log:${NC} $(users | wc -w)\n"
      printf "${GREEN}Network:${NC} IP $(ip -4 addr show dev eth0 | awk '/inet / {print $2}') $(ip address | grep ether | head -n 1 | awk '{print $2}')\n"
      printf "${GREEN}Sudo:${NC} $(journalctl -q _COMM=sudo | grep COMMAND | wc -l)"
	    printf "\n----------------------\n"
      ;;
    *)
      printf "${RED}Invalid option: $1${NC}"
	    usage
      exit 1
      ;;
  esac
  shift
done

