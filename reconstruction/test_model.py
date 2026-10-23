import unittest
from model import demo

class ReconstructionTest(unittest.TestCase):
    def test_behavior_and_failures(self):
        self.assertIsInstance(demo(), dict)

if __name__ == "__main__":
    unittest.main()
