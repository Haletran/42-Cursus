#!/bin/sh

echo "Broadcast message from $(hostname)@$(whoami) (tty1) $(date):"
echo ""
echo "#Architecture: $(uname -a)"
echo "#CPU physical: $(nproc --all)"
echo "#vCPU: $(cat /proc/cpuinfo | grep processor | wc -l)"

echo "#Memory Usage: $(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }')"
echo "#Disk Usage: " $(df -h | grep sda1 | awk '{print $3}')"/"$(df -h | grep sda1 | awk '{print $2}') "($(df -h | grep sda1 | awk '{print $5}'))"
echo "#CPU load: " $(top -bn1 | awk '/Cpu/ { print $2}')"%"
echo "#Last boot: $(last reboot | head -n 1 | awk '{print $5, $6, $7, $8}')"

# GET LVM USAGE
if grep -q "mapper" /etc/fstab; then
  echo "#LVM  use: yes"
else
  echo "#LVM use : no"
fi

echo "#Connection TCP: " $(netstat -an | grep -i "tcp" | grep ESTABLISHED | wc -l)
echo "#User log: $(ps auxwww | grep sshd | grep pts | wc -l)"

echo "#Network: " "IP" $(ip -4 addr show dev eno1 | awk '/inet / {print $2}') $(ip address | grep ether | head -n 1 | awk '{print $2}')
echo "#Sudo: " $(grep -c 'sudo:' /var/log/sudo/sudo.log)


