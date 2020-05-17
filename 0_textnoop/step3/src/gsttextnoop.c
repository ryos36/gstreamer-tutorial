#include "gsttextnoop.h"

struct _GstTextNoop
{
        GstElement parent_class;

};

G_DEFINE_TYPE(GstTextNoop, gst_text_noop, GST_TYPE_ELEMENT)

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

static GstFlowReturn gst_text_noop_chain(GstPad * pad, GstObject * parent,
                                           GstBuffer * buffer);

static void
gst_text_noop_class_init (GstTextNoopClass * klass)
{
        GstElementClass *gstelement_class;
        gstelement_class = (GstElementClass *) (klass);

        gst_element_class_set_static_metadata (gstelement_class,
                                               "Noop Element",
                                               "Filter",
                                               "Simple element like Identity",
                                               "Me");

        gst_element_class_add_static_pad_template (gstelement_class, &srctemplate);
        gst_element_class_add_static_pad_template (gstelement_class, &sinktemplate);
}

static void
gst_text_noop_init (GstTextNoop * noop)
{
        GstPad *srcpad;
        GstPad *sinkpad;

        srcpad = gst_pad_new_from_static_template(&srctemplate, "src");
        gst_element_add_pad(GST_ELEMENT(noop), srcpad);

        sinkpad = gst_pad_new_from_static_template(&sinktemplate, "sink");
        gst_element_add_pad(GST_ELEMENT(noop), sinkpad);

        gst_pad_set_chain_function(sinkpad, gst_text_noop_chain);
}

static GstFlowReturn
gst_text_noop_chain(GstPad * sinkpad,
                      GstObject * parent,
                      GstBuffer * buffer)
{
        GstPad *srcpad;
        GstFlowReturn ret;

        srcpad = gst_element_get_static_pad(GST_ELEMENT(parent), "src");
        ret = gst_pad_push(srcpad, buffer);
        gst_object_ref(srcpad);
        return ret;
}
