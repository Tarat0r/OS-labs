#!/usr/bin/bash

for i in 1 2 3
do
  touch boost_log$i.txt
  echo "DEFAULT" >> 800_log$i.txt
  ./linpack >> 800_log$i.txt
  echo "" >> 800_log$i.txt
  sleep 10
  echo "NICE 19" >> 800_log$i.txt
  sudo nice -n 19 ./linpack >> 800_log$i.txt
  echo "" >> 800_log$i.txt
  sleep 10
  echo "NICE -20" >> 800_log$i.txt
  sudo nice -n -20 ./linpack >> 800_log$i.txt
  echo "" >> 800_log$i.txt
  sleep 10
done
