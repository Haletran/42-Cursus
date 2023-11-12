#!bin/sh

USERNAME="bapasqui"
PACKAGES="vim ufw sudo curl git"

#BASIC SETUP
apt update && apt upgrade -y
apt install $PACKAGES
groupadd user42
usermod -aG sudo $USERNAME
usermod -aG user42 $USERNAME
hostname set-hostname $USERNAME"42"

#SETUP UFW
echo "IPV6=yes" >> /etc/default/ufw
sudo ufw default deny incoming
sudo ufw allow 4242/tcp
sudo ufw enable

#SETUP SSH
STATUS="$(systemctl is-active sshd.service)"
if [ "${STATUS}" = "active"]; then
    echo "PORT 4242" >> /etc/ssh/sshd_config
    echo "AllowGroups root" >> /ect/ssh/sshd_config
    echo "DenyUsers user42" >> /etc/ssh/sshd_config
    echo "PermitRootLogin yes" >> /etc/ssh/sshd_config
else 
    sudo systemctl enable ssh.service
    sudo systemctl start ssh.service
    echo "Port 4242" >> /etc/ssh/sshd_config	  
fi
systemctl restart ssh

#SETUP PASSWORD DATE AND POLICIES
sudo chage --mindays 2 --warndays 7 --maxdays 30 $USERNAME
sudo chage --mindays 2 --warndays 7 --maxdays 30 root

sudo cp /etc/pam.d/common-password /etc/pam.d/common-password.bak
echo "password [success=3 default=ignore] pam_unix.so obscure sha512 minlen=10" >> /etc/pam.d/common-password

#SETUP SUDO
MESSAGE="//Your Custom Failed Sudo Message"
mkdir /var/log/sudo
echo "Defaults    passwd_tries=3" >> /etc/sudoers
echo "Defaults    badpass_message=$MESSAGE" >> /etc/sudoers
echo "Defaults    logfile="/var/log/sudo/sudo.log"" >> /etc/sudoers
echo "Defaults    log_input, log_output" >> /etc/sudoers
echo "Defaults    requiretty" >> /etc/sudoers
echo "Defaults    secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"" >> /etc/sudoers


