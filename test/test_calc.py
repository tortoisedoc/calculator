import os
import subprocess
import logging
from  unittest import TestCase
from  unittest import main


class AcceptanceTests(TestCase):

    def __init__(self, arg):
        TestCase.__init__(self, arg)
        logging.basicConfig(level=logging.DEBUG, format=' %(levelname)s : %(asctime)s : %(message)s')
        self.base_dir = os.path.dirname(os.path.realpath(__file__))
        self.exe_path = os.path.join (self.base_dir, "../bin/Debug/calc.exe")
        
    def __send_process_command (self, _cmd):
        logging.debug ("Sending %s ...." % _cmd)
        cmd_result = self.process_pipe.communicate(input=b"%s\x04" % _cmd)[0]
        logging.debug (" -----> Result %s" % cmd_result)
        return cmd_result
        
    def __start_process_stub(self):
        try:
            self.process_pipe = subprocess.Popen(self.exe_path, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        except:
            logging.error (" ERROR : Test exe not found (%s) " % self.exe_path)
            raise
        
    def setUp(self):
        self.assert_(os.path.exists(self.exe_path), "ERROR : TEST TARGET NOT FOUND : %s " %self.exe_path)
        logging.debug ("Setup process.. %s " % self.exe_path)
        self.__start_process_stub()
        
    def assertTestSuccess(self, test_result, expected_val):
        self.assertEqual(test_result, expected_val, " ERROR : MULTIPLICATION RESULT IS NOT AS EXPECTED (16): %s" % test_result)
    
    def test_multiplication(self):
        test_result = self.__send_process_command("4*4")
        self.assertTestSuccess(test_result, "16")
            
    def test_addition(self):
        test_result = self.__send_process_command("4+4")
        self.assertTestSuccess(test_result, "8")
            
    def test_subtraction(self):
        test_result = self.__send_process_command("8-3")
        self.assertTestSuccess(test_result, "5")

    def test_division(self):
        test_result = self.__send_process_command("12/4")
        self.assertEqual(test_result, "3")
    
    def test_composite(self):
        test_result = self.__send_process_command("3+3*(12/4)")
        self.assertEqual(test_result, "12")    
        
if __name__ == '__main__':
    main()