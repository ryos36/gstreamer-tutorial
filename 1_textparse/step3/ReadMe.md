# STEP2:
textparser のひな形。中身を実装したので改行を認識しています。

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
      Author                   Yasushi SHOJI

    Plugin Details:
      Name                     text
      Description              Text Plugins for GStreamer
      Filename                 build/libtext.so
      Version                  0.1.0
      License                  LGPL
      Source module            gst-plugins-text
      Binary package           GStreamer Text Package
      Origin URL               https://github/ryos36/gstreamer-tutorial

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

    00000000 (0x7f5838007230): 31 32 37 2e 30 2e 30 2e 31 20 6c 6f 63 61 6c 68  127.0.0.1 localh
    00000010 (0x7f5838007240): 6f 73 74 0a                                      ost.            
    Pipeline is PREROLLED ...
    Setting pipeline to PLAYING ...
    New clock: GstSystemClock

    00000000 (0x7f583800a290): 31 32 37 2e 30 2e 31 2e 31 20 77 68 61 6c 65 0a  127.0.1.1 whale.

    00000000 (0x7f583800b1e0): 0a                                               .               

    00000000 (0x7f583800b480): 23 20 54 68 65 20 66 6f 6c 6c 6f 77 69 6e 67 20  # The following 
    00000010 (0x7f583800b490): 6c 69 6e 65 73 20 61 72 65 20 64 65 73 69 72 61  lines are desira
    00000020 (0x7f583800b4a0): 62 6c 65 20 66 6f 72 20 49 50 76 36 20 63 61 70  ble for IPv6 cap
    00000030 (0x7f583800b4b0): 61 62 6c 65 20 68 6f 73 74 73 0a                 able hosts.     

    00000000 (0x55e657f1c750): 3a 3a 31 20 20 20 20 20 69 70 36 2d 6c 6f 63 61  ::1     ip6-loca
    00000010 (0x55e657f1c760): 6c 68 6f 73 74 20 69 70 36 2d 6c 6f 6f 70 62 61  lhost ip6-loopba
    00000020 (0x55e657f1c770): 63 6b 0a                                         ck.             

    00000000 (0x7f583800c180): 66 65 30 30 3a 3a 30 20 69 70 36 2d 6c 6f 63 61  fe00::0 ip6-loca
    00000010 (0x7f583800c190): 6c 6e 65 74 0a                                   lnet.           

    00000000 (0x55e657f0d3f0): 66 66 30 30 3a 3a 30 20 69 70 36 2d 6d 63 61 73  ff00::0 ip6-mcas
    00000010 (0x55e657f0d400): 74 70 72 65 66 69 78 0a                          tprefix.        

    00000000 (0x55e657f09750): 66 66 30 32 3a 3a 31 20 69 70 36 2d 61 6c 6c 6e  ff02::1 ip6-alln
    00000010 (0x55e657f09760): 6f 64 65 73 0a                                   odes.           

    00000000 (0x55e657f2df70): 66 66 30 32 3a 3a 32 20 69 70 36 2d 61 6c 6c 72  ff02::2 ip6-allr
    00000010 (0x55e657f2df80): 6f 75 74 65 72 73 0a                             outers.         
    Got EOS from element "pipeline0".
    Execution ended after 0:00:00.000255455
    Setting pipeline to PAUSED ...
    Setting pipeline to READY ...
    Setting pipeline to NULL ...
    Freeing pipeline ...
