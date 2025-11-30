#!/bin/bash

# IP и MAC-адреса компьютеров
ipPC_K="192.168.1.10"
ipPC_A="192.168.1.20"
ipPC_V="192.168.1.30"

macADR_K="00:11:22:33:44:55"
macADR_A="00:11:22:33:44:56"
macADR_V="00:11:22:33:44:57"

# Функция включения ПК по IP и MAC
Vkl_PC() {
    local target_ip="$1"
    local mac_addr="$2"
    local label="$3"

    # Проверка IP
    if ! [[ "$target_ip" =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]]; then
        echo "❌ Ошибка: некорректный IP '$target_ip'"
        return 1
    fi

    # Проверка MAC
    if ! [[ "$mac_addr" =~ ^([0-9A-Fa-f]{2}[:-]){5}[0-9A-Fa-f]{2}$ ]]; then
        echo "❌ Ошибка: некорректный MAC-адрес '$mac_addr'"
        return 1
    fi

    echo -e "\n🔍 Проверка состояния ПК $label ($target_ip)..."
    if ping -c 1 -W 2 "$target_ip" >/dev/null 2>&1; then
        echo "✅ ПК $label уже включён и доступен в сети."
    else
        echo "📴 ПК $label недоступен. Отправка Wake-on-LAN сигнала..."

        if ! command -v wakeonlan >/dev/null 2>&1; then
            echo "❌ Утилита 'wakeonlan' не установлена."
            echo "   Установите: sudo apt install wakeonlan"
            return 1
        fi

        if wakeonlan "$mac_addr" >/dev/null 2>&1; then
            echo "📡 Wake-on-LAN сигнал отправлен на $mac_addr"
            echo "💡 ПК может включиться через несколько секунд."
        else
            echo "❌ Не удалось отправить Wake-on-LAN сигнал."
        fi
    fi
}

# Меню включения ПК с отображением текущего статуса
Vibor_PC_Vkl() {
    local BLUE GREEN YELLOW RED NC
    BLUE=$(printf '\033[1;34m')
    GREEN=$(printf '\033[1;32m')
    YELLOW=$(printf '\033[1;33m')
    RED=$(printf '\033[1;31m')
    NC=$(printf '\033[0m')

    # Функция проверки статуса ПК
    check_status() {
        local ip="$1"
        if ping -c 1 -W 1 "$ip" >/dev/null 2>&1; then
            echo "ON"
        else
            echo "OFF"
        fi
    }

    while true; do
        # Получаем статус каждого ПК
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
            "${BLUE}|${NC}       ${GREEN}Включение компьютеров${NC}            ${BLUE}|${NC}" \
            "${BLUE}+----------------------------------------+${NC}" \
            "${BLUE}|${NC} ${YELLOW}1${NC}) PC1 (${ipPC_A})  ${color_A}${stat_A}${NC}   ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}2${NC}) PC2 (${ipPC_K})  ${color_K}${stat_K}${NC}   ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}3${NC}) PC3 (${ipPC_V})  ${color_V}${stat_V}${NC}   ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}4${NC}) Назад                            ${BLUE}|${NC}" \
            "${BLUE}+----------------------------------------+${NC}" \
            ""

        read -rp "Выберите ПК для включения [1–4]: " choice

        case "$choice" in
            1) Vkl_PC "$ipPC_A" "$macADR_A" "А" ;;
            2) Vkl_PC "$ipPC_K" "$macADR_K" "К" ;;
            3) Vkl_PC "$ipPC_V" "$macADR_V" "В" ;;
            4) return 0 ;;
            *)
                echo -e "\n${RED}❗ Неверный выбор. Введите 1, 2, 3 или 4.${NC}"
                sleep 1.5
                ;;
        esac

        echo -e "\nНажмите Enter для продолжения..."
        read -r
    done
}
