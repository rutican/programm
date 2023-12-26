
param=$1


function myfunc () {


case $param in
	0)
		VklVikl="disable"
		;;

	1)
		VklVikl="enable"
                ;;
esac

ssh ser@192.168.77.1 -p 2245  "/interface wireless $VklVikl 1"

}

if [ "$1" = "1" ]

then
	echo ""
	echo "============== Начало влючения ВайФай ============"
	echo ""
	date "+%H:%M:%S    %d-%m-%Y"
	echo ""
	echo "==================================================="
	echo ""
	myfunc	

elif 	[ "$1" = "0" ]
then
	echo ""
	echo "=============== ВайФай выключен =================="
	echo ""
	date "+%H:%M:%S    %d-%m-%Y"
	echo ""
	echo "=================================================="
	echo ""
	myfunc
else

	echo "Введите 1 для включения, 0 - для выключения"

fi


