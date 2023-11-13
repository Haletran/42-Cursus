#!bin/sh

#GET VARIABLES FROM USER
read -p $'\e[33mWhat is your username ?\e[0m ' USERNAME
read -p $'\e[33mWhich packages do you want to install\e[0m ' PACKAGES

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
else 
    sudo systemctl enable ssh.service
    sudo systemctl start ssh.service
    echo "Port 4242" >> /etc/ssh/sshd_config	  
fi
echo "AllowGroups root" >> /ect/ssh/sshd_config
echo "DenyUsers user42" >> /etc/ssh/sshd_config
echo "PermitRootLogin yes" >> /etc/ssh/sshd_config
systemctl restart ssh

#SETUP PASSWORD DATE AND POLICIES
sudo chage --mindays 2 --warndays 7 --maxdays 30 $USERNAME
sudo chage --mindays 2 --warndays 7 --maxdays 30 root

sudo cp /etc/pam.d/common-password /etc/pam.d/common-password.bak
echo "password [success=3 default=ignore] pam_unix.so obscure sha512 minlen=10" >> /etc/pam.d/common-password

#SETUP SUDO
read -p $'\e[33mCustom Message for failed Sudo password: \e[0m ' MESSAGE
mkdir /var/log/sudo
echo "Defaults    passwd_tries=3" >> /etc/sudoers
echo "Defaults    badpass_message="$'\042'"$MESSAGE"$'\042' >> /etc/sudoers
echo "Defaults    logfile="$'\042'"/var/log/sudo/sudo.log"$'\042' >> /etc/sudoers
echo "Defaults    log_input, log_output" >> /etc/sudoers
echo "Defaults    requiretty" >> /etc/sudoers
echo "Defaults    secure_path="$'\042'"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"$'\042' >> /etc/sudoers


