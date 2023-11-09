import subprocess


def edit(fileName_kh, fileName_cg, fileName_kq,luachon, namecheck=""):
    with open("main.cpp", "r") as f:
        lines = f.readlines()

    # fileName_kh = fileName_kh.replace('/', '\\\\')
    # fileName_cg = fileName_cg.replace('/', '\\\\')
    # fileName_kq = fileName_kq.replace('/', '\\\\')

    lines[7] = '    sys.set_fileName_kh("' + fileName_kh + '");' + '\n'
    lines[8] = '    sys.set_fileName_cg("' + fileName_cg + '");' + '\n'
    lines[9] = '    sys.set_fileName_kq("' + fileName_kq + '");' + '\n'
    lines[10] = '    int option = ' + luachon + ';' + '\n'
    lines[11] = '    string nameChecking = "' + namecheck + '";' + '\n'
    with open("main.cpp", "w") as f:
        f.writelines(lines)


def complie():
    subprocess.call("g++ -o main main.cpp", shell=True)


def run():
    execute_command = "main"
    execute_process = subprocess.Popen(execute_command, shell=True)
    execute_process.wait()
