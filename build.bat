builder\nasm.exe -f win64 src/asm/master.asm -o libraries/master.obj
builder\mingw64\bin\g++.exe -m64 -shared -o libraries/main.dll src/main.cpp libraries/master.obj -I include -lopengl32 -lglu32 -lgdi32 -static-libgcc -static-libstdc++

builder\Python312\python.exe loader.py