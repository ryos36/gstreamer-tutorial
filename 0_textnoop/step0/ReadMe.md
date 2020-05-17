# STEP0: からっぽの element
からっぽ element をつくりましょう。これは何もできませんが、
gst-inspect-1.0 で内容を確認することが出来ます。

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

## error
> ( setenv GST_PLUGIN_PATH build ; gst-launch-1.0 -q fakesrc num-buffers=0 ! textnoop ! fakesink )

    WARNING: erroneous pipeline: could not link fakesrc0 to textnoop0

