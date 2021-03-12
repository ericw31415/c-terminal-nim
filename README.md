# C Terminal Nim
C Terminal Nim has a self-explanatory name: it is a game of Nim that you can play in your terminal.
There are two different gamemodes: local two-player, and human versus computer.

## Instructions
### Downloading
Navigate to the releases page and download the appropriate binary for your system (`nim` for Linux and `nim.exe` for Windows).

### Building from source
Download the source code and navigate to the appropriate directory.

```sh
git clone https://github.com/ericw31415/c-terminal-nim.git
cd c-terminal-nim
```

Then, generate the buildsystem and build the executable.

```sh
cmake -S . -B build -G "Ninja Multi-Config"
cmake --build build --config Release
```

The executable file will be built to the `bin/Release` subdirectory.
