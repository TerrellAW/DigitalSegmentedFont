<p align="center">
  <img width="405" height="33" alt="Digital Segmented Font" src="https://github.com/user-attachments/assets/113cf7f0-adec-4f8b-a07d-030526d7277f" />  
</p>

This font generator was created to bring my vision of a blocky digital font to life, for the sole purpose further customizing my Linux setup. You can see it in action [here](https://github.com/TerrellAW/blackglass-sddm-Qt5).

To compile and run this program it'll be necessary to have the [GNU Compiler Collection](https://gcc.gnu.org/) installed, or to reconfigure the Makefile to use your preferred compiler suite.

## Configuration
All GNU/Linux distributions include packages for GCC in their package managers.

Debian/Ubuntu:
``` bash
sudo apt-get install build-essential
```
Fedora:
``` bash
sudo dnf install @development-tools
```
Arch:
``` bash
pacman -Sy gcc
```

Its easy enough to find the install instructions for any other package managers online. During compilation GCC may ask you to install other dependencies. This program only uses the C standard library, so it shouldn't need much.

## Build
After cloning this repository you will need to build it using the `make` command.
All Unix systems come with `make`, whether its Linux, BSD, MacOS or WSL. To compile this program from a Unix terminal:
1. Enter the program directory, ie. `cd ./DigitalSegmentedFont`
2. Build with `make`

## Usage
Right now this generator only accepts one argument, or no arguments.

`-t` Runs in test mode, program will output glyphs and debug text

Default: Generates a bdf file in the same directory as the program.

The program will output instructions on what to do next with this file, however there is an easier way if you're using KDE Plasma. After using bdftopcf and gzip to convert the bdf font file into a pcf.gz, you can right-click it and push install and the system will do it for you. Try this out on other desktop environments, it may be possible!

After following these steps, the font should appear in your appearance settings and when you use the `fc-list` command.

### Notes
Bitmap fonts like this one are not always supported by default, on Debian based systems you will need to:
``` bash
sudo rm /etc/fonts/conf.d/70-no-bitmaps*
sudo fc-cache -fv
```
If that does not work, you should also do this:
``` bash
sudo ln -s /usr/share/fontconfig/conf.avail/70-yes-bitmaps.conf /etc/fonts/conf.d/
sudo fc-cache -fv
```
In modern Windows and MacOS there is no way to natively render bitmap fonts. You will have to use a third-party program like Gimp or open an XWindow session via WSL on Windows. If you'd like you can try converting this generator's output into a TTF or OTF for cross-platform compatibility. Such a contribution would be appreciated.
