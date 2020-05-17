project('gst-plugins-text', 'c', version : '0.1.0')

src = ['src/gsttextnoop.c', 'src/gsttext.c']

gst_dep = dependency('gstreamer-1.0', version : '>1.0')

cdata = configuration_data()
cdata.set_quoted('PACKAGE', meson.project_name())
cdata.set_quoted('PACKAGE_VERSION', meson.project_version())

configure_file(output : 'config.h', configuration : cdata)

gsttext = library('gsttext', src, dependencies : gst_dep)
