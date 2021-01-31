#!/bin/sh
#
# atm.sh - 2つのプログラムのためのラッパ
#

while true
do
    do_a_transaction
    if play_again
    then
        continue
    fi
    break
done
