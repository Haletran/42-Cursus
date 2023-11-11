#!bin/sh

USERNAME="bapasqui"
PACKAGES="vim ufw sudo curl git"
echo "password [success=2 default=ignore] pam_unix.so obscure sha512 minlen=10" >> /etc/pam.d/common-passwordpassword [success=2 default=ignore] pam_unix.so obscure sha512 minlen=8w ssh sudo libpam-pwquality"
GROUPS="$USERNAME 42"

#BASIC SETUP
su -
apt update && apt upgrade -y
apt install $PACKAGES
groupadd user42
usermod -aG sudo bapasqui42
usermod -aG user42 bapasqui42
exit
logout 

#SETUP SSH
STATUS="$(systemctl is-active sshd.service)"
if [ "${STATUS}" = "active"]; then
    echo "PORT 4242" >> /etc/ssh/ssh_config
else 
    sudo systemctl enable ssh.service
	sudo systemctl start ssh.service
	echo "Port 4242" >> /etc/ssh/ssh_config	  
fi

systemctl restart sshd

#SETUP UFW
echo "IPV6=yes" >> /etc/default/ufw
sudo ufw default deny incoming
sudo ufw allow ssh
sudo ufw enable


#SETUP PASSWORD DATE AND POLICIES
sudo chage --mindays 2 --warndays 7 --maxdays 30 $USERNAME
sudo chage --mindays 2 --warndays 7 --maxdays 30 root

sudo cp /etc/pam.d/common-password /etc/pam.d/common-password.bak
echo "password [success=3 default=ignore] pam_unix.so obscure sha512 minlen=10" >> /etc/pam.d/common-password

#
