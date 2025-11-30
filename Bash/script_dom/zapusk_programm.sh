#!/bin/bash

# Функция запуска Winbox (нативная версия)
startWinbox() {
    echo -e "\n▶️  Запуск Winbox..."
    if [[ -x "~/tools/BistrZap/WinBox_Linux/WinBox" ]]; then
        nohup ~/tools/BistrZap/WinBox_Linux/WinBox >/dev/null 2>&1 &
        echo "✅ Winbox запущен в фоне."
    else
        echo "❌ Ошибка: исполняемый файл WinBox не найден или не запускаем."
    fi
}

# Функция запуска WinSCP через Wine
startWinCP() {
    local winscp_path="~/tools/Win_Prog/WinCp/WinSCP-5.19.6-Portable/WinSCP.exe"
    echo -e "\n▶️  Запуск WinSCP..."
    if [[ -f "$winscp_path" ]]; then
        nohup wine "$winscp_path" >/dev/null 2>&1 &
        echo "✅ WinSCP запущен в фоне."
    else
        echo "❌ Ошибка: файл WinSCP не найден: $winscp_path"
    fi
}

# Функция запуска WhatsApp (через WhatsDesk)
startVacap() {
    echo -e "\n▶️  Запуск WhatsApp (WhatsDesk)..."
    if command -v whatsdesk >/dev/null 2>&1; then
        nohup whatsdesk >/dev/null 2>&1 &
        echo "✅ WhatsApp запущен в фоне."
    else
        echo "❌ Ошибка: программа 'whatsdesk' не установлена или недоступна в PATH."
    fi
}

# Функция запуска Chrome с прокси и spoof-dpi
startCHrom() {
    echo -e "\n▶️  Запуск Google Chrome с прокси и spoof-dpi..."

    # Проверка наличия spoof-dpi
    if ! command -v spoof-dpi >/dev/null 2>&1; then
        echo "⚠️  Предупреждение: spoof-dpi не найден. Прокси может не обходить DPI."
    else
        nohup spoof-dpi >/dev/null 2>&1 &
        echo "🛡️  spoof-dpi запущен в фоне."
    fi

    # Запуск Chrome
    if command -v google-chrome >/dev/null 2>&1; then
        nohup google-chrome --proxy-server="http://127.0.0.1:8080" --no-default-browser-check --disable-features=TranslateUI >/dev/null 2>&1 &
        echo "🌐 Chrome запущен с прокси 127.0.0.1:8080."
    else
        echo "❌ Ошибка: google-chrome не найден. Убедитесь, что он установлен."
    fi
}

# Основное меню запуска программ
Zapusk_Programm() {
    local BLUE GREEN YELLOW RED NC
    BLUE=$(printf '\033[1;34m')
    GREEN=$(printf '\033[1;32m')
    YELLOW=$(printf '\033[1;33m')
    RED=$(printf '\033[1;31m')
    NC=$(printf '\033[0m')

    while true; do
        clear
        printf '%s\n' \
            "" \
            "${BLUE}+----------------------------------------+${NC}" \
            "${BLUE}|${NC}       ${GREEN}Запуск программ${NC}                 ${BLUE}|${NC}" \
            "${BLUE}+----------------------------------------+${NC}" \
            "${BLUE}|${NC} ${YELLOW}1${NC}) Winbox (MikroTik)                  ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}2${NC}) WinSCP (SFTP/FTP)                 ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}3${NC}) WhatsApp (WhatsDesk)             ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}4${NC}) Chrome с прокси                   ${BLUE}|${NC}" \
            "${BLUE}|${NC} ${YELLOW}5${NC}) Назад                              ${BLUE}|${NC}" \
            "${BLUE}+----------------------------------------+${NC}" \
            ""

        read -rp "Выберите программу [1–5]: " choice

        case "$choice" in
            1) startWinbox ;;
            2) startWinCP ;;
            3) startVacap ;;
            4) startCHrom ;;
            5) return 0 ;;
            *)
                echo -e "\n${RED}❗ Неверный выбор. Введите число от 1 до 5.${NC}"
                sleep 1.5
                ;;
        esac

        echo -e "\nНажмите Enter для продолжения..."
        read -r
    done
}
