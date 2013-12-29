参考：（下記サイトのサンプルをほぼそのままテスト）
http://d.hatena.ne.jp/kojimu/20110831/1314803922

実行手順：

1) SConstruct と Make.bat を用意。Makefile は比較用のサンプル。

  ※SConstruct 内では日本語が使えないので注意。
  
  ※Make.bat 内にて、Python のパスを通し、環境変数 TEMP と TMP の内容を調整している点に注意。

2) Make.bat を実行

3) out01.txt, out02.txt, out01and02.txt が出力される。

  ※ファイルの依存関係をチェックしているので、2回目の実行時には何も出力されない。
    また、out1.txt か out2.txt を手動で書き変えると、out01and02.txtだけが再出力されることが確認できる。

以上
