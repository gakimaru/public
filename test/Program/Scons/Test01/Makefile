# 同フォルダの SConstruct と同じ内容を Makefile で記述したもの
#
# ※Makefile はシェルコマンド依存が強いこともあり、Unix系環境用に作成されたMakefileはWindows環境ではまず動かない。
#   Sconsでは、Pythonのコマンドを使って記述している限りなら、互換性を保つことができる。（パスの記述に関する問題は残る）

all: out01and02.txt

out01.txt:
	ECHO This is $@ > $@

out02.txt:
	ECHO This is $@ > $@

out01and02.txt: out01.txt out02.txt
	TYPE $+ > $@
