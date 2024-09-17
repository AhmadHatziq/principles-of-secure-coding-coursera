import os

# Path to the file to be read and modified
file_path = 'sa-1-testfile'

print("Granting read permissions on program startup...")
os.chmod(file_path, 0o444)

# Step 1: Open the file for reading but do not read from it yet
print("Opening the file for reading (but not reading yet).")
file = open(file_path, 'r')

# Step 2: Turn off read permissions for the file (you can do this in the program or pause it)
print("Turning off read permissions for the file...")
os.chmod(file_path, 0o200)  # Write-only permission for the owner

# Step 3: Try to read from the file now
print("\nAttempting to read the file after read permissions are removed:")
try:
    content = file.read()
    print(content)
except Exception as e:
    print(f"Error: {e}")
finally:
    file.close()

# Reset file permissions to be readable again for future runs of the program
print("Restoring read permissions for the file...")
os.chmod(file_path, 0o644)  # Read-write for owner, read for group and others

'''
    If system can read the whole file, that means the system does not enforce complete mediation. 
'''