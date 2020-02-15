
import serial, time
from flask import Flask, render_template, request
# from pyduino import Arduino


app = Flask(__name__)

rawdata=[]

sensor_pin = 14
led_pin = 13

# pydata = Arduino()
# time.sleep(2)

# pydata.set_pin_mode(sensor_pin,'I')
# pydata.set_pin_mode(led_pin,'O')
# time.sleep(1)

# pydata.digital_write(led_pin,0) 


@app.route('/', methods=['GET', 'POST'])
def home():
    if request.method == 'POST':
        print(request.form)
        print(type(request.form))
        if "TURN_ON" in request.form:
            pydata.digital_write(led_pin,1)  
            print("TURN_ON")
        elif "TURN_OFF" in request.form:
            pydata.digital_write(led_pin,0) 
            print("TURN_OFF")
        elif "READ" in request.form:
            print(pydata.analog_read(sensor_pin))
            data = pydata.analog_read(sensor_pin)
            print(type(data))
    return render_template("control.html")



if __name__ == "__main__":
    app.run(host="0.0.0.0")