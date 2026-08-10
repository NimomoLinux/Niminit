# NimomOS
A lightweight init made by a complete idiot at codding in C
. So uh that's basically it, it's mostly a backup for me
NimomOS is still in very early development, don't use it


Boot with:



qemu-system-x86_64 -kernel /home/nimarch/nimomos/build/linux-7.2-rc7/arch/x86_64/boot/bzImage -initrd ~/nimomos/nimomos.img -append "console=ttyS0" -nographic
