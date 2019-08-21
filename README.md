# First-library
My first library

三角形に特化した全く役に立たないライブラリ

namespace brahman<br>

三角形汎用ヘッダ<br>
General purpose Triangle header<br>

## 注意!!
元々libraryとtestフォルダに分けてファイルを管理していましたが、ビルドシステムを整備するのがめんどくさいので、全部外に出しておきます。

I don't use build system like cmake, because it is tired.
I scatter my files.

## Initialization
brahman::Triangle<typename> class-name(side-length, side-length, side-length);<br>

## member function
GetXX():return side length<br>

GetArea():return Area<br>

GetShape():return Shape(string)<br>

PrintCondition():Invoke all GetXX(), than call GetArea() and GetShape()<br>

## だめなところ
機能が足りてない<br>
なんとなく、なんかダメそう<br>

## なやみどころ
クラス内のメンバ変数と一時変数の見分けを付けるか否か<br>
辺ABをconstにするか否かを決めるために、辺の長さを変えたりするSetAB()を作ったりするかどうか<br>
仕様を決めてないせいで、constにしていない変数や関数が多い<br>

## 解決したこと
三角形の面積を求めるときにcastが必要か否か<br>
A.必要