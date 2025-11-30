#!/bin/bash

# IP-адреса компьютеров (должны совпадать с основным скриптом)
ipPC_K="192.168.1.10"
ipPC_A="192.168.1.20"
ipPC_V="192.168.1.30"

# Функция отправки сообщения на Windows через msg.exe
send_message_to_pc() {
    local target_ip="$1"
    local label="$2"

    # Проверка IP
    if ! [[ "$target_ip" =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]]; then
        echo "❌ Ошибка: некорректный IP '$target_ip'"
        return 1
    fi

    echo -e "\n💬 Введите текст сообщения для ПК $label (оставьте пустым для отмены):"
    read -r message

    if [[ -z "$message" ]]; then
        echo -e "\nℹ️  Отправка отменена."
        return 0
    fi

    echo -e "\n📡 Отправка сообщения на $target_ip..."

    # Проверяем доступность (повторно, на случай изменения состояния)
    if ! ping -c 1 -W 2 "$target_ip" >/dev/null 2>&1; then
        echo "❌ ПК $label ($target_ip) недоступен. Отправка невозможна."
        return 1
    fi

    # Отправляем через SSH команду: msg * "текст"
    if ssh -o ConnectTimeout=5 -o BatchMode=yes "winuser@$target_ip" -p 22 "msg * \"$message\"" 2>/dev/null; then
        echo -e "\n✅ Сообщение успешно отправлено на ПК $label!"
    else
        echo -e "\n❌ Не удалось отправить сообщение. Проверьте:"
        echo "   • Доступность ПК по SSH"
        echo "   • Наличие прав на выполнение 'msg' (требуется Windows Pro/Enterprise)"
        echo "   • Учётную запись 'user' с правами отправки сообщений"
    fi
}

# Меню выбора получателя с отображением статуса
Poslat_message_win() {
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
        # Получаем текущий статус каждого ПК
        local stat_A=$(check_status "$ipPC_A")
        local stat_K=$(check_status "$ipPC_K")
        local stat_V=$(check_status "$ipPC_V")

        # Определяем цвет статуса
        local color_A="$RED"; [[ "$stat_A" == "ON" ]] && color_A="$GREEN"
        local color_K="$RED"; [[ "$stat_K" == "ON" ]] && color_K="$GREEN"
        local color_V="$RED"; [[ "$stat_V" == "ON" ]] && color_V="$GREEN"

        clear
        printf '%s\n' \
            "" \
            "${BLUE}+----------------------------------------+${NC}" \
            "${BLUE}|${NC}      ${GREEN}Отправка сообщения на Windows${NC}      ${BLUE}|${NC}" \
            "${BLUE}+----------------------------------------+${NC}" \
            "${BLUE}|${NC} ${YELLOW}1${NC}) PC1 (${ipPC_A})  ${color_A}${stat_A}${NC}   ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}2${NC}) PC2 (${ipPC_K})  ${color_K}${stat_K}${NC}   ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}3${NC}) PC3 (${ipPC_V})  ${color_V}${stat_V}${NC}   ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}4${NC}) Назад                            ${BLUE}|${NC}" \
            "${BLUE}+----------------------------------------+${NC}" \
            ""

        read -rp "Выберите получателя [1–4]: " choice

        case "$choice" in
            1) send_message_to_pc "$ipPC_A" "А" ;;
            2) send_message_to_pc "$ipPC_K" "К" ;;
            3) send_message_to_pc "$ipPC_V" "В" ;;
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
