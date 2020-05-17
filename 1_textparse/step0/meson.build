project('gst-plugins-text', 'c', version : '0.1.0')

src = ['src/gsttext.c', 'src/gsttextparse.c']

gst_dep = dependency('gstreamer-base-1.0', version : '>1.0')

cdata = configuration_data()
cdata.set_quoted('PACKAGE', meson.project_name())
cdata.set_quoted('PACKAGE_VERSION', meson.project_version())

configure_file(output : 'config.h', configuration : cdata)

gsttext = library('text', src, dependencies : gst_dep)
