builder\nasm.exe -f win64 src/asm/master.asm -o libraries/master.obj
g++ -m64 -shared -o libraries/main.dll src/main.cpp libraries/master.obj -static-libgcc -static-libstdc++