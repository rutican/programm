#!/bin/bash

# Определяем директорию, где лежит ПАПКА BistrZap (относительно этого скрипта)
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Если скрипт запущен из BistrZap, поднимаемся на уровень выше
if [[ "$(basename "$SCRIPT_DIR")" == "BistrZap" ]]; then
    BASE_DIR="$(dirname "$SCRIPT_DIR")"
else
    BASE_DIR="$SCRIPT_DIR"
fi

# Путь к модулям
MODULES_DIR="$BASE_DIR/BistrZap"

# Проверяем, существует ли папка модулей
if [[ ! -d "$MODULES_DIR" ]]; then
    echo "❌ Ошибка: не найдена папка модулей '$MODULES_DIR'"
    echo "💡 Убедитесь, что папка 'BistrZap' находится рядом со скриптом."
    exit 1
fi

# Настройки сети
ipPC_K="192.168.1.10"
ipPC_A="192.168.1.20"
ipPC_V="192.168.1.30"
ip_R="192.168.1.1"
pSSH="2245"

# Экспортируем переменные, чтобы модули их видели
export ipPC_K ipPC_A ipPC_V ip_R pSSH

# Функция загрузки скрипта
load_script() {
    local script_path="$1"
    if [[ -f "$script_path" ]]; then
        . "$script_path"
    else
        echo "❌ Ошибка: файл '$script_path' не найден."
        exit 1
    fi
}

# Подключаем модули
load_script "$MODULES_DIR/Vikl_kolonku.sh"
load_script "$MODULES_DIR/VNC_na_3_PC.sh"
load_script "$MODULES_DIR/Wi-Fi.sh"
load_script "$MODULES_DIR/zapusk_programm.sh"
load_script "$MODULES_DIR/Vikl_PC.sh"
load_script "$MODULES_DIR/VKL_PC.sh"
load_script "$MODULES_DIR/Televizor.sh"
load_script "$MODULES_DIR/Poslat_message_win.sh"  # <-- новый модуль

# Список обязательных функций
required_functions=(
    vikl_kolonku
    Vibor_PC_VNC
    vkl_wifi
    Zapusk_Programm
    Vibor_PC_Vikl
    Vibor_PC_Vkl
    vkl_televizor
    Poslat_message_win  # <-- новая функция
)

for func in "${required_functions[@]}"; do
    if ! declare -f "$func" >/dev/null 2>&1; then
        echo "❌ Ошибка: функция '$func' не определена (проверьте подключаемые файлы)."
        exit 1
    fi
done

# Главное меню
show_menu() {
    local BLUE GREEN YELLOW NC
    BLUE=$(printf '\033[1;34m')
    GREEN=$(printf '\033[1;32m')
    YELLOW=$(printf '\033[1;33m')
    NC=$(printf '\033[0m')

    clear
    printf '%s\n' \
        "" \
        "${BLUE}+--------------------------------------------+${NC}" \
        "${BLUE}|${NC}        ${GREEN}Добро пожаловать в скрипт!${NC}         ${BLUE}|${NC}" \
        "${BLUE}|${NC}    Управление компьютерами и устройствами   ${BLUE}|${NC}" \
        "${BLUE}+--------------------------------------------+${NC}" \
        "${BLUE}|${NC} ${YELLOW}1${NC}) VNC на ПК                           ${BLUE}|${NC}" \
        "${BLUE}|${NC} ${YELLOW}2${NC}) Включить Wi-Fi на время            ${BLUE}|${NC}" \
        "${BLUE}|${NC} ${YELLOW}3${NC}) Запустить ПРОГРАММУ                 ${BLUE}|${NC}" \
        "${BLUE}|${NC} ${YELLOW}4${NC}) Послать сообщение                   ${BLUE}|${NC}" \
        "${BLUE}|${NC} ${YELLOW}5${NC}) ВЫКЛючить ПК                        ${BLUE}|${NC}" \
        "${BLUE}|${NC} ${YELLOW}6${NC}) ВКЛючить ПК                         ${BLUE}|${NC}" \
        "${BLUE}|${NC} ${YELLOW}7${NC}) Включить ТЕЛЕВИЗОР                 ${BLUE}|${NC}" \
        "${BLUE}|${NC} ${YELLOW}8${NC}) On/Off Колонка                     ${BLUE}|${NC}" \
        "${BLUE}|${NC} ${YELLOW}9${NC}) Выход                              ${BLUE}|${NC}" \
        "${BLUE}+--------------------------------------------+${NC}" \
        ""
}

# Основной цикл
while true; do
    show_menu
    read -rp "Выберите пункт [1–9]: " MENU_OPTION

    case $MENU_OPTION in
        1) echo -e "\n🚀 VNC на ПК"; Vibor_PC_VNC ;;
        2) echo -e "\n📡 Включить Wi-Fi на определённое время"; vkl_wifi ;;
        3) echo -e "\n▶️  Запуск программы"; Zapusk_Programm ;;
        4) echo -e "\n💬 Отправка сообщения на Windows"; Poslat_message_win ;;
        5) echo -e "\n🛑 Выключение ПК"; Vibor_PC_Vikl ;;
        6) echo -e "\n🟢 Включение ПК"; Vibor_PC_Vkl ;;
        7) echo -e "\n📺 Включение ТЕЛЕВИЗОРА"; vkl_televizor ;;
        8) echo -e "\n🔊 Включение/выключение колонки"; vikl_kolonku ;;
        9) echo -e "\n👋 До свидания!"; exit 0 ;;
        *)
            echo -e "\n❗ Неверный выбор. Введите число от 1 до 9."
            sleep 1.5
            ;;
    esac

    echo -e "\nНажмите Enter для возврата в меню..."
    read -r
done
