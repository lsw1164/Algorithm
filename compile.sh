#!/bin/sh

path=$1

gcc $path -o ./result -lstdc++

./result.exe
rm ./result.exe
