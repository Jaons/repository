#!/bin/bash -xv

#功能： 获取一个目录下c文件的函数名格数
#分解：
#1、 获取目录下的c文件
#2、 获取一个c文件的函数名个数 
#3、 变量1获取的c文件，对每个文件执行2


#function get_file_from_path()
#{
#    return `ls $1`
#}
#function get_fun_num_from_C_file()
FILEPATTERN="*.c"
function get_fun_num_from_path()
{
    #if [ -f $1 ]
    #then
    #    awk -F"[ (]" '/[^ ](.*)$|[^ ](.*) $|[^ ](.*){$|[^ ](.*) {$/ {p=substr($0, index($0, "(")+1); print $p}'  $1/$file
    #fi
    for file in `ls -a $1`; do 
        if [ "$file" = "." -o "$file" = ".." ]
        then
            echo .dir or ..dir
        elif [ -d $1/$file ]
        then
            get_fun_num_from_path $1/$file
        elif [[ $file == *.c ]]
        then
            echo $file
            #awk -F"[ (]" '/)$/ {fn = $1;print fn}'  $1/$file
            #awk -F"[ (]" '/)$|) $|){$|) {$/ {p=substr($0, index($0, "(")+1); split(p, S); i=0; while($$i != S[1]) i++; print $$(i-1)}'  $1/$file
            #awk -F"[ (]" '/)$|) $|){$|) {$/ {print $0; p=substr($0, index($0, "(")+1); print p;} END{print NR}' $1/$file
            awk -F"[ (]" '/(\w+)\s+[\*,&]*\s*(\w+)\s*\(/ {print NR; print $1; print $2}'  $1/$file
        fi 
    done
}

get_fun_num_from_path $1


