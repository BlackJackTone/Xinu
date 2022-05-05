make clean
make conf
make -j8
# make
qemu-system-i386 -nographic -serial mon:stdio -S -s -kernel xinu.elf
