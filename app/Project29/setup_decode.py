import subprocess

def edit(name_text,name_code):
    with open("main_decode.cpp", "r") as f:
        lines = f.readlines()

    # fileName_kh = fileName_kh.replace('/', '\\\\')
    # fileName_cg = fileName_cg.replace('/', '\\\\')
    # fileName_kq = fileName_kq.replace('/', '\\\\')

    lines[7] = '    string text="' + name_text + '";\n'
    lines[8] = '    string text_encode = "' + name_code + '";\n'
    with open("main_decode.cpp", "w") as f:
        f.writelines(lines)


def complie():
    subprocess.call("g++ -o main_decode main_decode.cpp", shell=True)

def run():
    execute_command = "main_decode"
    execute_process = subprocess.Popen(execute_command, shell=True)
    execute_process.wait()