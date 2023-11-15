#!/bin/bash

set -u

#ANSI COLORS
DEF_COLOR='\033[0;39m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
CYAN='\033[0;96m'
NC='\033[0m'
RED='\033[0;31m'

#VARS
DISTRIB=$(lsb_release -a | grep Di | awk '{print $3}')

usage() {
  printf "\n${RED}Usage:${NC} $0 [-p1 <part1>] [-p2 <part2> ] [-b <bonus>]\n"
}

pres() {
  printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};
  printf ${YELLOW}"\n\t\tSCRIPT CREATED BY: "${DEF_COLOR};
  printf ${CYAN}"bapasqui\t\n"${DEF_COLOR};
  printf ${YELLOW}"\t    Github : ${NC}https://github.com/Haletran\t\n"${DEF_COLOR};
  printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};
}

while [ $# -gt 0 ]; do
  case "$1" in
    -p1 | --part1)
      if [ "$EUID" -ne 0 ]; then
        echo "Please run this script as root. (Using this command : su -)"
        exit 1
      fi
      pres
      # READ USER INPUT
      read -p $'\e[33mWhat is your username ?\e[0m ' USERNAME
      printf "${RED}~10 characters long, an uppercase letter, a lowercase letter, \nand a number, not 3 consecutive identical characters.\n${NC}"
      read -p "Enter the password for user: " PASSWORD
      read -p "Enter the password for root: " ROOT_PASSWORD

      #BASIC SETUP
      apt-get update && sudo apt-get upgrade -y
      apt-get install -y sudo
      if [ $? -eq 0 ]; then echo "sudo installed successfully."; else echo "Failed to install sudo."; fi
      apt-get install -y ufw vim net-tools
      groupadd user42
      if ! id "$USERNAME" &>/dev/null; then
        useradd -m -s /bin/bash "$USERNAME"
        echo "$USERNAME:$PASSWORD" | chpasswd 
        if [ $? -eq 0 ]; then echo "$USERNAME password changed successfully."; else echo "Failed to change $USERNAME password."; fi
      else 
        echo "$USERNAME:$PASSWORD" | chpasswd
        if [ $? -eq 0 ]; then echo "$USERNAME password changed successfully."; else echo "Failed to change $USERNAME password."; fi
      fi

      usermod -aG sudo $USERNAME
      usermod -aG user42 $USERNAME
      hostnamectl set-hostname $USERNAME"42"

      #CHANGE SUDO PASSWORD
      echo "root:$ROOT_PASSWORD" | chpasswd
      if [ $? -eq 0 ]; then echo "Root password changed successfully."; else echo "Failed to change root password."; fi
      cp -r "../Born2Beroot" "/home/$USERNAME/"
      printf "Logout of root and $USERNAME.\n Login as $USERNAME and execute the second part of the script.\n (sudo ./setup.sh -p2)"
      ;;
  -p2 | --part2)
      if [ "$EUID" -ne 0 ]; then
        printf "Please run this script as sudo. \n(sudo bash setup.sh <parameters> or sudo ./setup.sh <parameters>)\n"
        exit 1
      fi
      pres

      #GET USERNAME
      USERNAME=$(whoami)
      
      #SETUP UFW
      echo "IPV6=yes" >> /etc/default/ufw
      sudo ufw default deny incoming
      sudo ufw allow 4242/tcp
      sudo ufw enable
      
      #SETUP SSH
      if [systemctl is-active sshd.service | grep -q "active"]; then
          echo "PORT 4242" >> /etc/ssh/sshd_config
      else 
          sudo systemctl enable ssh.service
          sudo systemctl start ssh.service
          echo "Port 4242" >> /etc/ssh/sshd_config	  
      fi
      echo "PermitRootLogin no" >> /etc/ssh/sshd_config
      systemctl restart ssh
      
      #SETUP PASSWORD EXPIRATION DATE AND POLICIES
      sudo chage --mindays 2 --warndays 7 --maxdays 30 $USERNAME
      sudo chage --mindays 2 --warndays 7 --maxdays 30 root
      sudo cp /etc/pam.d/common-password /etc/pam.d/common-password.bak
      sudo echo "password [success=3 default=ignore] pam_unix.so obscure sha512 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 difok=7 enforce_for_root reject_username" >> /etc/pam.d/common-password
      
      #SETUP SUDO
      read -p $'\e[33mCustom Message for failed Sudo password: \e[0m ' MESSAGE
      mkdir -p /var/log/sudo
      sudo echo "Defaults    passwd_tries=3" >> /etc/sudoers
      sudo echo "Defaults    badpass_message="$'\042'"$MESSAGE"$'\042' >> /etc/sudoers
      sudo echo "Defaults    logfile="$'\042'"/var/log/sudo/sudo.log"$'\042' >> /etc/sudoers
      sudo echo "Defaults    log_input, log_output" >> /etc/sudoers
      sudo echo "Defaults    requiretty" >> /etc/sudoers
      sudo echo "Defaults    secure_path="$'\042'"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"$'\042' >> /etc/sudoers
      sudo echo "$USERNAME  ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh" >> /etc/sudoers

      #SETUP CRONJOB
      mv monitoring.sh /usr/local/bin/monitoring.sh
      #sudo crontab -u root -e
      #*/10 * * * * /usr/local/bin/monitoring.sh

      printf "${YELLOW}Your $DISTRIB VM is ready, you might need to change your password if you didn't respect policy${NC}\n"
      ;;
  -b | --bonus)
      if [ "$EUID" -ne 0 ]; then
        printf "Please run this script as sudo. \n(sudo bash setup.sh <parameters> or sudo ./setup.sh <parameters>)\n"
        exit 1
      fi
      pres
      echo "Figure out by yourself how to do the bonus part"
      ;;
  -t | --test)
      if [ "$EUID" -ne 0 ]; then
        echo "Please run this script as root. (Using this command : su -)"
        exit 1
      fi
      #CHECK IF APP ARMOR or SELINUX IS ENABLED (for Debian 10< or for Rocky)
      if cat /etc/os-release | grep -q Debian; then 
      	if (cat /sys/module/apparmor/parameters/enabled | grep -q Y); then echo "AppArmor already enabled"; else echo "You need to enable AppArmor"; fi
      else
      	if (sestatus | grep -q enabled); then echo "SELINUX already enabled"; else echo "You need to enable SELINUX"; fi
      fi

      #CLONE AND USE TESTER
      git clone https://github.com/gemartin99/Born2beroot-Tester.git tester
      cd tester
      bash Test.sh
      ;;
  *)
      printf "${RED}Invalid option:${NC} $1"
	    usage
      exit 1
      ;;
  esac
  shift
done

