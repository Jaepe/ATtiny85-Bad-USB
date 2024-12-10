import subprocess
import tempfile
import os

text = """This is a test payload to check if Rubber Ducky is working!
It is!"""

with tempfile.NamedTemporaryFile(delete=False, mode='w', suffix='.txt') as temp_file:
    temp_file.write(text)
    temp_file_path = temp_file.name  # Get the path of the temporary file

# Open the temporary file with Notepad
subprocess.run(['notepad.exe', temp_file_path])
