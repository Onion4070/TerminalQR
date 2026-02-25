# Terminal QR
## 概要
QRコードをターミナルに出力します．
```cpp
const char* message 
```
に任意の文字列を入れることで任意の文字列を表示するQRコードを出力します．

## 動作環境
Windows, Linuxともに対応しています．Macは動作検証していませんが，恐らく動作可能です．

## 環境構築
このプログラムは[libqrencode](https://github.com/fukuchi/libqrencode/tree/master)を使用しています．

`libqrencode`をインストールしておいてください．Windows環境では`vcpkg`を利用して導入してください．またWindows環境では`qrencode.dll`を実行ファイルと同一ディレクトリに配置してください．[copy_dll.bat](https://github.com/Onion4070/TerminalQR/tree/main/scripts)を利用してカレントディレクトリにコピーしておきます．

### Windows
```sh
cd C:/
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat
vcpkg integrate install
vcpkg install libqrencode
```

### Linux, Mac
[libqrencode](https://github.com/fukuchi/libqrencode/tree/master)の手順に従って`libqrencode`をビルドしインストールします．

## ビルド
### Windows
`libqrencode`の`include`および`bin`のディレクトリを指定する必要があります．
```sh
g++ main.cpp -o TerminalQR -I C:/vcpkg/installed/x64-windows/include -LC:/vcpkg/installed/x64-windows/bin -lqrencode
```

### Linux, Mac
```sh
g++ main.cpp -o TerminalQR -lqrencode
```

## License
This program is licensed under the MIT License (see LICENSE).

### Third-party Libraries
- **libqrencode**: Licensed under LGPL v2.1 (see libqrencode_LICENSE)