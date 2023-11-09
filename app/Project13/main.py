import sys
import time
import webbrowser

import setupinfo as st

from PyQt5.QtWidgets import QApplication, QMainWindow, QFileDialog
from home import Ui_MainWindow  # home là tên module chứa giao diện của bạn
import messagebox

app = QApplication(sys.argv)
MainWindow = QMainWindow()


def run():
    global ui
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    ui.chontep_kh.clicked.connect(open_file_dialog_kh)
    ui.chontep_cg.clicked.connect(open_file_dialog_cg)
    ui.chontep_kq.clicked.connect(open_file_dialog_kq)
    ui.help.clicked.connect(open_help)
    ui.ktratiencuoc.clicked.connect(ktratiencuoc)
    ui.tongphutgoi.clicked.connect(tongphutgoi)
    ui.tkadt.clicked.connect(tkadt)
    ui.More.clicked.connect(open_more)
    MainWindow.show()

def open_more():
    import more
    global ui_more
    ui_more = more.Ui_MainWindow()
    ui_more.setupUi(MainWindow)
    ui_more.pushButton_2.clicked.connect(run)
    ui_more.pushButton.clicked.connect(lambda : webbrowser.open('https://github.com/hoangmanhkhiem'))
    ui_more.pushButton_3.clicked.connect(lambda : webbrowser.open('https://www.facebook.com/hoangmanhkhiem.IT'))

def tkadt():
    checking_file()
    fileName_kh = ui.path_khachhang.text()
    fileName_cg = ui.path_cuocgoi.text()
    fileName_kq = ui.path_ketqua.text()
    luachon = '1'
    st.edit(fileName_kh, fileName_cg, fileName_kq, luachon)
    st.complie()
    st.run()
    messagebox.showinfo("Info", "Đã thống kê xong, vui lòng xem kết quả trong tệp thống kê")
    ui.path_khachhang.setText(fileName_kh)
    ui.path_cuocgoi.setText(fileName_cg)
    ui.path_ketqua.setText(fileName_kq)

def tongphutgoi():
    fileName_kh = ui.path_khachhang.text()
    fileName_cg = ui.path_cuocgoi.text()
    fileName_kq = ui.path_ketqua.text()
    if checking_file() != -1:
        if checking_sdt_input2() != -1:
            if fileName_kq == '':
                fileName_kq = 'output/ketqua.txt'
            sdt = ui.hovaten_2.text()
            luachon = '2'
            st.edit(fileName_kh, fileName_cg, fileName_kq,luachon,namecheck=sdt)
            st.complie()
            st.run()
            with open("log_time.txt", "r") as f:
                lines = f.readlines()
            name1 = lines[0]
            time1 = lines[1]
            if "Not found" in name1:
                messagebox.showinfo("Info", "SDT: " + sdt + "\nKhông tồn tại trên CSDL")
            else:
                messagebox.showinfo("Info", "Khách hàng: " + name1 + "SDT: " + sdt + "\nSố phút gọi: " + time1)
    ui.path_khachhang.setText(fileName_kh)
    ui.path_cuocgoi.setText(fileName_cg)
    ui.path_ketqua.setText(fileName_kq)
    ui.hovaten_2.setText('')

def ktratiencuoc():
    fileName_kh = ui.path_khachhang.text()
    fileName_cg = ui.path_cuocgoi.text()
    fileName_kq = ui.path_ketqua.text()
    if checking_file() != -1:
        if checking_sdt_input1() != -1:
            if fileName_kq == '':
                fileName_kq = 'output/ketqua.txt'
            luachon = '3'
            sdt = ui.hovaten.text()
            st.edit(fileName_kh, fileName_cg, fileName_kq, luachon,namecheck=sdt)
            st.complie()
            st.run()
            with open("log_cuoc.txt", "r") as f:
                lines = f.readlines()
            name1 = lines[0]
            time1 = lines[1]
            if "Not found" in name1:
                messagebox.showinfo("Info", "SDT: " + sdt + "\nKhông tồn tại trên CSDL")
            else:
                messagebox.showinfo("Info", "Khách hàng: " + name1 + "SDT: " + sdt + "\nTổng cước: " + time1)
    ui.path_khachhang.setText(fileName_kh)
    ui.path_cuocgoi.setText(fileName_cg)
    ui.path_ketqua.setText(fileName_kq)
    ui.hovaten.setText('')

def checking_file():
    if ui.path_khachhang.text() == '' and ui.path_cuocgoi.text() == '':
        messagebox.showerror("Error", "Bạn chưa chọn tệp khách hàng và tệp cuộc gọi")
        return -1
    if ui.path_khachhang.text() == '':
        messagebox.showerror("Error", "Bạn chưa chọn tệp khách hàng")
        return -1
    if ui.path_cuocgoi.text() == '':
        messagebox.showerror("Error", "Bạn chưa chọn tệp cuộc gọi")
        return -1
    if ui.path_ketqua.text() == '':
        messagebox.showinfo("Thông báo", "tệp kết quả sẽ được lưu vào đường dẫn dưới đây\n" + "output/ketqua.txt")
        return 1

kc_sdt = ['0','1','2', '3', '4', '5', '6', '7', '8', '9']

def checking_sdt_input1():
    if ui.hovaten.text() == '':
        messagebox.showerror("Error", "Bạn chưa nhập SDT")
        return -1
    # Viết hàm kiểm tra só điện thoại đúng định dạng
    sdt1 = ui.hovaten.text()
    if len(sdt1)!=10 or sdt1[0]!="0" or all(x in kc_sdt for x in sdt1) == False:
        messagebox.showerror("Error", "Số điện thoại không đúng định dạng")
        return -1

def checking_sdt_input2():
    if ui.hovaten_2.text() == '':
        messagebox.showerror("Error", "Bạn chưa nhập SDT")
        return -1
    sdt2 = ui.hovaten_2.text()
    if len(sdt2)!=10 or sdt2[0]!="0" or all(x in kc_sdt for x in sdt2) == False:
        messagebox.showerror("Error", "Số điện thoại không đúng định dạng")
        return -1
def open_help():
    messagebox.showinfo("Help", "Author: Hoang Manh Khiem \nNickName: SKromnyy ")

def open_file_dialog_kh():
    options = QFileDialog.Options()
    default_directory = 'data/'
    file_path, _ = QFileDialog.getOpenFileName(MainWindow, 'Chọn tệp', default_directory, 'All Files (*)', options=options)

    if file_path:
        ui.path_khachhang.setText(file_path)
    else:
        ui.path_khachhang.setText('')

def open_file_dialog_cg():
    options = QFileDialog.Options()
    default_directory = 'data/'
    file_path, _ = QFileDialog.getOpenFileName(MainWindow, 'Chọn tệp', default_directory, 'All Files (*)', options=options)

    if file_path:
        ui.path_cuocgoi.setText(file_path)
    else:
        ui.path_cuocgoi.setText('')

def open_file_dialog_kq():
    options = QFileDialog.Options()
    file_path, _ = QFileDialog.getOpenFileName(MainWindow, 'Chọn tệp', '', 'All Files (*)', options=options)

    if file_path:
        ui.path_ketqua.setText(file_path)
    else:
        ui.path_ketqua.setText('')


if __name__ == '__main__':
    run()
    sys.exit(app.exec_())
