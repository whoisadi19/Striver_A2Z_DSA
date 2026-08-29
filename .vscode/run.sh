#!/usr/bin/env bash
set -e

FILE="$1"
if [ -z "$FILE" ]; then
  echo "[ERROR] No file provided."
  exit 1
fi

DIRNAME=$(dirname "$FILE")
BASENAME=$(basename "$FILE" .cpp)
OUT="${DIRNAME}/${BASENAME}.out"

# Compile
g++ -O2 -std=c++17 "$FILE" -o "$OUT"

# Run and cleanup
"$OUT"
rm -f "$OUT"
