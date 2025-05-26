set GPP=.\builder\g++.exe
set OUTDIR=libraries
set OUTFILE=%OUTDIR%\main.dll

%GPP% -m64 -shared -o %OUTFILE% main.cpp -static-libgcc -static-libstdc++


