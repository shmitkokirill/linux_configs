" Vundle config
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
Plugin 'ycm-core/YouCompleteMe'
Plugin 'NLKNguyen/papercolor-theme'
Plugin 'xuhdev/vim-latex-live-preview'
Plugin 'preservim/nerdtree'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to 
" auto-approve removal
"
" see :h vundle for more details or wiki for FAQ

" My config
set tags=./tags
cs add ./cscope.out

" --- Mappings ---
"  -- Spell Checker --
map <F2> :set spell spelllang=en_us,ru_ru

" --- Configurations ---
" -- Latex live previewer --
let g:livepreview_previewer = 'evince'         " Set app for preview

" --- YouCompleteMe ---
let g:ycm_autoclose_preview_window_after_completion = 1

" -- Color scheme -- 
set t_Co=256                                    " This is may or may not needed
set background=dark
colorscheme PaperColor

" -- netrw -- 
"let g:netrw_banner=0
"let g:netrw_liststyle=3
"let g:netrw_browse_split=3

nnoremap <leader>n :NERDTreeFocus<CR>
nnoremap <C-n> :NERDTree<CR>
nnoremap <C-t> :NERDTreeToggle<CR>
nnoremap <C-f> :NERDTreeFind<CR>
let g:NERDTreeNodeDelimiter = "\u00a0"

" -- Python --
set fileformat=unix

" -----------------------------------------------------------------------------
"  GENERAL SETTINGS FOR EVERYONE
"  ----------------------------------------------------------------------------

set keymap=russian-jcukenwin                            " Set keyboard layout
set iminsert=0
set imsearch=-1

filetype plugin indent on
set autoindent
set nomodeline                                  " Disable modeline vulnerability

set encoding=utf8

set expandtab
set tabstop=4
set softtabstop=4
set shiftwidth=4

set backspace =indent,eol,start
set hidden
set laststatus =2

set number
set wrap

set ruler
set colorcolumn=80
set textwidth=80

set incsearch
set showmatch
set hlsearch
set ignorecase
set smartcase

"syntax on

"set noswapfile
