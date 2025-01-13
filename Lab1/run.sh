#!/bin/bash
make                      # Compile the kernel module
sudo insmod lab1.ko       # Insert the module
sudo dmesg | tail         # Verify insertion and check messages
sudo lsmod | grep lab1    # Ensure the module is loaded
