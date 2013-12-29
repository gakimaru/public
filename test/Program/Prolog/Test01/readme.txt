参考：（下記サイトのサンプルをそのままテスト）
http://yohshiy.blog.fc2.com/blog-entry-225.html

操作手順：
1) sillogism.prl をダブルクリックで実行し、記述されている知識ベースを読み込ませると共に、Prologのコマンドプロンプトを起動。

2) プロンプト上で下記の質問を実行（サンプルそのまま）
    1 ?- die(socrates). % ソクラテスは死ぬ ?
    true.
    
    2 ?- die(What). % 何(What)が死ぬ ?
    What = socrates ;
    What = plato ;
    What = aristotle.

以上
