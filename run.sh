nasm -f elf32 kernel.asm -o kernelasm.o
gcc -m32 -c kernel.c -o kernelc.o
ld -m elf_i386 -T linker.ld -o mykernel kernelasm.o kernelc.o
qemu-system-i386 -kernel mykernel
