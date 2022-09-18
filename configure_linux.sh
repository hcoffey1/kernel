#!/bin/sh
cd linux
make defconfig ARCH=um
make menuconfig ARCH=um
make ARCH=um -j 32
