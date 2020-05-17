/* Original Source from Yasushi SHOJI https://github.com/yashi */

#include "gsttextparse.h"

struct _GstTextParse
{
        GstBaseParse parent;

};

G_DEFINE_TYPE(GstTextParse, gst_text_parse, GST_TYPE_BASE_PARSE)

static GstStaticPadTemplate sinktemplate =
        GST_STATIC_PAD_TEMPLATE ("sink",
                                 GST_PAD_SINK,
                                 GST_PAD_ALWAYS,
                                 GST_STATIC_CAPS_ANY);

static GstStaticPadTemplate srctemplate =
        GST_STATIC_PAD_TEMPLATE ("src",
                                 GST_PAD_SRC,
                                 GST_PAD_ALWAYS,
                                 GST_STATIC_CAPS_ANY);

static void
gst_text_parse_class_init (GstTextParseClass * klass)
{
        GstElementClass *element_class = GST_ELEMENT_CLASS(klass);

        gst_element_class_set_static_metadata (element_class,
                                               "Text Parser element",
                                               "Filter",
                                               "Parse text stream",
                                               "Yasushi SHOJI");

        gst_element_class_add_static_pad_template (element_class, &srctemplate);
        gst_element_class_add_static_pad_template (element_class, &sinktemplate);
}

static void
gst_text_parse_init (G_GNUC_UNUSED GstTextParse * parse)
{
}
