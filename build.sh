#!/bin/bash

set -euo pipefail

mkdir -p build && cd build

# Configure
cmake -DCMAKE_BUILD_TYPE=Coverage ..
# Build (for Make on Unix equivalent to `make -j $(nproc)`)
cmake --build . -- -j $(nproc)
# Test
./tests/transfer_function_tests