#!/bin/bash
make                      # Compile the kernel module
sudo insmod lab2.ko       # Insert the module
sudo dmesg | tail         # Verify insertion and check messages
sudo lsmod | grep lab2    # Ensure the module is loaded

echo "Press Enter to remove the module or Ctrl+C to exit..."
read -r                  # Wait for user input

sudo rmmod lab2           # Remove the module
sudo dmesg | tail         # Verify cleanup and check messages
sudo dmesg -C