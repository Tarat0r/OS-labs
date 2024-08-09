#!/usr/bin/bash
while true
do
 echo "$(ps -e | wc -l)" >> bomb.log
done
