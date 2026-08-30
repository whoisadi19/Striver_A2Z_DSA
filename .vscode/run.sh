#!/usr/bin/env bash

FILE="$1"
if [ -z "$FILE" ]; then
  echo "[ERROR] No file provided."
  exit 1
fi

DIRNAME=$(dirname "$FILE")
BASENAME=$(basename "$FILE" .cpp)
OUT="${DIRNAME}/${BASENAME}.out"
INPUT_FILE="${DIRNAME}/input.txt"
OUTPUT_FILE="${DIRNAME}/output.txt"

# 1. Ensure input.txt and output.txt exist in the active file's folder
touch "$INPUT_FILE"
touch "$OUTPUT_FILE"

# 2. Compile
g++ -O2 -std=c++17 -Wall -Wshadow "$FILE" -o "$OUT"
if [ $? -ne 0 ]; then
  echo "[ERROR] Compilation Failed!"
  exit 1
fi

# 3. Check if input.txt has content
if [ -s "$INPUT_FILE" ]; then
  # Run with input redirection, tee output to both console and output.txt
  "$OUT" < "$INPUT_FILE" | tee "$OUTPUT_FILE"
else
  # Run interactively
  "$OUT"
fi

EXIT_CODE=$?

# Clean up temporary compiled binary
rm -f "$OUT"

exit $EXIT_CODE
