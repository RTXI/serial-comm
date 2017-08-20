
PLUGIN_NAME = serial_comm

HEADERS =  serial.h \
           serial_comm.h

SOURCES = serial.cpp \
          serial_comm.cpp \
          moc_serial_comm.cpp

LIBS = 

### Do not edit below this line ###

include $(shell rtxi_plugin_config --pkgdata-dir)/Makefile.plugin_compile
