if !has('nvim')
"" Vundle config
"set nocompatible              " be iMproved, required
"filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
"Plugin 'ycm-core/YouCompleteMe'
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
endif

" My config
if !has('nvim')
    map fS :cs find s <c-r>=expand("<cword>")<cr><cr>
    map fT :cs find t <c-r>=expand("<cword>")<cr><cr>
    map fG :cs find g <c-r>=expand("<cword>")<cr><cr>
else
    map fS :Cs find s <c-r>=expand("<cword>")<cr><cr>
    map fT :Cs find t <c-r>=expand("<cword>")<cr><cr>
    map fG :Cs find g <c-r>=expand("<cword>")<cr><cr>
endif
" COC CONFIG--------------------------------------------------------------------
" May need for Vim (not Neovim) since coc.nvim calculates byte offset by count
" utf-8 byte sequence
set encoding=utf-8
" Some servers have issues with backup files, see #649
set nobackup
set nowritebackup

" Having longer updatetime (default is 4000 ms = 4s) leads to noticeable
" delays and poor user experience
set updatetime=400

" Always show the signcolumn, otherwise it would shift the text each time
" diagnostics appear/become resolved
set signcolumn=yes

" Use tab for trigger completion with characters ahead and navigate
" NOTE: There's always complete item selected by default, you may want to enable
" no select by `"suggest.noselect": true` in your configuration file
" NOTE: Use command ':verbose imap <tab>' to make sure tab is not mapped by
" other plugin before putting this into your config
inoremap <silent><expr> <TAB>
      \ coc#pum#visible() ? coc#pum#next(1) :
      \ CheckBackspace() ? "\<Tab>" :
      \ coc#refresh()
inoremap <expr><S-TAB> coc#pum#visible() ? coc#pum#prev(1) : "\<C-h>"

" Make <CR> to accept selected completion item or notify coc.nvim to format
" <C-g>u breaks current undo, please make your own choice
inoremap <silent><expr> <CR> coc#pum#visible() ? coc#pum#confirm()
                              \: "\<C-g>u\<CR>\<c-r>=coc#on_enter()\<CR>"

function! CheckBackspace() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction

" GoTo code navigation
nmap <silent> gD <Plug>(coc-definition)
nmap <silent> gY <Plug>(coc-type-definition)
nmap <silent> gI <Plug>(coc-implementation)
nmap <silent> gR <Plug>(coc-references)

"-------------------------------------------------------------------------------
set tags+=./tags
if !has("nvim")
    cs add ./cscope.out
endif
set exrc

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
highlight Normal ctermfg=256 ctermbg=black
highlight LineNr ctermfg=256 ctermbg=black

" -- netrw -- 
"let g:netrw_banner=0
"let g:netrw_liststyle=3
"let g:netrw_browse_split=3

"nnoremap <leader>n :NERDTreeFocus<CR>
"nnoremap <C-n> :NERDTree<CR>
nnoremap <C-l> :NERDTreeToggle<CR>
nnoremap <C-s> :NERDTreeFind<CR>
let g:NERDTreeNodeDelimiter = "\u00a0"

" vim-powered terminal in new tab
map <C-a> :tab term ++close<cr>
tmap <C-a> <c-w>:tab term ++close<cr>

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
highlight LineNr ctermfg=240
set wrap

set ruler
set colorcolumn=80
highlight ColorColumn ctermbg=235
set textwidth=80

set incsearch
set showmatch
set hlsearch
set ignorecase
set smartcase

"syntax on

set noswapfile
set mouse-=a
set mousehide
