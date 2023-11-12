#!bin/sh

echo "#Architecture: " $(uname -a)
echo "#CPU physical: " $(nproc --all)
echo "#vCPU: " $(cat /proc/cpuinfo | grep processor | wc -l)
echo "#Cpu load: " $(top -bn1 | awk '/Cpu/ { print $2}')"%"


## TEST
echo "Memory Usage: " $(cat /proc/meminfo | grep MemAvailable) / $(cat /proc/meminfo/ grep MemTotal)
echo "Last boot: " $(last reboot | head - 1)


