#!/usr/bin/env python

import RPi.GPIO as GPIO
import time
import subprocess

SHUTDOWN_PIN = 3
LONG_PRESS_TIME_IN_SECONDS = 2.0

GPIO.setmode(GPIO.BCM)
GPIO.setup(SHUTDOWN_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)


GPIO.wait_for_edge(SHUTDOWN_PIN, GPIO.FALLING)
buttonPressStart = time.time()

GPIO.wait_for_edge(SHUTDOWN_PIN, GPIO.RISING)
buttonPressedTime = time.time() - buttonPressStart

GPIO.cleanup()

if LONG_PRESS_TIME_IN_SECONDS > buttonPressedTime:
  subprocess.call(["shutdown", "-h", "now"])
else:
  subprocess.call(["shutdown", "-r", "now"])