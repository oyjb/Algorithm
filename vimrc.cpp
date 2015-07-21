syntax enable
set background=dark
colorscheme solarized
set guifont=dejavu\MONACO\ 12


set nu
set showmode
set autoindent
set showmatch
set tabstop=4

set mouse=a
set selection=exclusive
set selectmode=mouse,key

au InsertLeave *.c write
au InsertLeave *.cpp write
au InsertLeave *.txt write
au InsertLeave * write

set cursorline
set fileencodings=utf-8,gb2312,gbk,gb18030,big5
set encoding=euc-cn
set fenc=utf-8
set enc=utf-8
set ambiwidth=double

let g:clang_complete_copen=1
let g:clang_close_preview=1
let g:clang_user_options='-std=c++11'
let g:neocomplcache_enable_at_startup = 1 
set completeopt=longest

map <F4> ms:call AddAuthor()<cr>'s
function AddAuthor()
        let 
        while n < 5
                let line = getline(n)
                if line =~'^\s*\*\s*\S*Last\s*modified\s*:\s*\S*.*$'
                        call UpdateTitle()
                        return
                endif
                let n = n + 1
        endwhile
        call AddTitle()
endfunction

function UpdateTitle()
        normal m'
        execute '/* Last modified\s*:/s@:.*$@\=strftime(": %Y-%m-%d %H:%M")@'
        normal "
        normal mk
        execute '/* Filename\s*:/s@:.*$@\=": ".expand("%:t")@'
        execute "noh"
        normal 'k
        echohl WarningMsg | echo "Successful in updating the copy right." | echohl None
endfunction
function AddTitle()
        call append(0,"/**********************************************************")
        call append(1," * Author        : oyjb")
        call append(2," * Email         : jbouyang@126.com")
        call append(3," * Last modified : ".strftime("%Y-%m-%d %H:%M"))
        call append(4," * Filename      : ".expand("%:t"))
        call append(5," * Description   : ")
        call append(6," * *******************************************************/")
        echohl WarningMsg | echo "Successful in adding the copyright." | echohl None
endfunction
