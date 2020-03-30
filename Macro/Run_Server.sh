#!/bin/bash

vendor_id=21e1
device_id=3

if [ ${1-"NORMAL"} == "DEBUG" ];
then
    mode="DEBUG"
    tty="test_port"
else
    mode="NORMAL"

    for num in {0..9}
    do
	res=`grep PRODUCT /sys/class/tty/ttyACM${num}/../../uevent`
	
	if [[ $res = *${vendor_id}/${device_id}* ]];
	then
	    tty=ttyACM${num}
	    break
	fi
	
    done

    if [ test $tty ];
    then
	echo "Can't find device!"
	exit
    fi
fi

rm -f ${QC_SW_PATH}/Macro/FIFO
${QC_SW_PATH}/Bin/Server $tty $mode

