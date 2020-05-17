# STEP3: chain の追加と歓声
chain を追加したのでうまく動くようになりました。

## build
> meson build 
> ninja -C build

## OK
> GST_PLUGIN_PATH=build gst-launch-1.0 -q filesrc location=/etc/hosts ! textnoop ! filesink location=/tmp/hosts
or
> ( setenv GST_PLUGIN_PATH build; gst-launch-1.0 -q filesrc location=/etc/hosts ! textnoop ! filesink location=/tmp/hosts)
