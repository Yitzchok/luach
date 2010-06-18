#############################################################################
# Makefile for building: luach
# Generated by qmake (2.01a) (Qt 4.6.2) on: Fri Jun 18 12:30:52 2010
# Project:  Luach.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -unix -o Makefile Luach.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lhdate -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		daybutton.cpp \
		functions.cpp \
		mhdate.cpp \
		changelocation.cpp \
		about.cpp moc_mainwindow.cpp \
		moc_daybutton.cpp \
		moc_mhdate.cpp \
		moc_changelocation.cpp \
		moc_about.cpp \
		qrc_Luach.cpp
OBJECTS       = main.o \
		mainwindow.o \
		daybutton.o \
		functions.o \
		mhdate.o \
		changelocation.o \
		about.o \
		moc_mainwindow.o \
		moc_daybutton.o \
		moc_mhdate.o \
		moc_changelocation.o \
		moc_about.o \
		qrc_Luach.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Luach.pro
QMAKE_TARGET  = luach
DESTDIR       = 
TARGET        = luach

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_changelocation.h ui_about.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Luach.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile Luach.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile Luach.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/luach1.0.0 || $(MKDIR) .tmp/luach1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/luach1.0.0/ && $(COPY_FILE) --parents mainwindow.h daybutton.h functions.h mhdate.h changelocation.h about.h .tmp/luach1.0.0/ && $(COPY_FILE) --parents Luach.qrc .tmp/luach1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp daybutton.cpp functions.cpp mhdate.cpp changelocation.cpp about.cpp .tmp/luach1.0.0/ && $(COPY_FILE) --parents mainwindow.ui changelocation.ui about.ui .tmp/luach1.0.0/ && $(COPY_FILE) --parents Hebrew.ts .tmp/luach1.0.0/ && (cd `dirname .tmp/luach1.0.0` && $(TAR) luach1.0.0.tar luach1.0.0 && $(COMPRESS) luach1.0.0.tar) && $(MOVE) `dirname .tmp/luach1.0.0`/luach1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/luach1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_daybutton.cpp moc_mhdate.cpp moc_changelocation.cpp moc_about.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_daybutton.cpp moc_mhdate.cpp moc_changelocation.cpp moc_about.cpp
moc_mainwindow.cpp: mhdate.h \
		functions.h \
		daybutton.h \
		changelocation.h \
		about.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_daybutton.cpp: mhdate.h \
		functions.h \
		daybutton.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) daybutton.h -o moc_daybutton.cpp

moc_mhdate.cpp: functions.h \
		mhdate.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mhdate.h -o moc_mhdate.cpp

moc_changelocation.cpp: functions.h \
		changelocation.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) changelocation.h -o moc_changelocation.cpp

moc_about.cpp: about.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) about.h -o moc_about.cpp

compiler_rcc_make_all: qrc_Luach.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_Luach.cpp
qrc_Luach.cpp: Luach.qrc \
		Icons/help-about.png \
		Icons/arrow-left-double.png \
		Icons/exit.png \
		Icons/configure.png \
		Icons/icon.png \
		Icons/arrow-right.png \
		Icons/document-print.png \
		Icons/arrow-left.png \
		Icons/calendar.png \
		Icons/arrow-right-double.png \
		Icons/location.png
	/usr/bin/rcc -name Luach Luach.qrc -o qrc_Luach.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_changelocation.h ui_about.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_changelocation.h ui_about.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_changelocation.h: changelocation.ui
	/usr/bin/uic-qt4 changelocation.ui -o ui_changelocation.h

ui_about.h: about.ui
	/usr/bin/uic-qt4 about.ui -o ui_about.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		mhdate.h \
		functions.h \
		daybutton.h \
		changelocation.h \
		about.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		mhdate.h \
		functions.h \
		daybutton.h \
		changelocation.h \
		about.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

daybutton.o: daybutton.cpp daybutton.h \
		mhdate.h \
		functions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o daybutton.o daybutton.cpp

functions.o: functions.cpp functions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o functions.o functions.cpp

mhdate.o: mhdate.cpp mhdate.h \
		functions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mhdate.o mhdate.cpp

changelocation.o: changelocation.cpp changelocation.h \
		functions.h \
		ui_changelocation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o changelocation.o changelocation.cpp

about.o: about.cpp about.h \
		ui_about.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o about.o about.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_daybutton.o: moc_daybutton.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_daybutton.o moc_daybutton.cpp

moc_mhdate.o: moc_mhdate.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mhdate.o moc_mhdate.cpp

moc_changelocation.o: moc_changelocation.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_changelocation.o moc_changelocation.cpp

moc_about.o: moc_about.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_about.o moc_about.cpp

qrc_Luach.o: qrc_Luach.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_Luach.o qrc_Luach.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(DESTDIR)/usr/bin/ || $(MKDIR) $(DESTDIR)/usr/bin/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(DESTDIR)/usr/bin/$(QMAKE_TARGET)"
	-$(STRIP) "$(DESTDIR)/usr/bin/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(DESTDIR)/usr/bin/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(DESTDIR)/usr/bin/ 


install_trans: first FORCE
	@$(CHK_DIR_EXISTS) $(DESTDIR)/usr/share/Luach/ || $(MKDIR) $(DESTDIR)/usr/share/Luach/ 
	-$(INSTALL_FILE) `pwd`/Hebrew.qm $(DESTDIR)/usr/share/Luach/


uninstall_trans:  FORCE
	-$(DEL_FILE) -r $(DESTDIR)/usr/share/Luach/Hebrew.qm
	-$(DEL_DIR) $(DESTDIR)/usr/share/Luach/ 


install_zmanim: first FORCE
	@$(CHK_DIR_EXISTS) $(DESTDIR)/usr/share/Luach/ || $(MKDIR) $(DESTDIR)/usr/share/Luach/ 
	-$(INSTALL_FILE) `pwd`/ZmanimCLI.jar $(DESTDIR)/usr/share/Luach/


uninstall_zmanim:  FORCE
	-$(DEL_FILE) -r $(DESTDIR)/usr/share/Luach/ZmanimCLI.jar
	-$(DEL_DIR) $(DESTDIR)/usr/share/Luach/ 


install_icon: first FORCE
	@$(CHK_DIR_EXISTS) $(DESTDIR)/usr/share/Luach/ || $(MKDIR) $(DESTDIR)/usr/share/Luach/ 
	-$(INSTALL_FILE) `pwd`/Icons/calendar.png $(DESTDIR)/usr/share/Luach/


uninstall_icon:  FORCE
	-$(DEL_FILE) -r $(DESTDIR)/usr/share/Luach/calendar.png
	-$(DEL_DIR) $(DESTDIR)/usr/share/Luach/ 


install_menu: first FORCE
	@$(CHK_DIR_EXISTS) $(DESTDIR)/usr/share/applications/ || $(MKDIR) $(DESTDIR)/usr/share/applications/ 
	-$(INSTALL_PROGRAM) `pwd`/Luach.desktop $(DESTDIR)/usr/share/applications/
	-strip $(DESTDIR)/usr/share/applications/Luach.desktop


uninstall_menu:  FORCE
	-$(DEL_FILE) -r $(DESTDIR)/usr/share/applications/Luach.desktop
	-$(DEL_DIR) $(DESTDIR)/usr/share/applications/ 


install:  install_target install_trans install_zmanim install_icon install_menu  FORCE

uninstall: uninstall_target uninstall_trans uninstall_zmanim uninstall_icon uninstall_menu   FORCE

FORCE:

