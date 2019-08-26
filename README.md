# First-library
My first C++17 library

三角形汎用ヘッダーオンリーライブラリ<br>
General purpose Triangle header only library.<br>

# PURPOSE
簡単な実装で済むライブラリ作成を通して,C++やライブラリ作成,git系のお作法を学ぶため<br>
そして,今回学んだ知見をまとめたり,追いやすいsrcを心掛けたりすることで,<br>
他のライブラリ作成入門者の参考になれれば良いなと思います.<br>
<br>
I want to learn Best Practice about C++, making library and git.<br>
Moreover, I hope this helps people who is C++ beginner.<br>
<br>

# STRUCTURE
* hello.h: print hello<br>
* triangle.h: This can operate triangle<br>
* TriangleTest.cpp: test<br>
* LearnedList.md: put together things I learned<br>
* project.txt: memo<br>
<br>

# FEATURE(triangle.h)
* namespace brahman<br>
<br>
global function<br>
* sqrt(): template sqrt<br>
<br>
Instance<br>
* brahman::Triangle<T> obj(side-length, side-length, side-length)<br>
<br>
member function<br>
* Get??(): return side-length<br>
<br>
* GetArea(): return triangle area<br>
<br>
* GetShape(): return triangle-shape<br>
<br>
overload<br>
* <<: you can write```cout << obj``` <br>