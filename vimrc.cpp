if v:lang =~ "utf8$" || v:lang =~ "UTF-8$"
   set fileencodings=ucs-bom,utf-8,latin1
endif

set nocompatible	" Use Vim defaults (much better!)
set bs=indent,eol,start		" allow backspacing over everything in insert mode
"set ai			" always set autoindenting on
"set backup		" keep a backup file
set viminfo='20,\"50	" read/write a .viminfo file, don't store more
			" than 50 lines of registers
set history=50		" keep 50 lines of command line history
set ruler		" show the cursor position all the time

" Only do this part when compiled with support for autocommands
if has("autocmd")
  augroup redhat
  autocmd!
  " In text files, always limit the width of text to 78 characters
  " autocmd BufRead *.txt set tw=78
  " When editing a file, always jump to the last cursor position
  autocmd BufReadPost *
  \ if line("'\"") > 0 && line ("'\"") <= line("$") |
  \   exe "normal! g'\"" |
  \ endif
  " don't write swapfile on most commonly used directories for NFS mounts or USB sticks
  autocmd BufNewFile,BufReadPre /media/*,/run/media/*,/mnt/* set directory=~/tmp,/var/tmp,/tmp
  " start with spec file template
  autocmd BufNewFile *.spec 0r /usr/share/vim/vimfiles/template.spec
  augroup END
endif

if has("cscope") && filereadable("/usr/bin/cscope")
   set csprg=/usr/bin/cscope
   set csto=0
   set cst
   set nocsverb
   " add any database in current directory
   if filereadable("cscope.out")
      cs add $PWD/cscope.out
   " else add database pointed to by environment
   elseif $CSCOPE_DB != ""
      cs add $CSCOPE_DB
   endif
   set csverb
endif

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  syntax on
  set hlsearch
endif

filetype plugin on

if &term=="xterm"
     set t_Co=8
     set t_Sb=[4%dm
     set t_Sf=[3%dm
endif

" Don't wake up system with blinking cursor:
" http://www.linuxpowertop.org/known.php
let &guicursor = &guicursor . ",a:blinkon0"

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
