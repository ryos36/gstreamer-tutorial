# STEP1: element に Pad を追加
Pad を追加すると launch することができます。
Pad の情報が出てきません。その上、まだこれでも何もできません。

## build
> meson build 
> ninja -C build

## 確認
> GST_PLUGIN_PATH=build gst-inspect-1.0 textnoop
or
> ( setenv GST_PLUGIN_PATH build ; gst-inspect-1.0 textnoop )

    Factory Details:
      Rank                     none (0)
      Long-name                Noop Element
      Klass                    Filter
      Description              Simple element like Identity
      Author                   Me

    Plugin Details:
      Name                     textnoop
      Description              Text Plugins for GStreamer
      Filename                 build/libtextnoop.so
      Version                  0.1.0
      License                  LGPL
      Source module            gst-plugins-text
      Binary package           GStreamer Text Package
      Origin URL               https://github.com/ryos36/gstreamer-tutorial

    GObject
     +----GInitiallyUnowned
           +----GstObject
                 +----GstElement
                       +----GstTextNoop

    Pad Templates:
      none

    Element has no clocking capabilities.
    Element has no URI handling capabilities.

    Pads:
      SRC: 'src'
        Pad Template: 'src'
      SINK: 'sink'
        Pad Template: 'sink'

    Element Properties:
      name                : The name of the object
                            flags: readable, writable
                            String. Default: "textnoop0"
      parent              : The parent of the object
                            flags: readable, writable
                            Object of type "GstObject"

## OK
> GST_PLUGIN_PATH=build gst-launch-1.0 -q fakesrc num-buffers=0 ! textnoop ! fakesink )
or
> ( setenv GST_PLUGIN_PATH build ; gst-launch-1.0 -q fakesrc num-buffers=0 ! textnoop ! fakesink )
