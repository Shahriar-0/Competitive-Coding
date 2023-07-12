filetype detect
set nocompatible
set exrc
set mouse=a
set tabstop=4
set shiftwidth=4

set autoindent
set smartindent
set cindent

set showcmd
set number
set autowrite
set autoread

set nowrap
colorscheme elflord

set keymodel=startsel,stopsel

map <F9> :<C-U>!g++ -O2 -std=c++11 -Wall -Wextra %:r.cpp -o %:r<CR>
map <F5> :<C-U>!./%:r<CR>
