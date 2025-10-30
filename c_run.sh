#! /bin/bash

#pwd = ${workspaceFolder}

cmake --build build/ --target client
./build/bin/client