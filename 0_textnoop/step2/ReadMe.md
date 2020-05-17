# STEP2: Pad 
Pad に情報を追加したので情報が出るようになりました。
その上、まだこれでも何もできません。
データを流そうとするとエラーになります。

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
      SINK template: 'sink'
        Availability: Always
        Capabilities:
          ANY
      
      SRC template: 'src'
        Availability: Always
        Capabilities:
          ANY

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

## error
> GST_PLUGIN_PATH=. gst-launch-1.0 -q fakesrc num-buffers=1 ! textnoop ! fakesink
or
 ( setenv GST_PLUGIN_PATH build ; gst-launch-1.0 -q fakesrc num-buffers=1 ! textnoop ! fakesink )

    (gst-launch-1.0:4934): GStreamer-CRITICAL **: 03:52:04.189: chain on pad textnoop0:sink but it has no chainfunction
    ERROR: from element /GstPipeline:pipeline0/GstFakeSrc:fakesrc0: Internal data stream error.
    Additional debug info:
    gstbasesrc.c(3055): gst_base_src_loop (): /GstPipeline:pipeline0/GstFakeSrc:fakesrc0:
    streaming stopped, reason not-supported (-6)
    ERROR: pipeline doesn't want to preroll.
