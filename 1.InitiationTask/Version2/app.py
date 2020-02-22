
import serial, time
from flask import Flask, render_template, request


app = Flask(__name__)

ser = serial.Serial('COM5', 9600)


@app.route('/', methods=['GET', 'POST'])
def home():
    if request.method == 'POST':
        if "TURN_ON" in request.form:
            ser.write('1'.encode())
            print("TURN_ON")
        elif "TURN_OFF" in request.form:
            ser.write('0'.encode())
            print("TURN_OFF")
        elif "READ" in request.form:
            ser.write('R'.encode())
            while ser.inWaiting:
                return str(ser.readline())
    return render_template("control.html")


if __name__ == "__main__":
    app.run(host="0.0.0.0", debug=True)