@ECHO OFF

rem --- バッチファイルの存在するパス（ドライブ＆ディレクトリ）にカレントディレクトリを変更 ---
CD /D %~dp0

rem --- 現在のコードページを確認 ---
rem CHCP
rem --- コードページ指定：英語 ---
rem CHCP 437 >NUL
rem --- コードページ指定：UTF-8 ---
rem CHCP 65001 >NUL
rem --- コードページ指定：UTF-16(Unicode) ---
rem CHCP 1200 >NUL
rem --- コードページ指定：日本語（シフトJIS） ---
CHCP 932 >NUL

rem --- Python のパスを通す ---
SET PYTHON_DIR=D:\Python\27\x64
SET PATH=%PYTHON_DIR%\;%PYTHON_DIR%\Scripts\;%PATH%

rem --- MinGW(GCC)のパスを通す ---
SET MINGW_BIN_DIR=D:\MinGW\bin
SET PATH=%MINGW_BIN_DIR%;%PATH%

rem --- TEMP 調整 ---
rem ★環境変数 TEMP と TMP に日本語が入っているとSconsが動作しないので注意。
rem   ユーザー名に日本語が含まれているとそのような状態になる
rem   対策として、環境変数の内容を強引に書き換えておく
SET TEMP=%~dp0_temp
SET TMP=%~dp0_temp
IF NOT EXIST %TEMP% MKDIR %TEMP%

rem --- 開始 ---
ECHO.
ECHO ********** テスト開始 **********

rem --- Scons を実行 ---
CALL :RUN_CMD CALL scons.bat --tree=all --debug=explain

rem 【実行時オプション】
rem   -c オプションを付けると、ターゲットファイルを削除してくれる（make clean と同じ動作）
rem   --debug=explain オプションを付けると、ビルド実行時の理由が表示される。
rem   --tree=all オプションを付けると、ターゲットの依存関係が表示される。
rem   -Q オプションをつけると scons が静かになり主に gcc のメッセージが表示されます。
rem   install オプションをつけると make install の振る舞いをします。

rem --- C++プリプロセッサテスト ---
rem ※MinGWのGCCを使用する
rem   http://www3.u-toyama.ac.jp/kihara/pgm/gcc.html

rem SET SCRIPT_BASE=%~dp0
rem SET CCFLAGS=-x c++ -E -I "%SCRIPT_BASE%include00" -I "%SCRIPT_BASE%include01" -I "%SCRIPT_BASE%include02" -include "script_header_common01.h" -include "script_header_common02.h" -DXXX -DYYY
rem CALL :RUN_CMD g++.exe %CCFLAGS% -c %SCRIPT_BASE%src\test00.script -M -MF %SCRIPT_BASE%preprocess\test00.script.d -o %SCRIPT_BASE%preprocess\test00.script.i
rem CALL :RUN_CMD g++.exe %CCFLAGS% -c %SCRIPT_BASE%src\test01\test01.script -M -MF %SCRIPT_BASE%preprocess\test01\test01.script.d -o %SCRIPT_BASE%preprocess\test01\test01.script.i
rem CALL :RUN_CMD g++.exe %CCFLAGS% -c %SCRIPT_BASE%src\test02\test02a.script -M -MF %SCRIPT_BASE%preprocess\test02\test02a.script.d -o %SCRIPT_BASE%preprocess\test02\test02a.script.i
rem CALL :RUN_CMD g++.exe %CCFLAGS% -c %SCRIPT_BASE%src\test02\test02b.script -M -MF %SCRIPT_BASE%preprocess\test02\test02b.script.d -o %SCRIPT_BASE%preprocess\test02\test02b.script.i

rem 【g++.exe プリプロセッサ入出力に関係する主なオプション】 「★」は使用オプション
rem ★-c  ... ソース・ファイルのコンパイル、 または、 アセンブルを行いますが、
rem           リンクは行いません。 リンク処理段階は実行されません。 最終的な
rem           出力形態は、 個々のソース・ファイルに対応するオブジェクト・
rem           ファイルとなります。 デフォルトでは、 ソース・ファイルに対応する
rem           オブジェクト・ファイルの名前は、 ソース・ファイル名の
rem           接尾語`.c'、 `.i'、 `.s'等を`.o'に置き換えることによって作られます。
rem           接尾語が認識されない入力ファイルは、 コンパイルもアセンブルも必要と
rem           されないので、 無視されます。 
rem ★-o file 
rem       ... fileによって指定されるファイルを出力先とします。 これは、 生成
rem           される出力の種類に関係なく適用されます。 出力が、 実行可能
rem           ファイル、 オブジェクト・ファイル、 アセンブラ・ファイル、
rem           前処理済みのCコードのいずれであっても、 無関係に適用されます。
rem           出力ファイルは1つしか指定できないので、 複数の入力ファイルを
rem           コンパイルする際に`-o'を使うのは、 出力として実行可能ファイルを
rem           生成しようとしている場合を除けば、 意味のないことです。 `-o'が
rem           指定されないと、 デフォルトでは、 実行可能ファイルは`a.out'に、
rem           `source.suffix'に対応するオブジェクト・ファイルは`source.o'に、
rem           `source.suffix'に対応するアセンブラ・ファイルは`source.s'に、
rem           また、 すべての前処理済みのCのソースは標準出力に、 それぞれ
rem           出力されます。 
rem ★-x language
rem       ... 後続の入力ファイルの言語を、 （ファイル名の接尾語によって決まる
rem           デフォルトの言語をコンパイラに選択させるのではなく） languageに
rem           よって明示的に指定します。 このオプションは、 後続の入力ファイルの
rem           うち、 次の`-x'オプションよりも前に指定されたものすべてに対して
rem           適用されます。 languageに指定することのできる値は以下のとおりです。
rem               c  objective-c  c++
rem               c-header  cpp-output  c++-cpp-output
rem               assembler  assembler-with-cpp
rem ★-include file
rem       ... 通常の入力ファイルを処理する前に、 fileにより指定されるファイルを
rem           入力として処理します。 事実上、 fileの内容が最初にコンパイル
rem           されることになります。 コマンドライン上にある`-D'オプションと
rem           `-U'オプションは、 それらが指定された順序に関係なく、 
rem           常に`-include file'よりも前に処理されます。 すべての`-include'
rem           オプションと`-imacros'オプションは、 指定された順序に処理されます。 
rem   -imacros file
rem       ... 通常の入力ファイルを処理する前に、 fileにより指定されるファイルを
rem           入力として処理しますが、 その出力結果は破棄します。 fileから
rem           生成される出力は破棄されるので、 `-imacros file'の唯一の効果は、
rem           fileの中で定義されているマクロを、 主要な入力ファイルの中で
rem           使用可能にすることにあります。 コマンドライン上にある
rem           `-D'オプションと`-U'オプションは、 それらが指定された順序に
rem           関係なく、 常に`-imacros file'よりも前に処理されます。 すべての
rem           `-include'オプションと`-imacros'オプションは、 指定された順序に
rem           処理されます。
rem ★-Idir
rem       ... ヘッダ・ファイルを見つけるために探索するディレクトリの一覧の
rem           先頭にディレクトリdirを追加します。 これらのディレクトリは
rem           システム・ヘッダ・ファイルのディレクトリよりも前に探索されるので、
rem           このオプションを使って、 システム・ヘッダ・ファイルを無効にして、
rem           ユーザが独自に作成したヘッダ・ファイルで置き換えることができます。
rem           `-I'オプションを複数回使用すると、 指定されたディレクトリは左から
rem           右の順序で調べられます。 標準システム・ディレクトリはそのあとで
rem           調べられます。 
rem   -idirafter dir
rem       ... ディレクトリdirを第2のインクルード・パスに追加します。 第2の
rem           インクルード・パスに含まれるディレクトリは、 あるヘッダ・ファイルが
rem           メイン・インクルード・パス （`-I'オプションはここにディレクトリを
rem           追加します） に含まれるどのディレクトリの中にも見つからない場合に
rem           探索されます。
rem   -iprefix prefix
rem       ... 後続の`-iwithprefix'オプションのための接頭語としてprefixを指定
rem           します。
rem   -iwithprefix dir
rem       ... ディレクトリを第2のインクルード・パスに追加します。 ディレクトリの
rem           名前は、 事前に`-iprefix'により指定された接頭語prefixとdirを
rem           連結することによって作られます。 接頭語が事前に指定されていない
rem           場合には、 コンパイラがインストールされたディレクトリがデフォルトの
rem           接頭語として使われます。
rem   -iwithprefixbefore dir
rem       ... メイン・インクルード・パスにディレクトリを追加します。
rem           `-iwithprefix'の場合と同様、 ディレクトリの名前は、 prefixとdirを
rem           連結することによって作られます。
rem   -isystem dir
rem       ... ディレクトリを第2のインクルード・パスの先頭に追加し、 標準の
rem           システム・ディレクトリに適用されるのと同等の特殊な取り扱いを
rem           受けられるようにするために、 システム・ディレクトリとしてマーク
rem           します。
rem   -nostdinc
rem       ... ヘッダ・ファイルを探す際に、 標準のシステム・ディレクトリを
rem           探索しません。`-I'オプションにより指定されたディレクトリ （および、
rem           カレント・ディレクトリを探索することが適切である場合には、
rem           カレント・ディレクトリ） だけが探索されます。 `-I'に関する情報に
rem           ついては、 ディレクトリ探索のためのオプションを参照してください。
rem           `-nostdinc'と`-I-'を両方使用することにより、 インクルード・ファイルの
rem           探索パスを、 明示的に指定したディレクトリだけに限定することが
rem           できます。 
rem ★-E  ... Cプリプロセッサだけを実行します。 指定されたすべてのCソース・
rem           ファイルを前処理して、 その結果を標準出力、 もしくは、 指定された
rem           出力ファイルに出力します。 
rem   -C  ... プリプロセッサに対して、 コメントを破棄しないよう指示します。
rem           `-E'オプションとともに使います。
rem   -P  ... プリプロセッサに対して、 `#line'指示子を生成しないよう指示します。
rem           `-E'オプションとともに使います。
rem ★-M  ... プリプロセッサに対して、 makeコマンドで使うのに適した、 個々の
rem           オブジェクト・ファイルの依存関係を記述したルール情報を出力
rem           するよう指示します。 プリプロセッサは、 個々のソース・ファイルに
rem           対して、 そのソース・ファイルに対応するオブジェクト・ファイル名が
rem           依存関係のターゲットであり、 そのソース・ファイルが#includeにより
rem           取り込むすべてのヘッダ・ファイルが依存関係のソースであるような
rem           makeルールを出力します。(5) このルールは単一行の場合もありますが、
rem           長い場合には、 改行の直前に`\'を置くことにより複数行に継続する
rem           こともあります。 ルールの一覧は、 前処理されたCプログラムの中に
rem           ではなく、 標準出力に表示されます。 `-M'は暗黙のうちに`-E'を
rem           指定します。 makeルールを出力するよう指定する別の方法に、 
rem           環境変数DEPENDENCIES_OUTPUT （GCCに影響を与える環境変数を参照） を
rem           設定する方法があります。
rem   -MM ... `-M'と似ていますが、 出力の中には、 `#include "file"'により
rem           取り込まれたユーザ・ヘッダ・ファイルだけが記述されます。 
rem           `#include <file>'により取り込まれたシステム・ヘッダ・ファイルは
rem           省かれます。 -MD `-M'と似ていますが、 依存関係の情報は、 入力
rem           ファイル名の末尾の".c"を".d"に置き換えた名前のファイルに書き込まれ
rem           ます。 指定されたファイルはコンパイルされ、 それに加えて、 
rem           このような処理が行われます。 `-MD'は、 `-M'のように通常の
rem           コンパイル処理を禁止することをしません。 Machでは、 ユーティリティ
rem           mdを使うことにより、 複数の依存関係ファイルをマージして、
rem           `make'コマンドで使うのに適した単一の依存関係ファイルを作成する
rem           ことができます。
rem   -MMD... `-MD'と似ていますが、 ユーザ・ヘッダ・ファイルだけが対象となり、 
rem           システム・ヘッダ・ファイルが省かれる点が違います。 -MG 見つからない
rem           ヘッダ・ファイルは生成されるファイルとして取り扱い、 ソース・
rem           ファイルと同じディレクトリに存在するものと想定します。 `-MG'を
rem           指定する場合には、 `-M'か`-MM'のいずれかをあわせて指定しなければ
rem           なりません。 `-MD'や`-MMD'が指定されている場合には、 `-MG'は
rem           サポートされません。
rem ★-MF file
rem       ... When used with '-M' or '-MM', specifies a file to write the
rem           dependencies to. If no '-MF' switch is given the preprocessor
rem           sends the rules to the same place it would have sent preprocessed
rem           output. 
rem           When used with the driver options '-MD' or '-MMD', '-MF' overrides
rem           the default dependency output file. 
rem   -H  ... 通常の処理に加えて、 使用される個々のヘッダ・ファイルの名前を
rem           表示します。 
rem   -Aquestion(answer)
rem       ... `#if #question(answer)'のような前処理の条件式でテストされる場合に
rem           備えて、 questionに対する答えanswerを診断します。 `-A-'は、
rem           通常であればターゲット・マシンを記述する標準の診断を、 使用不可と
rem           します。
rem ★-Dmacro
rem       ... マクロmacroを文字列`1'として定義します。
rem   -Dmacro=defn
rem       ... マクロmacroをdefnとして定義します。 コマンドライン上にある
rem           すべての`-D'オプションは、 どの`-U'オプションよりも前に処理
rem           されます。
rem   -Umacro
rem       ... マクロmacroの定義を取り消します。 `-U'オプションは、 すべての
rem           `-D'オプションの評価が終わったあとで評価されますが、 どの
rem           `-include'オプションや`-imacros'オプションよりも前に評価されます。
rem   -dM ... プリプロセッサに対して、 前処理の終了時点において有効なマクロ定義の
rem           一覧だけを出力するよう指示します。 `-E'オプションとともに使います。
rem   -dD ... プリプロセッサに対して、 マクロの正しい出現順序で、 すべての
rem           マクロ定義を出力へ渡すよう指示します。
rem   -dN ... `-dD'と似ていますが、 マクロ引数とマクロ定義の内容が省かれる点が
rem           違います。 `#define name'という形式の情報だけが出力に含まれます。 

rem --- 終了 ---
ECHO.
CALL :PAUSE_MSG ********** テスト終了 **********
EXIT /B %RESULT%



rem ========== 標準サブルーチン ==========

rem --- 標準サブルーチン：コマンドラインを表示して実行 ---
:RUN_CMD
ECHO ^> %*
%*
EXIT /B %ERRORLEVEL%

rem --- 標準サブルーチン：メッセージ付きポーズ ---
:PAUSE_MSG
SET MSG=%*
IF "%MSG%" == "" SET MSG=続行するには何かキーを押してください．．．
ECHO.%MSG%
PAUSE >NUL
EXIT /B
