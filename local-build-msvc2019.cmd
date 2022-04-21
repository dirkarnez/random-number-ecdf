REM run as Administrator
@echo off
cd /d %~dp0
set DOWNLOAD_DIR=%USERPROFILE%\Downloads
set DOWNLOAD_DIR_LINUX=%DOWNLOAD_DIR:\=/%
@REM %DOWNLOAD_DIR%\mingw64-win32; ^
@REM %DOWNLOAD_DIR%\mingw64-win32\bin; ^

SET PATH=%DOWNLOAD_DIR%\PortableGit\bin;%DOWNLOAD_DIR%\cmake-3.22.2-windows-x86_64\bin;

cmake -G "Visual Studio 16 2019" -A x64 ^
-DARMADILLO_ROOT="P:/armadillo-11.0.1.tar/armadillo-11.0.1" ^
-DBUILD_SHARED_LIBS=OFF ^
-DCMAKE_INSTALL_PREFIX="%~dp0build/armadillo-boilerplate" -B./build

cd build
cmake --build . --target ALL_BUILD --config Debug -- /nologo /verbosity:minimal /maxcpucount

pause

