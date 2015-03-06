CONFIG -= console
CONFIG -= app_bundle
CONFIG -= qt

system(python ../../../../test/test_calc.py)
OTHER_FILES += ../../../../test/test_calc.py
