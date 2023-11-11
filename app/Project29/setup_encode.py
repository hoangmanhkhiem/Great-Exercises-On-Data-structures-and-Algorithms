import subprocess


def edit(name_text):
    with open("main_encode.cpp", "r") as f:
        lines = f.readlines()

    # fileName_kh = fileName_kh.replace('/', '\\\\')
    # fileName_cg = fileName_cg.replace('/', '\\\\')
    # fileName_kq = fileName_kq.replace('/', '\\\\')

    lines[6] = '    string text="' + name_text + '";\n'
    with open("main_encode.cpp", "w") as f:
        f.writelines(lines)


def complie():
    subprocess.call("g++ -o main_encode main_encode.cpp", shell=True)


def run():
    execute_command = "main_encode"
    execute_process = subprocess.Popen(execute_command, shell=True)
    execute_process.wait()