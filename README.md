# Terminal QR
QRコードをターミナルに出力します.

このプログラムは[libqrencode](https://github.com/fukuchi/libqrencode/tree/master)を使用しています．
`libqrencode`のサンプルプログラムです．

プログラムの実行にあたり，`libqrencode`を導入しておいてください．Windows環境では`vcpkg`を利用して導入してください．

```sh
cd C:\
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat
vcpkg integrate install
vcpkg install libqrencode
```