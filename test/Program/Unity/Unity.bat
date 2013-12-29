@ECHO OFF

rem ユーザー名が日本語だと Unity が起動できない。
rem その対策として、環境変数 TEMP, TMP を別のパスに変えてからUnityを起動する。
rem このバッチのショートカットを作ってコマンドプロンプトをアイコン化して起動すると良い。

SET TEMP=D:\Temp
SET TMP=D:\Temp

SET UNITY_DIR=D:\Program Files (x86)\Unity\Editor

CD /D "%UNITY_DIR%"

"%UNITY_DIR%\Unity.exe" -force-d3d11
