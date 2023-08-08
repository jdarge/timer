# Timer

## Files required to make this application
1. ao library
2. mpg123 library
### Arch installation:
```console
# pacman -Sy libao lib32-mpg123
```
### Debian installation:
```console
# apt-get install libao-dev libmpg123-dev
```
### Fedora installation:
```console
# dnf install libao-devel mpg123-devel
```

## How to generate the binary file:
```console
$ chmod +x run.sh
$ ./run.sh
$ ./build/bin/timer --help
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
Once the alarm starts to go off, you cann press any key to kill it; subsequently killing the program all together.

## Further notes:
This has only been tested for Linux based operating systems.<br>
This is still under development but it does function as intended, as far as I know.<br>
Line 31 of driver.c dictates where the audio comes from. If you do not wish to install this application, please change this string value to a more appropriate path.

TODO: allow user to specify mp3 file for alarm noise
