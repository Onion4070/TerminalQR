@echo off
if exist "%~dp0\..\qrencode.dll" (
  echo already present
) 
else (
  copy "C:\vcpkg\installed\x64-windows\bin\qrencode.dll" "%~dp0\.." || (echo copy failed & exit /b 1)
)