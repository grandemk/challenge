#!/bin/bash

scriptPath=$(realpath $0)
scriptDir=$(dirname $scriptPath)
tmpDir=$(mktemp -d)
create_check=$tmpDir/create_check.c

trap 'clean' EXIT

function clean
{
    rm "$tmpDir" -r

    if [ -f $scriptDir/create_check ]
    then
        rm $scriptDir/create_check
    fi
}

function push_dir
{
    pushd $1 > /dev/null
}
function pop_dir
{
    popd > /dev/null
}

function create_check_fcn
{
    echo "[-] Creating check function"
    push_dir $scriptDir 
    make main > /dev/null
    r2 chall -i $scriptDir/get_check.r2 -q > $tmpDir/check_f.c
    pop_dir #$scriptDir
}

function create_obfuscator
{
    echo "[-] creating obfuscator"
    push_dir $scriptDir
    cat $tmpDir/check_f.c $scriptDir/create_check.c > $create_check
    gcc $create_check -o create_check > /dev/null
    pop_dir #$scriptDir
}

function obfuscate_check
{
    echo "[-] obfuscating check function"
    push_dir $scriptDir
    ./create_check > check2.c
    pop_dir #$scriptDir
}

function create_main2
{
	echo "[-] creating chall"
	python process_main.py
	make main2 > /dev/null
}

function main
{
    create_check_fcn
    create_obfuscator
    obfuscate_check
	create_main2
}

main "$@"
