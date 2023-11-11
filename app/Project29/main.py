import webbrowser

from home import Ui_MainWindow
import messagebox
import sys
import encode, decode
import setup_encode, setup_decode

from PyQt5.QtWidgets import QApplication, QMainWindow, QFileDialog

app = QApplication(sys.argv)
MainWindow = QMainWindow()


def menu():
    global ui
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)

    ui.pushButton.clicked.connect(menu_encode.home)
    ui.pushButton_2.clicked.connect(menu_decode.home)
    ui.pushButton_3.clicked.connect(open_more)

    MainWindow.show()

def open_more():
    import more
    global ui_more
    ui_more = more.Ui_MainWindow()
    ui_more.setupUi(MainWindow)
    ui_more.pushButton_2.clicked.connect(menu)
    ui_more.pushButton.clicked.connect(lambda : webbrowser.open('https://github.com/hoangmanhkhiem'))
    ui_more.pushButton_3.clicked.connect(lambda : webbrowser.open('https://www.facebook.com/hoangmanhkhiem.IT'))

class menu_encode(object):
    def home(self):
        global ui_encode
        ui_encode = encode.Ui_MainWindow()
        ui_encode.setupUi(MainWindow)

        ui_encode.pushButton.clicked.connect(menu_encode.encode_run)
        ui_encode.pushButton1.clicked.connect(menu)

        MainWindow.show()

    def encode_run(self):
        text = ui_encode.input.toPlainText()
        if text == "":
            messagebox.showerror("Error", "Bạn chưa nhập dữ liệu cần mã hóa")
            return
        setup_encode.edit(text)
        setup_encode.complie()
        setup_encode.run()
        with open("output.txt", "r") as f:
            lines = f.readlines()
        ui_encode.out.setText(lines[0])


class menu_decode(object):
    def home(self):
        global ui_decode
        ui_decode = decode.Ui_MainWindow()
        ui_decode.setupUi(MainWindow)

        ui_decode.pushButton.clicked.connect(menu_decode.decode_run)
        ui_decode.pushButton1.clicked.connect(menu)

        MainWindow.show()

    def decode_run(self):
        text_code = ui_decode.input.toPlainText()
        if ("1" or "0") not in text_code:
            messagebox.showerror("Error", "Bạn đã nhập sai dữ liệu")
            return
        freq_code = ui_decode.freq.text()
        seg_code = ui_decode.code.text()
        frq = list(map(int, freq_code.split("~")))
        if len(frq) != len(seg_code):
            messagebox.showerror("Error", "Bạn đã nhập thiếu ở phần tần số hoặc mã")
            return
        if text_code == "":
            messagebox.showerror("Error", "Bạn chưa nhập dữ liệu cần giải mã")
            return
        list_seg_code = ""
        for i in range(len(seg_code)):
            for j in range(frq[i]):
                list_seg_code += seg_code[i]
        setup_decode.edit(list_seg_code, text_code)
        setup_decode.complie()
        setup_decode.run()
        with open("output.txt", "r") as f:
            lines = f.readlines()
        ui_decode.out.setText(lines[0])


menu()
sys.exit(app.exec_())
