# Aperture-OS
We want to create an os from scratch.
Inspired by this paper: https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf

### Goals: 
* A text based interface.
* Keyboard (and maybe joystick) input
* A basic filesystem (Data files, program files, etc.)
* The OS kernel!
* The ability to port to different system architectures.
* Software: 
    * BASIC compiler
    * Text editor / compiler for our own games engine
    * Small (text based) games
* Sound?

### So far: 
* Created an empty boot sector (bootsector.bin) which we can open in VirtualBox
* Created a boot sector that greets you with a nice "Hello World!" Welcome message. 
* Created a print_string function to print a string on screen through the boot_sect.img.
* Created a new bootsector that uses the 32bit Protected Mode

### Tools: 
* This paper: https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf
* QEmu: https://www.qemu.org/
* VirtualBox: https://www.virtualbox.org/
* HxD: https://mh-nexus.de/en/hxd/
* Make: https://www.gnu.org/software/make/
* GCC: https://gcc.gnu.org/
