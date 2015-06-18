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
hi CursorLine cterm=NONE ctermbg=darkred ctermfg=white
hi CursorColumn cterm=NONE ctermbg=darkred ctermfg=white


map <F4> ms:call AddAuthor()<cr>'s
function AddAuthor()
        let n=1
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
