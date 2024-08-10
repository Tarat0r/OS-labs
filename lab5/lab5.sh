#!/usr/bin/bash

#===
#dd if=/dev/zero of=1.bin bs=4G count=1
for i in "fat -F 16" "fat -F 32" "vfat -F 32" "msdos -F 32" "ext2 -F" "ext3 -F" "ext4 -F" "ntfs -F" "bfs -F" "cramfs -F"
 do
echo "-----------------------------------------"
echo -n " === " $i " === "
echo ""
mkfs.$i  /dev/sdb1
mount /dev/sdb1 /mnt1

time dd  if=/dev/urandom of=/mnt1/1.txt bs=2500
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
umount /dev/sdb1
done
