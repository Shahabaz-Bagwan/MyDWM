#!/bin/bash

echo "Updating the system...."
sudo apt update
sudo apt upgrade

echo "Installing applicaiton and dependencies...."
sudo apt install fish python3-pip git make cmake automake autoconf gcc \
feh imagemagic ranger pavucontrol blueman thunar rofi dmenu vim gsimplecal \
mpv kdenlive vscode w3m scrot libboost-program-options1.71-dev \
libpulse-dev htop curl libxft-dev libfontconfig1-dev libxinerama-dev \
libx11-dev scrot zathura

echo "Getting configs from git and setting them...."
git clone https://github.com/shahabaz-bagwan/dotfiles.git ~/github

echo "Installing correct fonts...."
if [ -d "$HOME/.fonts" ]; then
  echo "Installing fonts in $HOME/.fonts..."
	cp $HOME/github/fonts/* $HOME/.fonts/
	unzip $HOME/.fonts/Inconsolata.zip -d $HOME/.fonts
	fc-cache -fv
else
  echo "Creating $HOME/.fonts  directory and installing fonts in $HOME/.fonts "
	mkdir $HOME/.fonts
	cp $HOME/github/fonts/* $HOME/.fonts
	unzip $HOME/.fonts/Inconsolata.zip -d $HOME/.fonts
	fc-cache -fv
fi

echo "change shell to fish shell...."
sudo chsh -s /usr/bin/fish $USER

touch $HOME/scrp.sh
curl -L https://get.oh-my.fish > $HOME/scrp.sh
fish $HOME/scrp.sh --noninteractive

fish << 'themeInstall'
	echo	"Setting fish theme as bobthefish"
	omf install bobthefish
  omf install fzf  
themeInstall

echo "linking configs..."
if [ -d "$HOME/.config/fish" ]; then
	ln -sf $HOME/github/config.fish $HOME/.config/fish/config.fish
else
	mkdir $HOME/.config/fish
	ln -sf $HOME/github/config.fish $HOME/.config/fish/config.fish
fi

ln -sf $HOME/github/vimrc $HOME/.vimrc
ln -sf $HOME/github/Xresources $HOME/.Xresources
xrdb -merge $HOME/.Xresources
ln -sf $HOME/github/xbindkeysrc $HOME/.xbindkeysrc

echo "Installing pywal..."
sudo pip3 install pywal

echo "Installing pamixer...."
git clone https://github.com/cdemoulins/pamixer /tmp/pamixer
cd /tmp/pamixer
sudo make install
cd ~
rm /tmp/pamixer

echo "Installing dwm..."
git clone https://github.com/shahabaz-bagwan/mydwm ~/repos/dwm
cd ~/repos/dwm
sudo make install

echo "Adding login session...."
sudo cp dwm.desktop /usr/share/xsession/dwm.desktop
sudo cp myDwmStart.sh /usr/local/bin/
ln -srf .dwm ~/.dwm

echo "Copying scripts.."
cp battery clock cpu forecast internet memory volume ~/.local/bin/
cd ~

echo "Installing Simple Terminal...."
git clone https://github.com/shahabaz-bagwan/sucklessTerminal ~/repos/st
cd ~/repos/st
sudo make install
cd ~

echo "Installing dwmblocks...."
git clone https://github.com/shahabaz-bagwan/dwmblocks ~/repos/dwmblocks
cd ~/repos/dwmblocks
sudo make install
cd ~

exit 0
