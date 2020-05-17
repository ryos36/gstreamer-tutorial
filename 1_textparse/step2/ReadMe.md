# STEP2:
textparser のひな形。"text/x-raw" を追加してエラーはなくなりました。
でもまだなにもしていません。

## build
> meson build 
> ninja -C build

## 確認
> GST_PLUGIN_PATH=build gst-inspect-1.0 textparse
or
> ( setenv GST_PLUGIN_PATH build ; gst-inspect-1.0 textparse )

    Factory Details:
      Rank                     none (0)
      Long-name                Text Parser element
      Klass                    Filter
      Description              Parse text stream 
      Author                   Yasushi SHOJI <yasushi.shoji@gmail.com

    Plugin Details:
      Name                     text
      Description              Text Plugins for GStreamer
      Filename                 build/libtext.so
      Version                  0.1.0
      License                  LGPL
      Source module            gst-plugins-text
      Binary package           GStreamer Text Package
      Origin URL               https://github/yashi/gst-plugins-text

    GObject
     +----GInitiallyUnowned
           +----GstObject
                 +----GstElement
                       +----GstBaseParse
                             +----GstTextParse

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
      SINK: 'sink'
        Pad Template: 'sink'
      SRC: 'src'
        Pad Template: 'src'

    Element Properties:
      name                : The name of the object
                            flags: readable, writable
                            String. Default: "textparse0"
      parent              : The parent of the object
                            flags: readable, writable
                            Object of type "GstObject"
      disable-passthrough : Force processing (disables passthrough)
                            flags: readable, writable
                            Boolean. Default: false

## error
> GST_PLUGIN_PATH=build gst-launch-1.0 -q filesrc location=/etc/hosts ! textparse ! filesink location=/tmp/hosts
or
> ( setenv GST_PLUGIN_PATH build; gst-launch-1.0 -q filesrc location=/etc/hosts ! textparse ! filesink location=/tmp/hosts)
Setting pipeline to PAUSED ...
Pipeline is PREROLLING ...
Pipeline is PREROLLED ...
Setting pipeline to PLAYING ...
New clock: GstSystemClock
Got EOS from element "pipeline0".
Execution ended after 0:00:00.000095248
Setting pipeline to PAUSED ...
Setting pipeline to READY ...
Setting pipeline to NULL ...
Freeing pipeline ...
