#!/usr/bin/bash

#pvcreate /dev/sdb1
#vgcreate vgusb /dev/sdb1
#lvcreate -L 3.8G -n lvusb vgusb
#mkfs.ext4 /dev/vgusb/lvusb
#mount /dev/vgusb/lvusb /mnt1

time dd  if=/dev/urandom of=/mnt1/1.txt bs=2048
echo  ">====="
rm /mnt1/*
sleep 1
test () {
for j in `seq 1 1 40`
do
 for m in `seq 1 1 1000`
 do
  echo zdr > /mnt1/qq$m.txt
 done
sleep 1
done
 }
time test
sleep 1
rm /mnt1/*
umount /dev/vgusb/lvusb

