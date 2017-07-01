AM_CPPFLAGS = -DDEBUG -D_GNU_SOURCE
AM_CXXFLAGS = $(DEFAULT_CXXFLAGS)
AM_LDFLAGS =


lib_LTLIBRARIES =
lib_LTLIBRARIES += libtwsapi.la
libtwsapi_la_SOURCES =
libtwsapi_la_SOURCES += src/EClientSocketBase.cpp
libtwsapi_la_SOURCES += src/EPosixClientSocket.cpp
header_HEADERS =
header_HEADERS += $(top_srcdir)/Include/Shared/CommonDefs.h
header_HEADERS += $(top_srcdir)/Include/Shared/CommissionReport.h
header_HEADERS += $(top_srcdir)/Include/Shared/Contract.h
header_HEADERS += $(top_srcdir)/Include/Shared/EClient.h
header_HEADERS += $(top_srcdir)/Include/Shared/EClientSocketBase.h
header_HEADERS += $(top_srcdir)/Include/Shared/EWrapper.h
header_HEADERS += $(top_srcdir)/Include/Shared/Execution.h
header_HEADERS += $(top_srcdir)/Include/Shared/IBString.h
header_HEADERS += $(top_srcdir)/Include/Shared/Order.h
header_HEADERS += $(top_srcdir)/Include/Shared/OrderState.h
header_HEADERS += $(top_srcdir)/Include/Shared/ScannerSubscription.h
header_HEADERS += $(top_srcdir)/Include/Shared/TagValue.h
header_HEADERS += $(top_srcdir)/Include/Shared/shared_ptr.h
header_HEADERS += src/EPosixClientSocket.h
header_HEADERS += $(top_srcdir)/Include/Shared/TwsSocketClientErrors.h
noinst_HEADERS =
noinst_HEADERS += $(top_srcdir)/Include/Shared/EClientSocketBaseImpl.h
noinst_HEADERS += $(top_srcdir)/Include/Shared/TwsSocketClientErrors.h
noinst_HEADERS += src/EPosixClientSocketPlatform.h

EXTRA_libtwsapi_la_SOURCES =
libtwsapi_la_LIBADD =


libtwsapi_la_CPPFLAGS =
libtwsapi_la_CPPFLAGS += $(AM_CPPFLAGS) -fPIC
libtwsapi_la_CPPFLAGS += -I$(top_srcdir)/Include/Shared

CLEANFILES =
CLEANFILES += *.s
CLEANFILES += *.i

## Create preprocessor output (debugging purposes only)
.c.i:
	$(COMPILE) -E -o $@ $<
.cpp.i:
	$(CXXCOMPILE) -E -o $@ $<

## Create assembler output (debugging purposes only)
.c.s:
	$(COMPILE) -S -c $(cflags) $<
.cpp.s:
	$(CXXCOMPILE) -S -c $(cflags) $<

