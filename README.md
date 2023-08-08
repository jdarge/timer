# Timer

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
Currently there is no installation method in place.<br>
This has only been tested for Linux based operating systems.<br>
This is still under development but it does function as intended, as far as I know.<br><br>
Since this is not suited for installation, it is important to note that the binary expects there to be a file located in `sound/alarm.mp3` based on the root directory of the command. Thus, if you wish to move the binary else where, you must copy the sound folder.<br>
```console
Example:
/home/user/folder/timer
/home/user/folder/sound/alarm.mp3
```
