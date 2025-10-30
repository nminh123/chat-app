#! /bin/bash

#pwd = ${workspaceFolder}

cmake --build build/
./build/bin/client
./build/bin/server