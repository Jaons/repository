!#/bin/bash -xv

function get_c_file() {
    for file in `s $1`
    do 
        if [ -d $1"/"$file ] then
            get_c_file $1"/"$file
        else
            echo $1"/"$file  
        fi
    done
}

if test -d $1 then
    get_c_file $1
elif test -f $1 then 
    test -f 
