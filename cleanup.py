import os

os.system("cls")
extensions_to_keep = ['.py', '.c', '.vscode', '.gitignore', ".git"]
for filename in os.listdir():
    if not any(filename.endswith(ext) for ext in extensions_to_keep):
        os.remove(filename)
        print(f"Removed: {filename}")