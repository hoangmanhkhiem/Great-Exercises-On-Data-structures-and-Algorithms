try:
    from PyQt5 import QtCore, QtGui, QtWidgets
    from PyQt5.QtWidgets import QApplication, QMainWindow, QFileDialog, QPushButton
    import sys
    import webbrowser
    import messagebox
    import subprocess
    import os
except:
    os.system('pip install PyQt5')
    os.system('pip install webbrowser')
    os.system('pip install messagebox')
    os.system('pip install subprocess')


