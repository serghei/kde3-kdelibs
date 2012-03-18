#!/bin/sh

usage()
{
	echo "usage: $0 [OPTIONS]"
cat << EOH

options:
	[--libs]
	[--cflags]
	[--version]
	[--arts-version]
	[--arts-prefix]
EOH
	exit 1;
}

prefix=@CMAKE_INSTALL_PREFIX@
exec_prefix=@EXEC_INSTALL_PREFIX@
libdir=@LIB_INSTALL_DIR@
includedir=@INCLUDE_INSTALL_DIR@

flags=""

while test $# -gt 0
do
  case $1 in
    --libs)
	  flags="$flags -L$libdir -lartsc
	  ;;
    --cflags)
	  flags="$flags -I$includedir/artsc
	  ;;
    --version)
	  echo 0.9.5
	  ;;
    --arts-version)
	  echo @ARTS_VERSION@
	  ;;
    --arts-prefix)
	  echo $prefix
	  ;;
	*)
	  echo "$0: unknown option $1"
	  echo 
	  usage
	  ;;
  esac
  shift
done

if test -n "$flags"
then
  echo $flags
fi
