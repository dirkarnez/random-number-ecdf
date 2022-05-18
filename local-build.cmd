REM run as Administrator
@echo off
cd /d %~dp0
set DOWNLOAD_DIR=%USERPROFILE%\Downloads
set DOWNLOAD_DIR_LINUX=%DOWNLOAD_DIR:\=/%

SET PATH=^
%DOWNLOAD_DIR%\PortableGit\bin;^
%DOWNLOAD_DIR%\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0;^
%DOWNLOAD_DIR%\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\bin;^
%DOWNLOAD_DIR%\cmake-3.22.2-windows-x86_64\bin;

@REM cmake -G "Visual Studio 16 2019" -A x64 ^
@REM -DARMADILLO_ROOT="%DOWNLOAD_DIR%/armadillo-v11.1.1-msvc2019" ^
@REM -DBUILD_SHARED_LIBS=OFF ^
@REM -DCMAKE_INSTALL_PREFIX="%~dp0build/armadillo-boilerplate" -B./build

cmake -G"MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ^
-DARMADILLO_ROOT="%DOWNLOAD_DIR_LINUX%/armadillo-v11.1.1-mingw" ^
-DBUILD_SHARED_LIBS=OFF ^
-DCMAKE_INSTALL_PREFIX="%~dp0build/armadillo-boilerplate" -B./build &&^
cd build &&^
cmake --build . &&^
echo "Successful build"
pause


@REM cd build
@REM cmake --build . --target ALL_BUILD --config Debug -- /nologo /verbosity:minimal /maxcpucount
@REM pause


