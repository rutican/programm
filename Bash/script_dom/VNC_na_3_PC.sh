#!/bin/bash

# IP-адреса компьютеров
ipPC_K="192.168.1.10"
ipPC_A="192.168.1.20"
ipPC_V="192.168.1.30"

# Функция запуска VNC-подключения
VNC_PC() {
    local target_ip="$1"

    # Проверка формата IPv4
    if ! [[ "$target_ip" =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]]; then
        echo "❌ Ошибка: некорректный IP-адрес '$target_ip'"
        return 1
    fi

    echo -e "\n📡 Проверка доступности хоста $target_ip..."
    if ping -c 1 -W 2 "$target_ip" >/dev/null 2>&1; then
        echo "✅ Хост $target_ip доступен. Запускаем VNC..."
        nohup remmina -c "vnc://$target_ip?VncUsername=&VncPassword=***VNC_PASS***" >/dev/null 2>&1 &
        echo "▶️  VNC-подключение запущено в фоне."
    else
        echo "❌ Хост $target_ip недоступен (возможно, выключен или VNC-сервер не запущен)."
    fi
}

# Функция выбора ПК для VNC с отображением статуса
Vibor_PC_VNC() {
    local BLUE GREEN YELLOW RED NC
    BLUE=$(printf '\033[1;34m')
    GREEN=$(printf '\033[1;32m')
    YELLOW=$(printf '\033[1;33m')
    RED=$(printf '\033[1;31m')
    NC=$(printf '\033[0m')

    # Вспомогательная функция: проверка состояния ПК
    check_status() {
        local ip="$1"
        if ping -c 1 -W 1 "$ip" >/dev/null 2>&1; then
            echo "ON"
        else
            echo "OFF"
        fi
    }

    while true; do
        # Проверяем статус каждого ПК
        local stat_A=$(check_status "$ipPC_A")
        local stat_K=$(check_status "$ipPC_K")
        local stat_V=$(check_status "$ipPC_V")

        # Цвет статуса: ON — зелёный, OFF — красный
        local color_A="$RED"; [[ "$stat_A" == "ON" ]] && color_A="$GREEN"
        local color_K="$RED"; [[ "$stat_K" == "ON" ]] && color_K="$GREEN"
        local color_V="$RED"; [[ "$stat_V" == "ON" ]] && color_V="$GREEN"

        clear
        printf '%s\n' \
            "" \
            "${BLUE}+----------------------------------------+${NC}" \
            "${BLUE}|${NC}           ${GREEN}Подключение по VNC${NC}            ${BLUE}|${NC}" \
            "${BLUE}+----------------------------------------+${NC}" \
            "${BLUE}|${NC} ${YELLOW}1${NC}) PC1 (${ipPC_A})  ${color_A}${stat_A}${NC}   ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}2${NC}) PC2 (${ipPC_K})  ${color_K}${stat_K}${NC}   ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}3${NC}) PC3 (${ipPC_V})  ${color_V}${stat_V}${NC}   ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}4${NC}) Назад                            ${BLUE}|${NC}" \
            "${BLUE}+----------------------------------------+${NC}" \
            ""

        read -rp "Выберите компьютер [1–4]: " choice

        case "$choice" in
            1) VNC_PC "$ipPC_A" ;;
            2) VNC_PC "$ipPC_K" ;;
            3) VNC_PC "$ipPC_V" ;;
            4) return 0 ;;
            *)
                echo -e "\n${RED}❗ Неверный выбор. Введите 1, 2, 3 или 4.${NC}"
                sleep 1.5
                ;;
        esac

        echo -e "\nНажмите Enter, чтобы продолжить..."
        read -r
    done
}
