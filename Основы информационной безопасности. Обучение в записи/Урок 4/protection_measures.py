first_line = 'код меры защиты\tнаименование меры защиты\tколичество баллов\n'
freq_dict = dict()
with open('Меры защиты.txt') as fl:
    for line in fl:
        kod = line.strip().split()[0]
        name = line.lstrip(kod).strip()
        freq_dict[kod] = freq_dict.get(kod, [0, name])
        freq_dict[kod][0] += 1

lst = sorted(freq_dict.items(), key=lambda item: item[1][0], reverse=True)

with open('result.csv', 'w') as fl:
    fl.writelines(first_line)
    for line in lst:
        csv_line = line[0] + '\t' + line[1][1] + '\t' + str(line[1][0]) + '\n'
        fl.writelines(csv_line)

