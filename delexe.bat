@echo off
title 删除可执行文件

@REM setlocal enabledelayedexpansion

for %%a in (.\) do (
    %%a:
    del *.exe /s /f /q
)
pause