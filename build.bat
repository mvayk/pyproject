builder\nasm.exe -f win64 src/asm/master.asm -o libraries/master.obj
builder\mingw64\bin\gcc.exe -m64 -shared -o libraries/main.dll src/main.c libraries/master.obj -I src/include -L src/lib -lglfw3 -lopengl32 -lglu32 -lgdi32 -luser32 -lkernel32 -luuid -static-libgcc -static-libstdc++

builder\Python312\python.exe loader.py