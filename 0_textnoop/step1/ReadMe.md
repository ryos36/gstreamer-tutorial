# STEP1: element に Pad を追加
Pad を追加すると launch することができます。
Pad の情報が出てきません。その上、まだこれでも何もできません。

## build
> meson . build 
> ninja -C build

## 確認
> gst-inspect-1.0 build/libtextnoop.so

    Plugin Details:
      Name                     textnoop
      Description              Text Plugins for GStreamer
      Filename                 build/libtextnoop.so
      Version                  0.1.0
      License                  LGPL
      Source module            gst-plugins-text
      Binary package           GStreamer Text Package
      Origin URL               https://github.com/ryos36/gstreamer-tutorial

      textnoop: Noop Element

      1 features:
      +-- 1 elements


    Plugin Details:
      Name                     textnoop
      Description              Text Plugins for GStreamer
      Filename                 build/libtextnoop.so
      Version                  0.1.0
      License                  LGPL
      Source module            gst-plugins-text
      Binary package           GStreamer Text Package
      Origin URL               https://github.com/ryos36/gstreamer-tutorial

      textnoop: Noop Element

      1 features:
      +-- 1 elements

## error
> GST_PLUGIN_PATH=build gst-launch-1.0 -q fakesrc num-buffers=0 ! textnoop ! fakesink )
or
> ( setenv GST_PLUGIN_PATH build ; gst-launch-1.0 -q fakesrc num-buffers=0 ! textnoop ! fakesink )

