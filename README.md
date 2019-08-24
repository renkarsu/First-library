# First-library
My first C++17 library

三角形に特化した全く役に立たないライブラリ<br>
This is not useful library for people.<br>

三角形汎用ヘッダ<br>
General purpose Triangle header<br>

namespace brahman<br>

## Caution!!
元々libraryとtestフォルダに分けてファイルを管理していましたが、ビルドシステムを整備するのがめんどくさいので、全部外に出しておきます。<br>
<br>
I don't use build system like Cmake.<br>
Is it necessary?<br>
I scatter my files.

## 今後の予定
* 非メンバ関数を用意する<br>
* openSiv3Dを導入して三角形を描画する<br>
* 三角形の辺を伸ばしたり、三角形を拡大縮小できたりするようにする<br>

## Future
* To prepare non-member function.<br>
* Introduce openSiv3D, and then draw a triangle.<br>
* extend side or scales a triangle.<br>

## Initialization
brahman::Triangle< typename > class-name(side-length, side-length, side-length);

## member function
GetXX():return side length<br>

GetArea():return Area<br>

GetShape():return Shape(string)<br>

PrintCondition():Invoke all GetXX(), than call GetArea() and GetShape()

## だめなところ
機能が足りてない<br>
なんとなく、なんかダメそう

## なやみどころ
クラス内のメンバ変数と一時変数の見分けを付けるか否か<br>
辺ABをconstにするか否かを決めるために、辺の長さを変えたりするSetAB()を作ったりするかどうか<br>

## 解決したこと
三角形の面積を求めるときにcastが必要か否か<br>
A.必要<br>
* To overload operator<< in enum class TriangleShape.<br>
A.enum classに実装しなくてよかった<br>
仕様を決めてないせいで、constにしていない変数や関数が多い<br>
A.いなむ先生とtimelerさんに多大な感謝<br>