# これは何？
gstreamer を簡単な element からつくろうという目論見です。
元ネタをこつこつ入力して(うそコピペどん!)動かしたところ動きませんでした。
恐らく gstreamer のバージョンが変わったためでしょう。
詳しい原因はわかりませんでしたが、回避方法は見つかりました。
GST_PLUING_DEFINE の第3引数に **gsttext** という名称を使っていた為でした。
どうやら gst で始まるものを使うとうまく動かないようです。

gsTtext ならだいじょうぶ。

xgsttext ならだいじょうぶ。

## これは例のやつでは？
古くは eCos でテーブルを作るときに使っていた技法を使っていると
思われます。gcc の attribuite を使います。
もっと古くは gcc/g++ (いまでも？) のアセンブラで使ってた技法ですね（たぶん）。

# どうすれば？
step0 から順々に src の下のソースを見ながら build 実行してみてください。
build には meson と ninja が必要です。

## gst version 
> gst-inspect-1.0 --version
    gst-inspect-1.0 version 1.14.5
    GStreamer 1.14.5
    https://launchpad.net/distros/ubuntu/+source/gstreamer1.0

# 元ネタは？
Hello Library World からのパクリです。すいません。LGPL とのことなので
勝手に引用してます。
http://hellolibraryworld.blogspot.com/2016/12/gstreamer-2-identity-textnoop-element.html

