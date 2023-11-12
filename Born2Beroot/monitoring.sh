#!bin/sh

echo "#Architecture: " $(uname -a)
echo "#CPU physical: " $(nproc --all)
echo "#vCPU: " $(cat /proc/cpuinfo | grep processor | wc -l)
echo "#Cpu load: " $(top -bn1 | awk '/Cpu/ { print $2}')"%"


## TEST
echo "Memory Usage: " $(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }')
echo "Last boot: " $(last reboot | head - 1)

#GET LWM USAGE
if [ cat /etc/fstab | grep -q "mapper" ]; then 
  echo "#LVM  use: yes"
else
  echo "#LVM use : no"
fi

echo "#User log: " $(ps auxwww | grep sshd | grep pts | wc -l)




