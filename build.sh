#!/bin/sh

echo Setting environment variables...
export DEVKITPRO=/opt/devkitpro
export DEVKITARM="${DEVKITPRO}/devkitARM"
export LIBGBA="${DEVKITPRO}/libgba"
echo Done!

echo Building the binary
make $1
mv solarius.gba ezkernelnew.bin
echo Done!