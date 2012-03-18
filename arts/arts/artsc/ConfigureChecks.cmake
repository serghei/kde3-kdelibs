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

check_c_source_compiles("
  #include <unistd.h>
  #include <sys/ioctl.h>
  void main() { int ioctl(int d, int request,...); } "
  HAVE_IOCTL_INT_INT_DOTS )

if( NOT HAVE_IOCTL_INT_INT_DOTS )
  check_c_source_compiles("
    #include <unistd.h>
    #include <sys/ioctl.h>
    void main() { int ioctl(int d, unsigned long request,...); } "
    HAVE_IOCTL_INT_ULONG_DOTS )
    if( NOT HAVE_IOCTL_INT_ULONG_DOTS )
      check_c_source_compiles("
        #include <unistd.h>
        #include <sys/ioctl.h>
        void main() { int ioctl(int d, unsigned long int request,...); } "
        HAVE_IOCTL_INT_ULONGINT_DOTS )
      if( NOT HAVE_IOCTL_INT_ULONGINT_DOTS )
        kde_message_fatal( "uknown ioctl type" )
      endif( )
    endif( )
endif( )
