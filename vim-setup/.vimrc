" This is the custom vim file setup.... I will list the key changes upfront
" F2 - Toggle Line Numbers
" F7 - Toggle Buffer Explorer
" F8 - Toggle NerdTree
" F9 - Toggle Tagbar (for supported languages)
" Ctrl-J g - Generate a guid (insert mode only)
" F10 - Try to compile the file (Ctrl-F9) Compile and run (if can) - SimpleCompile
" F12 - Change make to use make instead of rake (Ctrl-F12) uses rake instead
"
" May need to uncomment below line if pathogen isn't loading correctly
" set nocp
"
" This sets the pathogen startup
runtime bundle/vim-pathogen/autoload/pathogen.vim
call pathogen#infect()
call pathogen#helptags()


" no vi compatibility
set nocompatible
filetype on
filetype indent on
filetype plugin on

" Turn on omni completion
set ofu=syntaxcomplete#Complete

" Colors - default, delek, slate, desert, evening, darkblue,
" Installed - rdark, jellybeans, railscasts, darkspectrum, vividchalk
"colorscheme slate
colorscheme vividchalk

" Turn on code folding (specifically for erlang)
set foldenable

set smartindent
set autoindent
set expandtab
set tabstop=2
set shiftwidth=2

" This is the notes directory for vim-pad
let g:pad_dir = "~/.notes/"

syntax on
set showmatch                       " Show matching [] and ()
set showmode

set makeprg=rake                    " Change make to rake...
nnoremap <F6> :set makeprg=make<cr>
nnoremap <F5> :set makeprg=rake<cr>
nmap <C-tab> :tabn<cr>


"set viminfo^=!                     " Add recently accessed projects menu

set number
set hls    " Search highlighting
nnoremap <F2> :set nonumber!<CR>:set foldcolumn=0<CR>


imap <c-j>g <c-r>=system('~/.vim/custom/guid_generator.py')<cr>
map <F8> :NERDTreeToggle <cr>
map <F9> :TagbarToggle <cr>
map <F7> :BufExplorer <cr>
map <c-n><c-p> :OpenPad <cr>
map <c-n><c-l> :ListPad <cr>


set cf                              " Enable error files & error jumping.
set clipboard=unnamed              " Yanks go to clipboard
set history=256
set autowrite                       " Writes on make/shell commands
set ruler
set timeoutlen=250                  " Time to wait after ESC
set bs=2                            " Backspace over everything in insert mode

set noerrorbells                    " No noise on errors

set laststatus=2                    " Always show status line

set mousehide                       " Hide mouse after chars typed
set mouse=a                         " Mouse is in all modes

set backup
set backupdir=~/.vimbackup
set directory=~/.vimtmp

nmap <c-b> :SCCompile<CR>
nmap <c-e> :SCCompileRun<CR>


" Play tetris with <leader>te  (leader defaults to \)
" quit it with :q or <Esc>


