#!/bin/bash - 
#===============================================================================
#
#          FILE: setup.sh
# 
#         USAGE: ./setup.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 09/18/2012 02:02:38 PM MDT
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

read -p "This is a destructive operation, will remove .vimrc and .vim if they exist, continue? [y/N] " yn
case $yn in 
  [Yy] ) break;;
  * ) exit;;
esac

if [ -f $HOME/.vimrc ]; then
  echo "Removing $HOME/.vimrc"
  rm $HOME/.vimrc
fi

if [ -d $HOME/.vim ]; then
  echo "Removing $HOME/.vim"
  rm -rf $HOME/.vim
fi

cp -r .vim $HOME/.vim
cp .vimrc $HOME/.vimrc
cd $HOME/.vim
./setup-vim.sh

