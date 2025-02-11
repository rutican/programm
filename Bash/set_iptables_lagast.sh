

iptables -A INPUT -i lo -j ACCEPT
iptables -A OUTPUT -o lo -j ACCEPT

#Совсем виснет
iptables -A OUTPUT -o ens3 -j ACCEPT

# Разрешить пинги со всех сторон и во все стороны
iptables -A INPUT -p icmp -j ACCEPT
iptables -A OUTPUT -p icmp -j ACCEPT

#DNS
iptables -A INPUT -p tcp -m tcp --dport 53 -j ACCEPT
iptables -A OUTPUT -p tcp -m tcp --dport 53 -j ACCEPT
iptables -A INPUT -p udp -m udp --dport 53 -j ACCEPT
iptables -A OUTPUT -p udp -m udp --dport 53 -j ACCEPT

#Без этого правила начитает заедать, команды выполняются не сразу, подвиснет не некоторое время потом стработает
iptables -A INPUT -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT

# Разницы в правилах нет
#iptables -A INPUT -p tcp --dport 2238 -m conntrack --ctstate NEW,ESTABLISHED -j ACCEPT
iptables -A INPUT -p tcp -m tcp --dport 2238 -j ACCEPT

#==================================================
# для работы сервера HTTP
iptables -A INPUT -p tcp -m tcp --dport 443 -j ACCEPT

# разрешае пересылку с одного интерфейса на другой
# без этого не работало curl ifcomfig.me и выход в инет с ПК
# которые подключались по sstp


iptables -A FORWARD -i ppp+ -o ens3 -j ACCEPT
iptables -A FORWARD -i ens3 -o ppp+ -j ACCEPT
iptables -A FORWARD -i ppp+ -o ppp+ -j ACCEPT

#sstp сам сервер поднимает эти правила
#iptables -I INPUT -p tcp --dport 6951 -m state --state NEW -j ACCEPT
#iptables -I INPUT -p gre -j ACCEPT
#iptables -I POSTROUTING -t nat -o ens3 -j MASQUERADE
#iptables -I FORWARD -p tcp --tcp-flags SYN,RST SYN -s 192.168.10.0/24 -j TCPMSS  --clamp-mss-to-pmtu

# Все остальное убить
iptables -P INPUT DROP
iptables -P FORWARD DROP
iptables -P OUTPUT DROP
