# pico_test_vscode_debug
Raspberry Pi Pico example which can be debugged under VSCode using Picoprobe.
This document references package names of Arch Linux, on other OSs they will
be called differently and different commands might be needed to for installation...

You need two Raspberry Pi Pico boards: one will be used as debugger (Picoprobe) the
other will be the device which can be debugged.

# Creating Picoprobe debugger
Press BOOTSEL button then connect USB to the computer. A mass storage device
will appear, copy 'picoprobe.uf2' to this device. It will flash the firmware and
appear as CMSIS-DAP device:

```
$ lsusb -d 2e8a:
Bus 001 Device 049: ID 2e8a:000c Raspberry Pi Picoprobe CMSIS-DAP
```

# Install Raspberry Pi Pico SDK
On Arch Linux the package is called raspberry-pico-sdk-git which can be found in AUR.

```
$ yay raspberry-pico-sdk-git
```

# Install openocd-picoprobe
You need different version of OpenOCD which is adapted for Picoprobe.
On Arch Linux the package is called openocd-picoprobe which can be found in AUR.

```
$ yay openocd-picoprobe
```

# Opening in VSCode and debugging
After that you can open this folder in VSCode, but you need to install the following extensions:
C/C++
CMake
CMake Tools
Cortex-Debug

First you need to select kit, which is a small wrench icon on the bottom. Currently 'GCC 12.2.2 arm-none-eabi'
is selected on my system.
Then you should click on 'Build' which is next to kit selection button.
After that click on 'Run and Debug', a green play icon should appear and 'Pico Debug'.
Click on play icon, and debug!
