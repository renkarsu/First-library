# 学んだことリスト

## なぜそうするのかシリーズ

* なぜメンバ関数にstaticをつけるのですか?<br>
A. テストがしやすいのと,非staticメンバ変数（主に状態）などを変更しないことを明示できるから,可読性も上がる.<br>
<br>
蛇足. 関数にもメモリが存在していて,メモリの節約になるから（多分）（それならGetXXもstaticにするべき？）<br>
<br>

* なぜsqrtはtemplateにしたの？<br>
A. template目的というより,constexprをつけたかったから.<br>
普通は標準ライブラリにあるものは自前で用意しない.<br>
<br>

* なんでCalculateArea()はprivate？<br>
privateなのは,ユーザが直接使う必要が無いから.<br>
<br>

*  CalculateArea()はユーザは使わないの?<br>
A. 使いそう(;'∀') そのうち,ユーザが面積を確認できるように面積計算関数をラップするかも...<br>
<br>

* なぜconstexprをコンストラクタにつけるのか<br>
A. コンパイル時にコンストラクタを計算できるなら計算した方が良いよね！<br>
コンストラクタもメンバ関数の一種<br>
A2. constexprで計算できるものは未定義動作を含まないことを保証できるのでテストになる<br>
<br>

e.g.<br>

```cpp

//constexpr変数なのに,コンストラクタがconstexprじゃなかったら,これはerror
constexpr brahman::Triangle<T> tri(3, 4, 5);

```
<br>

* なぜexplicitなコンストラクタにするのですか？<br>
A. 関数の仮引数として構造体を与えた時,意図しない挙動を防ぐため<br>
<br>
仮引数として構造体を与えるとき,<br>
func(ClassName obj)<br>
とする.<br>
これに実引数として<br>
func(i)をすると<br>
func(obj(i))<br>
を呼んだことになる<br>
これを防ぎたい時はexplicit<br>
<br>
あと,コピー初期化ができなくなる.<br>
<br>

* なぜコンストラクタの初期化子リストに全てのメンバ変数を書くのですか？<br>
A. よう分からんけど安定する！気にしたらアカン！C++は冒険や！（ネタです）<br>
<br>

* なぜ=defaultにするのですか？<br>
A. =defaultは明示的なデフォルト定義と呼ばれており,明示的に定義することで可読性を上げるため<br>
<br>

* なぜメンバ関数はconstexpr func() constにすることが推奨されていますか？<br>
A. constexprをつけることでコンパイル時に計算できるなら計算することを命令.<br>
加えて,constは関数の中でメンバ変数を変更しないことを明示する.<br>
constは「constexprは引数や返り値のconst性は保障しない」という性質のため,<br>
引数や返り値をconstにしたければ付ける.<br>
<br>
constはコンパイル時計算を保証しないが,副作用の禁止ができる<br>
constexpr関数は実行時にも計算できて,実行時の副作用が無いことは保証しない.<br>
↓融合<br>
コンパイル時は副作用がなく,コンパイル時か実行時に計算できる関数<br>
...と考えるが吉？<br>
<br>

* endlではなく,なんで'\n'?<br>
A. 改行を出力するためだけにわざわざバッファフラッシュをするのは処理の無駄なので<br>
appendix<br>
https://www.quora.com/When-do-you-use-std-endl-vs-n-in-C<br>
https://www.geeksforgeeks.org/endl-vs-n-in-cpp/<br>
<br>

* バッファフラッシュしたいのはいつ？つまり,いつendlを使えばいい？<br>
A. endlではbuffer-flushのtimingが指定されてるだけで,なくてもbufferが貯まればflushする<br>
あと,flushしないと画面とかに出力されないので,その辺りコントロールしたいときにflush<br>
よって,ストリームに出力を貯め込みたい時に'\n'使って,こまめに出力したいときはendl<br>
（ぶっちゃけbufferとかflushよく分かってないです.stdoutも雰囲気使ってる.区別はできてない.）<br>
<br>
appendix<br>
ここにあるC11ドラフトからの言及とかも参考になる.<br>
https://stackoverflow.com/questions/27910422/c-flushing-the-buffer<br>
https://www.quora.com/What-does-it-mean-to-flush-the-output-stream-in-C++<br>
<br>

* なんで演算子"<<"のオーバーロードはfriend<br>
A. friendが無いとクラス内の private メンバにアクセスすることができないから.<br>
クラスのメンバ関数で演算子をオーバーロードする場合,引数はひとつのみという制約がある.<br>
そのため,引数が二つ必要な"<<"演算子は困る.<br>
このため,クラス外部に関数を宣言し,定義することが考えられる.（メンバ関数の分離）<br>
しかし,これ以外にも方法があって,friend関数は非メンバ関数として関数を定義できるkeyword.<br>
<br>
"必ずグローバル関数にする必要がある."という流派もある.<br>
<br>

## 知識シリーズ

/*const編*/<br>

* 仮引数のconstには実引数に非constな変数を使用可能<br>

* 関数の引数がconst intのとき実引数をコピーした値は関数内で不変.実引数で与えた変数と同じ変数への参照を関数内でいじると変化.<br>
const intが参照やポインタだったら関数内では不変.<br>

* メンバ関数のconstはメンバ関数内でインスタンスが不変であることを示す.<br>

* const T func(){}は戻り値がconst<br>

* staticメンバ関数とnon-member関数(普通の関数)はT func() const {}と書けない<br>
(メンバ変数を変化させないのは自明だから?)<br>
<br>
/*constexpr編*/<br>

* constexpr関数はconstexpr T func(){}のこと<br>

* constexpr関数はコンパイル時評価か実行時評価をする．<br>

* コンパイル時評価にするには,全ての変数や関数がconst又はconstexprでなければならない.<br>

* constexprメンバ関数はコンパイル時評価か実行時評価する.<br>
<br>

* 以上を踏まえるとconstexpr const func(){}とも書ける<br>