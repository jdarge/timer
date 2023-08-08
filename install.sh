#!/bin/bash

# Generate Binary Executable
chmod +x run.sh 
./run.sh 

# Detect the user's shell
SHELL_CONFIG_FILE=""
if [[ -n "$BASH_VERSION" ]]; then
    SHELL_CONFIG_FILE=~/.bashrc
elif [[ -n "$ZSH_VERSION" ]]; then
    SHELL_CONFIG_FILE=~/.zshrc
else
    echo "Unsupported shell. Please add /usr/local/bin to your PATH manually."
    exit 1
fi

# Check if /usr/local/bin is in PATH
if [[ ":$PATH:" != *":/usr/local/bin:"* ]]; then
    echo "Adding /usr/local/bin to PATH"
    echo 'export PATH=$PATH:/usr/local/bin' >> "$SHELL_CONFIG_FILE"
    source "$SHELL_CONFIG_FILE"
fi

# Move timer executable
sudo cp build/bin/timer /usr/local/bin/timer

# Move sound files
sudo mkdir -p /usr/local/share/timer/
sudo cp -r sound/ /usr/local/share/timer/
