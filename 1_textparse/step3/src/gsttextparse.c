/* Original Source from Yasushi SHOJI https://github.com/yashi */

#include "gsttextparse.h"

struct _GstTextParse
{
        GstBaseParse parent;

};

G_DEFINE_TYPE(GstTextParse, gst_text_parse, GST_TYPE_BASE_PARSE)


static GstFlowReturn gst_text_parse_handle_frame (GstBaseParse * parse, GstBaseParseFrame * frame, G_GNUC_UNUSED gint * skipsize);

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
        GstBaseParseClass *base_class = GST_BASE_PARSE_CLASS(klass);

        gst_element_class_set_static_metadata (element_class,
                                               "Text Parser element",
                                               "Filter",
                                               "Parse text stream ",
                                               "Yasushi SHOJI");

        gst_element_class_add_static_pad_template (element_class, &srctemplate);
        gst_element_class_add_static_pad_template (element_class, &sinktemplate);

        base_class->handle_frame = gst_text_parse_handle_frame;
}

static GstFlowReturn
gst_text_parse_handle_frame (GstBaseParse * parse,
                             GstBaseParseFrame * frame,
                             G_GNUC_UNUSED gint * skipsize)
{
        GstPad *srcpad;
        ptrdiff_t len;
        guint8 *pos;
        GstMapInfo info;

        srcpad = gst_element_get_static_pad(GST_ELEMENT(parse), "src");
        if (!gst_pad_has_current_caps(srcpad))
                gst_pad_set_caps(srcpad, gst_caps_new_empty_simple ("text/x-raw"));

        gst_buffer_map(frame->buffer, &info, GST_MAP_READ);

        pos = memchr(info.data, '\n', info.size);
        if (!pos)
                return GST_FLOW_OK;
        len = pos - info.data;

        gst_buffer_unmap(frame->buffer, &info);

        return gst_base_parse_finish_frame(parse, frame, len+1);
}

static void
gst_text_parse_init (G_GNUC_UNUSED GstTextParse * parse)
{
}

