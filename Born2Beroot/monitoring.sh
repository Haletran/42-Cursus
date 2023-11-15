#!/bin/sh

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

set -u

usage() {
  echo "Usage: $0 [-a <architecture>] [-c <cpu] ... [--all]"
}

while [ $# -gt 0 ]; do
  case "$1" in
    -a|--architecture)
      echo "${GREEN}Architecture:${NC} $(uname -a)"
      ;;
    -c|--cpu-physical)
      echo "${GREEN}CPU physical:${NC} $(nproc --all)"
      ;;
    -vc|--vcpu)
      "${GREEN}vCPU:${NC} $(cat /proc/cpuinfo | grep processor | wc -l)"
      ;;
    -m|--memory-usage)
      echo "${GREEN}Memory Usage:${NC} $(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }')"
      ;;
    -d|--disk-usage)
      echo "${GREEN}Disk Usage:${NC} $(df -h | grep sda1 | awk '{print $3}')/$(df -h | grep sda1 | awk '{print $2}') ($(df -h | grep sda1 | awk '{print $5}'))"
      ;;
    -cl|--cpu-load)
      echo "${GREEN}CPU load:${NC} $(top -bn1 | awk '/Cpu/ { print $2}')%"
      ;;
    -lb|--last-boot)
      echo "${GREEN}Last boot:${NC} $(last reboot | head -n 1 | awk '{print $5, $6, $7, $8}')"
      ;;
    -lvm|--lvm-use)
	  if lsblk | grep -q "lvm"; then echo "${GREEN}LVM use:${NC} yes"; else echo "${GREEN}LVM use:${NC} no"; fi
      ;;
    -tc|--tcp-connections)
      echo "${GREEN}Connection TCP:${NC} $(ss -neopt state established | wc -l)"
      ;;
    -ul|--user-log)
      echo "${GREEN}User log:${NC} $(users | wc -w)"
      ;;
    -n|--network)
      echo "${GREEN}Network:${NC} IP $(ip -4 addr show dev eno1 | awk '/inet / {print $2}') $(ip address | grep ether | head -n 1 | awk '{print $2}')"
      ;;
    -s|--sudo)
      echo "${GREEN}Sudo:${NC} $(journalctl -q _COMM=sudo | grep COMMAND | wc -l)"
      ;;
    --all)
      echo "----------------------"
      echo "#Architecture: $(uname -a)"
      echo "#CPU physical: $(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)"
      echo "#vCPU: $(grep "^processor" /proc/cpuinfo | wc -l)"
	  echo "#Memory Usage: $(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }')"
      echo "#Disk Usage: $(df -h | grep sda1 | awk '{print $3}')/$(df -h | grep sda1 | awk '{print $2}') ($(df -h | grep sda1 | awk '{print $5}'))"
      echo "#CPU load: $(top -bn1 | awk '/Cpu/ { print $2}')%"
      echo "#Last boot: $(last reboot | head -n 1 | awk '{print $5, $6, $7, $8}')"
      if lsblk | grep -q "lvm"; then echo "LVM use: yes"; else echo "LVM use: no"; fi
      echo "#Connection TCP: $(ss -neopt state established | wc -l)"
      echo "#User log: $(users | wc -w)"
      echo "#Network: IP $(ip -4 addr show dev eno1 | awk '/inet / {print $2}') $(ip address | grep ether | head -n 1 | awk '{print $2}')"
      echo "#Sudo: $(journalctl -q _COMM=sudo | grep COMMAND | wc -l)"
	    echo "----------------------"
      ;;
    --allc)
      echo ${GREEN}$(whoami)${NC}@${GREEN}$(hostname)${NC} | wall
	  echo "----------------------"
      echo "${GREEN}Architecture:${NC} $(uname -a)"
      echo "${GREEN}CPU physical:${NC} $(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)"
      echo "${GREEN}vCPU:${NC} $(grep "^processor" /proc/cpuinfo | wc -l)"
	  echo "${GREEN}Memory Usage:${NC} $(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }')"
      echo "${GREEN}Disk Usage:${NC} $(df -h | grep sda1 | awk '{print $3}')/$(df -h | grep sda1 | awk '{print $2}') ($(df -h | grep sda1 | awk '{print $5}'))"
      echo "${GREEN}CPU load:${NC} $(top -bn1 | awk '/Cpu/ { print $2}')%"
      echo "${GREEN}Last boot:${NC} $(last reboot | head -n 1 | awk '{print $5, $6, $7, $8}')"
      if lsblk | grep -q "lvm"; then echo "${GREEN}LVM use:${NC} yes"; else echo "${GREEN}LVM use:${NC} no"; fi
      echo "${GREEN}Connection TCP:${NC} $(ss -neopt state established | wc -l)"
      echo "${GREEN}User log:${NC} $(users | wc -w)"
      echo "${GREEN}Network:${NC} IP $(ip -4 addr show dev eno1 | awk '/inet / {print $2}') $(ip address | grep ether | head -n 1 | awk '{print $2}')"
      echo "${GREEN}Sudo:${NC} $(journalctl -q _COMM=sudo | grep COMMAND | wc -l)"
	    echo "----------------------"
      ;;
    *)
      echo "${RED}Invalid option: $1${NC}"
	    usage
      exit 1
      ;;
  esac
  shift
done

