include /tmp/rocksdb/make_config.mk

ifndef DISABLE_JEMALLOC
	ifdef JEMALLOC
		PLATFORM_CXXFLAGS += -DROCKSDB_JEMALLOC -DJEMALLOC_NO_DEMANGLE
	endif
	EXEC_LDFLAGS := $(JEMALLOC_LIB) $(EXEC_LDFLAGS) -lpthread
	PLATFORM_CXXFLAGS += $(JEMALLOC_INCLUDE)
endif

ifneq ($(USE_RTTI), 1)
	CXXFLAGS += -fno-rtti
endif

CFLAGS += -Wstrict-prototypes

.PHONY: clean librocksdb

all: dbtestset dbtestget dbtestgetrand dbtestsetrand

dbtestset: librocksdb dbtestset.cc
	$(CXX) $(CXXFLAGS) $@.cc -o$@ /tmp/rocksdb/librocksdb.a -I/tmp/rocksdb/include -O2 -std=c++17 $(PLATFORM_LDFLAGS) $(PLATFORM_CXXFLAGS) $(EXEC_LDFLAGS)

dbtestgetrand: librocksdb dbtestgetrand.cc
	$(CXX) $(CXXFLAGS) $@.cc -o$@ /tmp/rocksdb/librocksdb.a -I/tmp/rocksdb/include -O2 -std=c++17 $(PLATFORM_LDFLAGS) $(PLATFORM_CXXFLAGS) $(EXEC_LDFLAGS)

dbtestsetrand: librocksdb dbtestsetrand.cc
	$(CXX) $(CXXFLAGS) $@.cc -o$@ /tmp/rocksdb/librocksdb.a -I/tmp/rocksdb/include -O2 -std=c++17 $(PLATFORM_LDFLAGS) $(PLATFORM_CXXFLAGS) $(EXEC_LDFLAGS)

dbtestget: librocksdb dbtestget.cc
	$(CXX) $(CXXFLAGS) $@.cc -o$@ /tmp/rocksdb/librocksdb.a -I/tmp/rocksdb/include -O2 -std=c++17 $(PLATFORM_LDFLAGS) $(PLATFORM_CXXFLAGS) $(EXEC_LDFLAGS)

librocksdb:
	cd /tmp/rocksdb && $(MAKE) static_lib
