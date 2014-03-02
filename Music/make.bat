@echo off
for %file in (Files\*.mus) do (
  Compiler\win32\MusicCompiler.exe %file NXT\%~nI.nms
)
