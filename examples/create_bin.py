# create_bin.py
# This script creates a .bin file with some example byte values
import os

# Example bytecode: 0xB8 0x0C 0x00 0x00 0x00  (like "mov eax, 12")
bytecode = bytes([0xB8, 0x0C, 0x00, 0x00, 0x00, 0x83, 0xC0, 0x01, 0xC3])
bytecode += bytes([0x90] * 10)  # Append 10 NOPs
bytecode += "HEXY THE SIMPLE HEX DUMPER".encode('utf-8')  # Append ASCII string

# Get the directory of this script
script_dir = os.path.dirname(os.path.abspath(__file__))

# Construct full path for the output file relative to the script
output_file = os.path.join(script_dir, "example.bin")

# Write bytes to the file
with open(output_file, "wb") as f:
    f.write(bytecode)

print(f"{output_file} created with {len(bytecode)} bytes")
