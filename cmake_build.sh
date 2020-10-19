#!/bin/bash

if [ ! -d build]; then
mkdir build
fi

cd build
cmake -G  "Unix Makefiles" ../src
cmake -build . --config Release --target CliWidget
