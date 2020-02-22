
import serial, time
from flask import Flask, render_template, request
from pyduino import Arduino

app = Flask(__name__)

# Pin definitions
sensor_pin = 14
led_pin = 13

pydata = Arduino()
time.sleep(2)

# initialization
pydata.set_pin_mode(sensor_pin,'I')
time.sleep(0.5)
pydata.set_pin_mode(led_pin,'O')
time.sleep(0.5)


@app.route('/', methods=['GET', 'POST'])
def home():
    if request.method == 'POST':
        if "TURN_ON" in request.form:
            pydata.digital_write(led_pin,1) # Turn on Arduino's LED
            print("TURN_ON")
        elif "TURN_OFF" in request.form:
            pydata.digital_write(led_pin,0) # Turn on Arduino's LED
            print("TURN_OFF")
        elif "READ" in request.form:
            return str(pydata.analog_read(14)) # Read Arduino's Sensor data
    return render_template("control.html")


if __name__ == "__main__":
    app.run(host="0.0.0.0", debug=True)