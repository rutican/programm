#/bin/bash

#Определим переменные

ipPC_K="192.168.77.113"
ipPC_A="192.168.77.119"
ip_R="192.168.77.1"
pSSH="2245"

#=============== Выключить пк К
function viklPC_K(){
	# проверим доступность хоста
	
	ping -c 1 $ipPC_K > /dev/null
	if [ $? -eq 0 ]; then
	    echo "Хост ipPC_K доступен, выключаем!"
	    ssh user@$ipPC_K -p 22  "shutdown /s"
	else
	    echo "Хост ipPC_K недоступен, возможно выключен!"
	fi
	
	
#========= end Выключить пк К
}
#=============== Выключить пк А
function viklPC_A(){
	# проверим доступность хоста
	
	ping -c 1 $ipPC_A > /dev/null
	if [ $? -eq 0 ]; then
	    echo "Хост ipPC_A доступен, выключаем!"
	    ssh user@$ipPC_A -p 22  "shutdown /s"
	else
	    echo "Хост ipPC_A недоступен, возможно выключен!"
	fi
	
	
}
#========= end Выключить пк A

#=============== VNC на ПК А 1)
function VNC_PC_A(){
	# проверим доступность хоста
	
	ping -c 1 $ipPC_A > /dev/null
	if [ $? -eq 0 ]; then
	    echo "Хост ipPC_A доступен, запускаем VNC"
	    remmina -c vnc://$ipPC_A?VncUsername=""\&VncPassword="tess=4" &
	else
	    echo "Хост ipPC_A недоступен, возможно выключен!"
	fi
	
	
}
#========= end VNC на ПК А


#=============== VNC на ПК K 1)
function VNC_PC_K(){
	# проверим доступность хоста
	
	ping -c 1 $ipPC_K > /dev/null
	if [ $? -eq 0 ]; then
	    echo "Хост ipPC_K доступен, запускаем VNC"
	    remmina -c vnc://$ipPC_K?VncUsername=""\&VncPassword="tess=4" &
	else
	    echo "Хост ipPC_K недоступен, возможно выключен!"
	fi
	
	
}
#========= end VNC на ПК А

#=============== Включить ПК K 
function vkl_PC_K(){
	# проверим доступность хоста
	
	ping -c 1 $ipPC_K > /dev/null
	if [ $? -eq 0 ]; then
	    echo "Хост ipPC_K доступен, т.е. он уже РАБОТАЕТ!"
	  
	else
	    echo "Хост ipPC_K недоступен, ВКЛЮЧАЕМ!"
	     wakeonlan a8:a1:59:ed:99:f0
	fi
	
	
}
#========= end выключить ПК К


#=============== Включить вайфай на опред время 
function vkl_wifi(){
	
	echo ""
		echo  "Введите время работы вайфай "
		echo -n "Формат ввода <число><m> или <число><h> - введите-> "
		read time
		
		echo ""
	echo "============== Начало влючения ВайФай ============"
	echo ""
#	date
	date "+%H:%M:%S    %d-%m-%Y"
	echo ""
	echo "============== Выключение ВайФай через $1 ========"
	echo ""
	
	ssh ser@$ip_R -p $pSSH "[:parse [/system script get script1 source ]] ztime=$time"

	
}
#========= end включить вайфай на время


#=============== Запуск Winbox 4)
function startWinbox(){
	
	echo ""
	echo "Запуск программы Winbox64"
	wine /home/rut/progWin/WinBox/winbox64.exe &
}
#========= end Запуск Winbox

#=============== Запустить программу winCP 5)
function startWinCP(){
	
	echo ""
	echo "Запуск программы winCP"
	
	wine /home/rut/progWin/WinCp/WinSCP-5.19.6-Portable/WinSCP.exe &
}
#========= end Запустить программу winCP

#=============== Запустить программу Вацап 6)
function startVacap(){
	
	echo ""
	echo "Запуск программы Вацап"
	
	 whatsdesk &
}
#========= end Запустить программу Вацап



#===========================Начало программы

	echo "Добро пожаловать в скрипт!"
	echo "Важно! Данный скрипт запускает программы"
	echo ""
	echo "Что вы хотите запустить?"
	echo "   1) VNC на ПК А"
	echo "   2) VNC на ПК К"
	echo "   3) Включить wifi на определенное время"
	echo "   4) Запустить mikrotik Winbox"
	echo "   5) Запустить программу winCP"
	echo "   6) Запустить программу Вацап"
	echo "   7) Выключить ПК А"
	echo "   8) Выключить ПК К"
	echo "   9) Включить ПК К"
	echo "   10) Exit"
	echo ""
	
	until [[ $MENU_OPTION =~ ^[1-9]$ ]]; do
		read -rp "Select an option [1-9]: " MENU_OPTION
	done

	case $MENU_OPTION in
	1)	
		VNC_PC_A
		;;
	2)	
		VNC_PC_K
		;;
	3)	
		vkl_wifi
		;;
	4)	
		startWinbox
		;;
	5)	
		startWinCP
		;;
	6)	
		startVacap
		;;
	7)	
		viklPC_A
		;;
	8)	
		
		viklPC_K
		;;
	9)
		vkl_PC_K
		;;
	10)
	
		exit 0
		;;
	esac
#================конец программы




