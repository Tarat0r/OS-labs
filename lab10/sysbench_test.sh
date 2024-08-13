#!/usr/bin/bash

echo ">=== CPU 1 thread ===" 
for i in 1 2 3 4 5
do
sysbench --test=cpu run --time=180
done
sleep 5
echo ">=== CPU 4 threads ==="
for i in 1 2 3 4 5
do
sysbench --test=cpu run --time=180 --threads=4
done
sleep 5
echo ">=== Memory ===" 
for i in 1 2 3 4 5
do
sysbench --test=memory run --time=180
done
sleep 5
echo ">=== fileio ==="
sysbench --test=fileio --file-total-size=56G prepare
for i in 1 2 3 4 5
do
sysbench --test=fileio --file-total-size=56G --file-test-mode=rndrw --max-time=300 --max-requests=0 run
done
sysbench --test=fileio —file-total-size=56G cleanup	