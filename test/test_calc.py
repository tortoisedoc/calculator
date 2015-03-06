import os
import subprocess
import logging
from  unittest import TestCase
from  unittest import main

class BaseTest (TestCase):

    def __init__(self, arg):
        TestCase.__init__(self, arg)
        logging.basicConfig(level=logging.DEBUG, format=' %(levelname)s : %(asctime)s : %(message)s')
        self.base_dir = os.path.dirname(os.path.realpath(__file__))
        self.exe_path = os.path.join (self.base_dir, "../bin/qtcreator/debug/app/calc")

    def __send_process_command (self, _cmd):
        logging.debug ("Sending %s ...." % _cmd)
        cmd_result = self.process_pipe.communicate(input=b"%s\n" % _cmd)[0]
        logging.debug (" -----> Result %s" % str(cmd_result))
        return cmd_result.rstrip("\n")

    def __start_process_stub(self):
        try:
            self.process_pipe = subprocess.Popen(self.exe_path, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            logging.debug(" Process %s started, PID is %s" % (self.exe_path, self.process_pipe.pid))
        except:
            logging.error (" ERROR : Test exe not found (%s) " % self.exe_path)
            raise

    def setUp(self):
        self.assert_(os.path.exists(self.exe_path), "ERROR : TEST TARGET NOT FOUND : %s " %self.exe_path)
        logging.debug ("Setup process.. %s " % self.exe_path)
        self.__start_process_stub()

    def assertTestSuccess(self, test_result, expected_val):
        self.assertEqual(test_result, expected_val, " ERROR : RESULT IS NOT AS EXPECTED (%s): %s" % (expected_val, test_result))

    def execute_test (self, input, expected_result):
        test_result = self.__send_process_command(input)
        self.assertEqual(test_result, expected_result)

class FunctionalTests(BaseTest):

    def test_multiplication(self):
        self.execute_test("4*4", "16")
            
    def test_addition(self):
        self.execute_test("4+4", "8")
            
    def test_subtraction(self):
        self.execute_test("8-3", "5")

    def test_division(self):
        self.execute_test("12/4", "3")
    
    def test_division_round_down(self):
        self.execute_test("8/3", "2")

    def test_division_negative_round_down(self):
        self.execute_test("-8/3", "-3")

    def test_division(self):
        self.execute_test("12%7", "5")

    def test_composite(self):
        self.execute_test("3+3*(12/4)", "12")



class AcceptanceTests(BaseTest):

    def test_a(self):
        self.execute_test("(1+3)*(9/3)", "12")

    def test_b(self):
        self.execute_test("0-123", "-123")

if __name__ == '__main__':
    main()
