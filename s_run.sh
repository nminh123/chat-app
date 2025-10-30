#! /bin/bash

#pwd = ${workspaceFolder}

cmake --build build/ --target server
./build/bin/server