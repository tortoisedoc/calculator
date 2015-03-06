CONFIG -= console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG(release, release|debug){
    message(run test cases on RELEASE build)
    system(python ../../../../test/test_calc.py)
}else:{
    message(run test cases on DEBUG build)
    system(python ../../../../test/test_calc.py debug)
}

OTHER_FILES += ../../../../test/test_calc.py
