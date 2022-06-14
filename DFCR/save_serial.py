import serial

sensor = "RMS"
serial_port = '/dev/ttyACM0'
baud_rate = 115200
path = f"./{sensor}_LOG_.csv"
ser = serial.Serial(serial_port, baud_rate)
with open(path, 'w+') as f:
    while True:
        line = ser.readline().decode()
        f.writelines([line.strip(), "\n"])