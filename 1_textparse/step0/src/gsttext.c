#include <gst/gst.h>
#include "config.h"
#include "gsttextnoop.h"
#include "gsttextparse.h"

static gboolean
plugin_init (GstPlugin * plugin)
{
        gst_element_register(plugin, "textnoop", GST_RANK_NONE, gst_text_noop_get_type());
        gst_element_register(plugin, "textparse", GST_RANK_NONE, gst_text_parse_get_type());
        return TRUE;
}


GST_PLUGIN_DEFINE (
        GST_VERSION_MAJOR,
        GST_VERSION_MINOR,
        gsttext,
        "Text Plugins for GStreamer",
        plugin_init,
        PACKAGE_VERSION,
        "LGPL",
        "GStreamer Text Package",
        "https://github/yashi/gst-plugins-text")
