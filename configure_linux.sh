#!/bin/sh

#Get disk image from here, rename to root_fs
#https://fs.devloop.org.uk/

cd linux
make defconfig ARCH=um
make menuconfig ARCH=um
make ARCH=um -j 32
