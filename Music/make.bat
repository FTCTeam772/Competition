@echo off
for %%f in (Files\*.mus) do (
  Compiler\win32\MusicCompiler.exe %%f NXT\%%~nf.nms
)
