"""   Задание
Написать программу на Python, которая будет проводить сканирование с использованием nmap.
"""

# Замечание 1. nmap лучше работает под рутом поэтому
# Замечание 2. библиотеку python-nmap лучше ставить в виртуальное окружение
# sudo su
# python3 -m venv venv
# source venv/bin/activate
# pip install python-nmaр
# python ./main.py
# deactivate
# exit

import nmap

# Параметры сканирования
ip_range = '192.168.1.1'   #'192.168.1.0/24'
ports = '1-1024'
arguments = '-sS'

# Создаем сканер
nm = nmap.PortScanner()

# Сканируем
nm.scan(hosts=ip_range, ports=ports, arguments=arguments)

# Выводим результат
for host in nm.all_hosts():
    print(f'Хост : {host} ({nm[host].hostname()})')
    print(f'Статус : {nm[host].state()}')
    for proto in nm[host].all_protocols():
        print(f'Протокол : {proto}')
        lport = nm[host][proto].keys()
        sorted(lport)
        for port in lport:
            print(f'Порт : {port}\tСтатус : {nm[host][proto][port]["state"]}')
