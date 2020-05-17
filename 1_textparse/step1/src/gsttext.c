#include <gst/gst.h>
#include "config.h"
#include "gsttextparse.h"

static gboolean
plugin_init (GstPlugin * plugin)
{
        gst_element_register(plugin, "textparse", GST_RANK_NONE, gst_text_parse_get_type());
        return TRUE;
}


GST_PLUGIN_DEFINE (
        GST_VERSION_MAJOR,
        GST_VERSION_MINOR,
        text,
        "Text Plugins for GStreamer",
        plugin_init,
        PACKAGE_VERSION,
        "LGPL",
        "GStreamer Text Package",
        "https://github/yashi/gst-plugins-text")
