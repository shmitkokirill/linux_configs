set runtimepath^=~/.vim runtimepath+=~/.vim/after
let &packpath = &runtimepath
source ~/.vimrc

hi Normal guifg=#737373 guibg=#000000
hi LineNr guifg=#737373 guibg=#000000
hi StatusLine guifg=#737373 guibg=#000000
hi ColorColumn guifg=#737373
hi TabLineFill guibg=#000000
hi TabLine guibg=#000000
hi TabLineSel guibg=#a3a3a3

lua require('cscope_maps').setup()
map fS :Cscope find s <c-r>=expand("<cword>")<cr><cr>
map fT :Cscope find t <c-r>=expand("<cword>")<cr><cr>
map fG :Cscope find g <c-r>=expand("<cword>")<cr><cr>

let g:NERDTreeWinSize=60
