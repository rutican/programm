#!/bin/bash

#Определим переменные

ipPC_K="192.168.1.10"
ipPC_A="192.168.1.20"
ipPC_V="192.168.1.30"

ip_R="192.168.1.1"
pSSH="2245"
cd ~/tools/BistrZap/
# Экспортируем функции
#. ./progi.sh
. ./Vikl_kolonku.sh
#source ~/tools/BistrZap/Vikl_kolonku.sh
. ./Vikl_kolonku.sh
. ./VNC_na_3_PC.sh
. ./Wi-Fi.sh
. ./zapusk_programm.sh
. ./Vikl_PC.sh
. ./VKL_PC.sh
. ./Televizor.sh
  ./permanent_vikl_PC.sh
 #. ~/tools/BistrZap/Vikl_kolonku.sh
#source "./BistrZap/VNC_na_3_PC.sh"

#echo "Перед показом выбора"

#===========================Начало программы
echo ""
	echo ""
	echo "Добро пожаловать в скрипт!"
	echo "Важно! Данный скрипт запускает программы"
	echo ""
	echo "Что вы хотите запустить?"
	echo ""
	echo "   1) VNC на ПК"
	echo "      2) Включить wifi на определенное время"
	echo "          3) Запустить ПРОГРАММУ"
	echo "   4) ВЫКЛючить ПК"
	echo "      5) ВКЛючить ПК"
	echo "          6) Включить ТЕЛЕВИЗОР"
	echo "          	7) On/Off Колонка"
	echo "   8) Exit"
	echo ""
	
	until [[ $MENU_OPTION =~ ^[1-8]$ ]]; do
		read -rp "Select an option [1-8]: " MENU_OPTION
	done

	case $MENU_OPTION in
	1)	
		echo "VNC на PC1"
		Vibor_PC_VNC
		;;
	2)	
		echo "Включить wifi на определенное время"
		vkl_wifi
		;;
	3)	
		echo "Запустить ПРОГРАММУ"
		Zapusk_Programm
		;;
	4)	
		echo "Выключить ПК"
		Vibor_PC_Vikl
		;;
	5)
		echo "Включить ПК"
		Vibor_PC_Vkl
		;;

	6)
                echo "Включить ТЕЛЕВИЗОР"
                vkl_televizor
                ;;
	7)
                echo "On/Off Колонка"
		vikl_kolonku
                ;;
	8)
		exit 0
		;;
	esac
#================конец программы


cd 

