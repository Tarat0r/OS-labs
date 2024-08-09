#!/usr/bin/bash

while true
do
  free -m | grep Mem: | awk '{print $4}' >> log_free_mem.txt
  free -m | grep Swap: | awk '{print $4}' >> log_free_swap.txt
done
