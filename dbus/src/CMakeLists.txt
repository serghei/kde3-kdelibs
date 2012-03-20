#################################################
#
#  (C) 2012 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${QT_INCLUDE_DIR}
  ${DBUS_INCLUDE_DIRS}
)


##### headers ###################################

install( FILES
    qdbusconnection.h qdbusdata.h qdbusdatamap.h qdbusmacros.h
    qdbusobject.h qdbusproxy.h qdbusvariant.h qdbusdataconverter.h
    qdbusdatalist.h qdbuserror.h qdbusmessage.h qdbusobjectpath.h
    qdbusserver.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/dbus )


##### kdedbus (shared) #########################

kde_moc( MOCS qdbusconnection_p.h )

kde_add_library( kdedbus SHARED AUTOMOC
  SOURCES
    qdbusconnection.cpp qdbusdata.cpp qdbuserror.cpp qdbusmarshall.cpp
    qdbusobjectpath.cpp qdbusserver.cpp qdbusdataconverter.cpp
    qdbusdatalist.cpp qdbusintegrator.cpp qdbusmessage.cpp qdbusproxy.cpp
    ${MOCS}
  VERSION 0.0.0
  LINK ${QT_LIBRARY} ${DBUS_LIBRARIES}
  DESTINATION ${LIB_INSTALL_DIR}
)
