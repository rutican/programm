#!/bin/bash

# Убедись, что в основном скрипте определены:
#   ip_R="192.168.1.1"
#   pSSH="2245"

vikl_kolonku() {
    local BLUE GREEN YELLOW RED NC
    BLUE=$(printf '\033[1;34m')
    GREEN=$(printf '\033[1;32m')
    YELLOW=$(printf '\033[1;33m')
    RED=$(printf '\033[1;31m')
    NC=$(printf '\033[0m')

    local choice

    clear
    printf '%s\n' \
        "" \
        "${BLUE}+------------------------------------------+${NC}" \
        "${BLUE}|${NC}    ${GREEN}Управление колонкой (On/Off)${NC}        ${BLUE}|${NC}" \
        "${BLUE}+------------------------------------------+${NC}" \
        ""

    while true; do
        read -rp "Включить колонку? (y/n): " choice

        case "$choice" in
            [yY])
                echo -e "\n🔊 Включение колонки..."
                if ssh "router_user@$ip_R" -p "$pSSH" "interface/wireless/access-list/enable numbers=6" 2>/dev/null; then
                    echo "✅ Колонка включена."
                else
                    echo "❌ Не удалось включить колонку. Проверьте подключение к роутеру."
                fi
                break
                ;;
            [nN])
                echo -e "\n🔇 Выключение колонки..."
                if ssh "router_user@$ip_R" -p "$pSSH" "interface/wireless/access-list/disable numbers=6" 2>/dev/null; then
                    echo "✅ Колонка выключена."
                else
                    echo "❌ Не удалось выключить колонку. Проверьте подключение к роутеру."
                fi
                break
                ;;
            *)
                echo -e "\n${RED}❗ Введите 'y' для включения или 'n' для выключения.${NC}\n"
                ;;
        esac
    done

    echo -e "\nНажмите Enter для возврата..."
    read -r
}
