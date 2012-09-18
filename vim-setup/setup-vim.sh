#!/bin/bash

# Move to the vim directory for this
cd $HOME/.vim/bundle

function install_plugin() 
{
  if [ -d "$1" ]; then
    echo "Updating $1"
    cd $1
    git checkout HEAD --force
    git pull
    cd ..
  else
    echo "Installing $1"
    git clone $2
  fi
}

### Install the vim pathogen which is the first item to run
#
install_plugin vim-pathogen https://github.com/tpope/vim-pathogen.git

### Install the next most commonly used vim plugins
# A tree explorer plugin for vim
install_plugin nerdtree https://github.com/scrooloose/nerdtree.git
# This allows for viewing open buffers (http://www.vim.org/scripts/script.php?script_id=42)
install_plugin bufexplorer.vim https://github.com/vimcn/bufexplorer.vim.git
# Buffer Explorer / Browser
install_plugin bufexplorer.zip https://github.com/vim-scripts/bufexplorer.zip.git
# Vim plugin for previewing markup files (markdown, rdoc, textile, html)
install_plugin vim-preview https://github.com/greyblake/vim-preview.git
# Ruby on Rails power tools
#install_plugin vim-rails https://github.com/tpope/vim-rails.git
# Vim/Ruby configuration Files
#install_plugin vim-ruby https://github.com/vim-ruby/vim-ruby.git
# Refactoring tool for Ruby in Vim
#install_plugin vim-ruby-refactoring https://github.com/ecomba/vim-ruby-refactoring.git
# Vim syntax highlight and snippets that helps coding application based in Sinatra micro-framework
#install_plugin vim-ruby-sinatra https://github.com/hallison/vim-ruby-sinatra.git
# switch Ruby version from inside Vim
#install_plugin vim-rvm https://github.com/tpope/vim-rvm.git
# Scala vim
#install_plugin vim-scala https://github.com/derekwyatt/vim-scala.git
# Vim plugin that displays tags in a window, ordered by class, etc
install_plugin tagbar https://github.com/majutsushi/tagbar.git
# Tools for fast XHTML and CSS coding
#install_plugin zen-coding https://github.com/sergeche/zen-coding.git
#
#install_plugin bash-support.vim https://github.com/vim-scripts/bash-support.vim.git
#
install_plugin gtags-multiwindow-browsing https://github.com/vim-scripts/gtags-multiwindow-browsing.git
#
install_plugin surround.vim https://github.com/vim-scripts/surround.vim.git
#
#install_plugin Syntastic https://github.com/vim-scripts/Syntastic.git
# ocaml.vim - vim conceal enhancement for ocaml
#install_plugin vim-ocaml-conceal https://github.com/vim-scripts/vim-ocaml-conceal.git
# Fast file navigation for VIM
install_plugin Command-T https://github.com/wincent/Command-T.git
# Syntax highlighting for Django templates
#install_plugin django.vim https://github.com/vim-scripts/django.vim.git
# The Erlang plugin for Vim
#install_plugin Vimerl https://github.com/vim-scripts/Vimerl.git
# Vim Markdown runtime files
install_plugin vim-markdown https://github.com/tpope/vim-markdown.git
# buffer/file/command/tag/etc explorer with fuzzy matching
install_plugin FuzzyFinder https://github.com/vim-scripts/FuzzyFinder.git
install_plugin L9 https://github.com/vim-scripts/L9.git

# This is a tetris game inside of vim (kind of cool)
install_plugin TeTrIs.vim https://github.com/vim-scripts/TeTrIs.vim.git


### Themes for VIM
# programming theme for gvim
install_plugin pw https://github.com/vim-scripts/pw.git
# a colorscheme strangely reminiscent of Vibrant Ink for a certain OS X editor
install_plugin vim-vividchalk https://github.com/tpope/vim-vividchalk.git

### These plugins require some execution to install
# A quick notetaking plugin
install_plugin vim-pad https://github.com/fmoralesc/vim-pad.git
if [ ! -d "$HOME/.notes" ]; then
  mkdir $HOME/.notes
fi
# HTML5 omnicomplete and syntax
install_plugin html5.vim https://github.com/othree/html5.vim.git
cd html5.vim
make install
cd ..


### These are some vim plugins that I don't need right now
##
#install_plugin textile.vim https://github.com/timcharper/textile.vim.git
## Plugin for the Perl module / CLI script 'ack'
#install_plugin ack.vim https://github.com/vim-scripts/ack.vim.git
## Lightweight support for Ruby's Bundler
#install_plugin vim-bundler https://github.com/tpope/vim-bundler.git
## CoffeeScript support for vim
#install_plugin vim-coffee-script https://github.com/kchmck/vim-coffee-script.git
## Vim Jade template engine syntax highlighting and indention
#install_plugin vim-jade https://github.com/digitaltoad/vim-jade.git
## Syntax file for jQuery in VIM
#install_plugin jquery.vim https://github.com/nono/jquery.vim.git
## extended % matching for HTML, LaTeX and many other languages
#install_plugin matchit.zip https://github.com/vim-scripts/matchit.zip.git
## A vim plugin making it more convenient to compile or run a single source file
#install_plugin SingleCompile https://github.com/xuhdev/SingleCompile.git
## Aims to be a concise vim script that implements some of TextMate's snippets features in Vim
#install_plugin snipmate.vim https://github.com/msanders/snipmate.vim.git
##Syntax Highlighting for Stylus
#install_plugin vim-stylus https://github.com/wavded/vim-stylus.git
## Perform all your vim insert mode completions with Tab
#install_plugin supertabl https://github.com/ervandew/supertab.git
## A custom text object for selecting ruby blocks
#install_plugin vim-textobj-rubyblock https://github.com/nelstrom/vim-textobj-rubyblock.git
## Support for user-defined text objects
#install_plugin vim-textobj-user https://github.com/kana/vim-textobj-user.git
## Just a development environment for VIM
#install_plugin vjde https://github.com/cespare/vjde.git
## ghetto HTML/XML mappings (formally allml.vim)
#install_plugin vim-ragtag https://github.com/tpope/vim-ragtag.git
## Map keys ')' and ']' to perform automatic formatting of parentheses content
#install_plugin Align.vim https://github.com/vim-scripts/Align.vim.git
## Vim Cucumber runtime files
#install_plugin vim-cucumber https://github.com/tpope/vim-cucumber.git
## endwise.vim: wisely add "end" in ruby, endfunction/endif/more in vim script, etc
#install_plugin vim-endwise https://github.com/tpope/vim-endwise.git
## A Git wrapper so awesome, it should be illegal
#install_plugin vim-fugitive https://github.com/tpope/vim-fugitive.git
## Vim runtime files for Haml, Sass and SCSS
#install_plugin vim-haml https://github.com/tpope/vim-haml.git
## Plugin for C/C++/ObjC/ObjC++ include directive completion
#install_plugin inccomplete https://github.com/vim-scripts/inccomplete.git
## Vim plugin for intensely commenting
#install_plugin nerdcommenter https://github.com/scrooloose/nerdcommenter.git





