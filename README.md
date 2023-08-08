# Timer

Currently there is no installation method in place.<br>
### Note
This has only been tested for Linux based operating systems.

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
