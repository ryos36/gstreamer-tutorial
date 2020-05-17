# meson でプリプロセッサーの値を得る
もしかしてもっとスマートな方法があるかもしれないが、
meson が作った build/compile_commands.json をコピーして command を抜き出す。

        "command": "ccache cc -Itextnoop@sha -I. -I.. -I/usr/include/gstreamer-1.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -fdiagnostics-color=always -pipe -D_FILE_OFFSET_BITS=64 -Wall -Winvalid-pch -g -fPIC -pthread -MD -MQ 'textnoop@sha/src_gsttextnoop.c.o' -MF 'textnoop@sha/src_gsttextnoop.c.o.d' -o 'textnoop@sha/src_gsttextnoop.c.o' -c ../src/gsttextnoop.c",

cc 以下を完全に抜き出して

-o を src_gsttextnoop.E に

-c を -E に変更

    cc -Itextnoop@sha -I. -I.. -I/usr/include/gstreamer-1.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -fdiagnostics-color=always -pipe -D_FILE_OFFSET_BITS=64 -Wall -Winvalid-pch -g -fPIC -pthread -MD -MQ 'textnoop@sha/src_gsttextnoop.c.o' -MF 'textnoop@sha/src_gsttextnoop.c.o.d' -o 'src_gsttextnoop.E' -E ../src/gsttextnoop.c

実行すればプリプロセッサが出力してくれた中身を見ることが出来るよ。
