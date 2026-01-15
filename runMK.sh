#!/bin/bash

echo "****Results MK*****" > resMK.dat

for K in 2 4 8 16; do 
    lK=$(echo "l($K)/l(2)" | bc -l)
    lK=${lK%.*}   # truncate to integer

    for lN in {16..28}; do
        for i in {1..4}; do
            if (( lN % lK == 0 )); then
                ./build/InverseMK "$lN" "$K" >> resMK.dat
                echo "run $i of logN = $lN  K = $K complete"
            fi
        done
    done
done
