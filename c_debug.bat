builder\nasm.exe -f win64 src/asm/master.asm -o libraries/master.obj
builder\mingw64\bin\g++.exe -std=c++20 -m64 -o debug/main.exe ^
  src/main.cpp libraries/master.obj src/include/glad.c ^
  -I src/include -L src/lib -lglfw3 -lopengl32 -lglu32 -lgdi32 -luser32 -lkernel32 -luuid ^
  -static-libgcc -static-libstdc++