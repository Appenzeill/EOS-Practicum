#!/usr/bin/env bash
FILE=$1
FILE_EXT=${FILE: -3}

case $FILE_EXT in

  .cc)
    cat $FILE
    ;;

  .py)
    python $FILE
    ;;

  .sh)
    bash $FILE
    ;;

  *)
    echo "error"
    ;;
esac
