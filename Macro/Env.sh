#!/bin/bash

path=$(dirname -- $(readlink -fn -- "$BASH_SOURCE"))
QC_SW_PATH=`dirname ${path}`

echo $QC_SW_PATH
export QC_SW_PATH
