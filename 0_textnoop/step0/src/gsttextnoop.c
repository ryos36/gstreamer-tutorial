#include "gsttextnoop.h"

struct _GstTextNoop
{
        GstElement parent_class;
};

G_DEFINE_TYPE(GstTextNoop, gst_text_noop, GST_TYPE_ELEMENT)

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
}

static void
gst_text_noop_init (GstTextNoop * noop)
{
}
