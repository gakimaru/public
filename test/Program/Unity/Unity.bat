@ECHO OFF

rem ���[�U�[�������{�ꂾ�� Unity ���N���ł��Ȃ��B
rem ���̑΍�Ƃ��āA���ϐ� TEMP, TMP ��ʂ̃p�X�ɕς��Ă���Unity���N������B
rem ���̃o�b�`�̃V���[�g�J�b�g������ăR�}���h�v�����v�g���A�C�R�������ċN������Ɨǂ��B

SET TEMP=D:\Temp
SET TMP=D:\Temp

SET UNITY_DIR=D:\Program Files (x86)\Unity\Editor

CD /D "%UNITY_DIR%"

"%UNITY_DIR%\Unity.exe" -force-d3d11
