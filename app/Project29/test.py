freq_code = "ACc"
frg_num = "1~2~3"
frq = list(map(int, frg_num.split("~")))
list_seg_code = ""
for i in range(len(freq_code)):
    for j in range(frq[i]):
        list_seg_code += freq_code[i]

print(list_seg_code)