
import time
from pyduino import Arduino

a = Arduino()
time.sleep(3)

# set arduino pins manually
a.set_pin_mode(13,'O')
a.set_pin_mode(14,'I')


# get command from user
# Do sth with that command

while True:
    user_cmd = input("Enter your command: ")

    if user_cmd == 'read':
        print(a.analog_read(14))
    elif user_cmd == 'write':
        cmd = input("1 or 0 ? ")
        a.digital_write(13,int(cmd))













