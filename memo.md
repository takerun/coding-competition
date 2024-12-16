floor関数とceil関数の互換性
    ceil(x) = - floor(-x)
    floor(x) = - ceil(-x)
2点(x_1, y_1), (x_2, y_2)を通る直線の方程式
    (x_2 - x_1) * (y - y_1) = (y_2 - y_1) * (x - x_1)
外積から角度を求める
    https://atcoder.jp/contests/abc266/editorial/4659
ユークリッドの互除法の証明
    https://goukaku-suppli.com/archives/39934
写像12相
    https://qiita.com/drken/items/f2ea4b58b0d21621bd51
    重複組合せの場合の数
        「n種類のものから重複を許してr個選ぶ方法」と「r個の◯とn−1個の仕切りを一列に並べる方法」は1対1に対応する。
        そのような場合の数は (n-1+r)Cr となる。
連続する3つの整数の掛け算は3の倍数(n-1)*n*(n+1)=n^3-n
平方完成
    https://teno-hira.com/media/?p=612
Atcoderガイド
    数値型: https://atcoder.jp/contests/apg4b/tasks/APG4b_y
    pair/tuple: https://atcoder.jp/contests/apg4b/tasks/APG4b_z
    map/queue/priority_queue: https://atcoder.jp/contests/apg4b/tasks/APG4b_aa
next_permutationは重複する値をスキップするので、112は112,121,211の3(3!/2!)パターンしか列挙しない。
lower_boundとupper_boundは、[1,2,3,3,3,3,4,5]では、lower_boundは[2,3]の間を、upper_boundは[3,4]の間を見つける。
グラフ問題の解き方
    DFS https://qiita.com/drken/items/a803d4fc4a727e02f7ba
    BFS https://qiita.com/drken/items/996d80bcae64649a6580
標準ライブラリデータ
    https://qiita.com/gnbrganchan/items/616f3701b1169e834565
Atcoder問題のテストデータ
    https://atcoder.jp/posts/20