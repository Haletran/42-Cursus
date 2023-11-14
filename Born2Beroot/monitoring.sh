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
      echo "${GREEN}Connection TCP:${NC} $(netstat -an | grep -i "tcp" | grep ESTABLISHED | wc -l)"
      ;;
    -ul|--user-log)
      echo "${GREEN}User log:${NC} $(ps auxwww | grep sshd | grep pts | wc -l)"
      ;;
    -n|--network)
      echo "${GREEN}Network:${NC} IP $(ip -4 addr show dev eno1 | awk '/inet / {print $2}') $(ip address | grep ether | head -n 1 | awk '{print $2}')"
      ;;
    -s|--sudo)
      echo "${GREEN}Sudo:${NC} $(grep -c -s 'sudo:' /var/log/sudo/sudo.log)"
      ;;
    --all)
      echo ${GREEN}$(whoami)${NC}@${GREEN}$(hostname)${NC}
	  echo "----------------------"
      echo "${GREEN}Architecture:${NC} $(uname -a)"
      echo "${GREEN}CPU physical:${NC} $(nproc --all)"
      echo "${GREEN}vCPU:${NC} $(cat /proc/cpuinfo | grep processor | wc -l)"
	  echo "${GREEN}Memory Usage:${NC} $(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }')"
      echo "${GREEN}Disk Usage:${NC} $(df -h | grep sda1 | awk '{print $3}')/$(df -h | grep sda1 | awk '{print $2}') ($(df -h | grep sda1 | awk '{print $5}'))"
      echo "${GREEN}CPU load:${NC} $(top -bn1 | awk '/Cpu/ { print $2}')%"
      echo "${GREEN}Last boot:${NC} $(last reboot | head -n 1 | awk '{print $5, $6, $7, $8}')"
      if lsblk | grep -q "lvm"; then echo "${GREEN}LVM use:${NC} yes"; else echo "${GREEN}LVM use:${NC} no"; fi
      echo "${GREEN}Connection TCP:${NC} $(netstat -an | grep -i "tcp" | grep ESTABLISHED | wc -l)"
      echo "${GREEN}User log:${NC} $(ps auxwww | grep sshd | grep pts | wc -l)"
      echo "${GREEN}Network:${NC} IP $(ip -4 addr show dev eno1 | awk '/inet / {print $2}') $(ip address | grep ether | head -n 1 | awk '{print $2}')"
      echo "${GREEN}Sudo:${NC} $(grep -c -s 'sudo:' /var/log/sudo/sudo.log)"
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

