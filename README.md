# Timer
Demo video:
[![Demo video](https://img.youtube.com/vi/iHWzUJcnE0k/maxresdefault.jpg)](https://youtu.be/iHWzUJcnE0k)

## Files required to make this application
1. ao library
2. mpg123 library
<!---
#### Note:
If mpg123 is not a library that's currently supported by your OS, try this [branch](https://github.com/jdarge/timer/tree/indep).
### Arch installation:
--->
```console
# pacman -Sy libao mpg123 --needed
```
### Debian installation:
```console
# apt-get install libao-dev libmpg123-dev
```
### Fedora installation:
```console
# dnf install libao-devel mpg123-devel
```

## How to install timer application:
```console
$ chmod +x install.sh
# ./install.sh
```

## How to uninstall:
```console
$ chmod +x uninstall.sh
# ./uninstall.sh
```

## How to generate the binary file, for those who wish to avoid installation:
```console
$ chmod +x run.sh
$ ./run.sh
$ ./build/bin/timer --help
Line 31 of driver.c dictates where the audio comes from. If you do not wish to install this application, please change this string value to a more appropriate path.
```

## General flags for the application:
```console
    --help      Displays the help screen.\n"
-s, --second    Input second(s) before alarm rings.
-m, --minute    Input minute(s) before alarm rings.
-h, --hour      Input hour(s) before alarm rings.
-f, --format    For more specific timers.
                Format: hhmmss
                Example: -f 031530
                         will run for 03 hours, 15 minutes, 30 seconds
```

## Usage notes:
Once the alarm starts to go off, you can press any key to kill it; subsequently killing the program all together.

## Further notes:
This has only been tested for Linux based operating systems.<br>
This is still under development but it does function as intended, as far as I know.<br>

TODO: allow user to specify mp3 file for alarm noise
