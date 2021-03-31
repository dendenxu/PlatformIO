import numpy
import serial.serialwin32 as serwin32
for i in range(0, 10):
    try:
        ser = serwin32.Serial("com"+str(i), 115200, timeout=0.5)
        break
    except BaseException:
        pass
N_ROW = 2
N_COL = 3
dist_mesh = numpy.zeros([N_ROW, N_COL])
count = 0
while True:
    string = ser.readline().decode("gbk")
    if string == "Too Far or Too Close!\r\n":
        continue
    try:
        index = int(string.split(" ")[0])
        dist = float(string.split(" ")[1])
        dist_mesh[index//N_ROW][index % N_ROW] = dist
        if index == 5:
            count += 1
        # Debugging information is printed here
        print(dist_mesh)
    except BaseException:
        continue
