# Assignment 1

### - Hayden Coffey

## Summary

I made my modifications ontop of the Linux 5.19 kernel.
I've included a submodule in this repo pointing to the
modified kernel.

As far as I can tell, with the 5.19 version of Linux,
the process for adding a systemcall to UML is the same
as X86. Modifying `syscall_64.tbl` in `arch/x86` appears to generate
a declaration for the syscall in

`arch/x86/include/generated/uapi/asm/unistd_64.h`

which appears to be included into the object files
of the `arch/um` build. In this case, I've called
the syscall `ext2fcount` and in `unistd_64.h` we get
the following generation:

`#define __NR_ext2fcount 451`

At the moment, trying to call the syscall by using `ext2fcount()`
fails, but if the number is used `syscall(451)` the call works
as expected.

## Directory Files

* `build.sh` : Builds the kernel with `make`.
* `configure_linux.sh` : Runs `make` config setup commands.
* `log_build.txt` : Output log from compiling Linux.
* `run_linux.sh` : Runs linux in UM.
* `test_program.c` : Program that calls `fsync` and the custom syscall.
* `modfiles` : Directory with modified files from Linux copied in.
* `Linux` : Submodule pointing to modified kernel.

I have not included the disk images to save space,
but I can add these if needed.

## Changed Kernel Files

I've copied the modified files into the `modfiles` directory.

Modified files and their paths:
```
include/linux/syscalls.h
arch/x86/entry/syscalls/syscall_64.tbl
fs/ext2/file.c
```

## Sample Output

Running sample program on `ubda` which is using an `ext3` FS:
```
localhost ß # ./a.out 
	Counter is : 0
	Calling fsync once...
	Counter is : 0
	Calling fsync three times...
	Counter is : 0
```

Running sample progam on `ubdb` (`ext2`):
```
localhost mnt # ./a.out 
	Counter is : 0
	Calling fsync once...
	Counter is : 1
	Calling fsync three times...
	Counter is : 4
```