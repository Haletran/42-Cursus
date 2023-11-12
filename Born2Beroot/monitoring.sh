#!bin/sh

echo "Broadcast message from $(hostname)@$(whoami) (tty1) $(date):"

echo "#Architecture: " $(uname -a)
echo "#CPU physical: " $(nproc --all)
echo "#vCPU: " $(cat /proc/cpuinfo | grep processor | wc -l)
echo "#Cpu load: " $(top -bn1 | awk '/Cpu/ { print $2}')"%"

echo "Memory Usage: " $(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }')
echo "Disk Usage: "
echo "CPU load: "

echo "Last boot: " $(last reboot | head - 1)

#GET LWM USAGE
if [ cat /etc/fstab | grep -q "mapper" ]; then 
  echo "#LVM  use: yes"
else
  echo "#LVM use : no"
fi

echo "#Connection TCP: "
echo "#User log: " $(ps auxwww | grep sshd | grep pts | wc -l)

echo "#Network: "
echo "#Sudo: "



