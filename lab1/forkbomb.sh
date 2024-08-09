#!/usr/bin/bash

bomb(){
 echo "$(date +"%T.%N"),$(ps -e | wc -l)" >> bomb.log
 bomb|bomb &
 };
bomb
