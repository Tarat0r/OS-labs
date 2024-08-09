#!/usr/bin/bash

for i in 1 2 3
do
  touch boost_taskset_log$i.txt
  echo "DEFAULT" >> boost_taskset_log$i.txt
  sudo ./linpack >> boost_taskset_log$i.txt
  echo "" >> boost_taskset_log$i.txt
  sleep 10
  echo "NICE 19" >> boost_taskset_log$i.txt
  sudo nice -n 19 ./linpack >> boost_taskset_log$i.txt
  echo "" >> boost_taskset_log$i.txt
  sleep 10
  echo "NICE -20" >> boost_taskset_log$i.txt
  sudo nice -n -20 ./linpack >> boost_taskset_log$i.txt
  echo "" >> boost_taskset_log$i.txt
  sleep 10
done
