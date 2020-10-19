import math
import sys

dane_we = list()
d=0
pd=0
md=0
z = list()
dana1 = int(input())
dana2 = int(input())
dana3 = int(input())
dane_we.append(dana1)
dane_we.append(dana2)
dane_we.append(dana3)
z.append(0)
z.append(0)
z.append(0)
z.append(0)
z.append(0)
z.append(0)


if (dane_we[0] != 1 and dane_we[0] != 0 and dane_we[0] != -1):
    sys.stdout.write(dane_we[0])

if (dane_we[0] != 0):
    if (dane_we[0] == -1):
        sys.stdout.write("-")
    sys.stdout.write("xx")
    if (dane_we[1] > 0):
        sys.stdout.write("+")

if (dane_we[1] != 1 and dane_we[1] != 0 and dane_we[1] != -1):
    sys.stdout.write(dane_we[1])

if (dane_we[1] != 0):
    if (dane_we[1] == -1):
        sys.stdout.write("-")
    sys.stdout.write("x")
    if (dane_we[2] > 0):
        sys.stdout.write("+")

if (dane_we[2] != 0):
    sys.stdout.write(dane_we[2])
if (dane_we[0] == 0 and dane_we[1] == 0 and dane_we[2] == 0):
    sys.stdout.write('0')

sys.stdout.write("=0")
print('')


if (dane_we[0] != 0):
    d = (dane_we[1] * dane_we[1]) - (4 * dane_we[0] * dane_we[2])
    sys.stdout.write("d=")
    sys.stdout.write(d)


if (dane_we[0] != 0):
    if (d > 0):
        z[0] = ((-dane_we[1] * 1.0) - math.sqrt(d)) / (2 * (dane_we[0] * 1.0))
        sys.stdout.write("x1v=")
        sys.stdout.write(z[0].real)
        z[1] = (((-dane_we[1] * 1.0) + math.sqrt(d)) * 1.0) / ((2 * (dane_we[0] * 1.0)) * 1.0)
        print('')
        sys.stdout.write("x2v=")
        sys.stdout.write(z[1].real)
        print('')

    if (d == 0):
        z[0] = (-dane_we[1] * 1.0) / ((2 * (dane_we[0] * 1.0)) * 1.0)
        sys.stdout.write("x1v=")
        sys.stdout.write(z[0].real)
        print('')

    if (d < 0):
        z[0] = (-dane_we[1] * 1.0) / ((2 * dane_we[0]) * 1.0)
        z[1] = z[0]
        c1 = complex(z[0].real, (math.sqrt(math.fabs(d))) / (2 * (dane_we[0] * 1.0)))
        z[0] = c1
        c1 = complex(z[1].real, -z[0].imag)
        z[1] = c1
        print('')

if (dane_we[0] == 0 and dane_we[1] != 0):
    x1v = ((-dane_we[2] * 1.0) / (dane_we[1] * 1.0))
    z[0] = x1v
    sys.stdout.write("x1v=")
    sys.stdout.write(z[0].real)
    print('')

if (dane_we[0] == 0 and dane_we[1] == 0 and dane_we[2] != 0):
    sys.stdout.write("Rownanie sprzeczne")
    print('')

if (dane_we[0] == 0 and dane_we[1] == 0 and dane_we[2] == 0):
    sys.stdout.write("Rownanie tozsamosciowe")
    print('')

if (d < 0):
    sys.stdout.write("z1=")
    sys.stdout.write(z[0].real)
    if (z[0].imag >= 0):
        sys.stdout.write("+")
    if (z[0].imag == -1):
        sys.stdout.write("-")
    if (z[0].imag != 1 and z[0].imag != -1 and z[0].imag != 0):
        sys.stdout.write(z[0].imag)
    if (z[0].imag != 0):
        sys.stdout.write("*")

    sys.stdout.write("i")
    print('')
    sys.stdout.write("z2=")
    sys.stdout.write(z[1].real)
    if (z[1].imag >= 0):
        sys.stdout.write("+")
    if (z[1].imag == -1):
        sys.stdout.write("-")
    if (z[1].imag != 1 and z[1].imag != -1 and z[1].imag != 0):
        sys.stdout.write(z[1].imag)
    if (z[1].imag != 0):
        sys.stdout.write("*")
    sys.stdout.write("i")
    print('')

if(d > 0):
    t1 = 0
    t2 = 1
    if (t1 != t2):
        t1 = t2
        t2 = (t1 + math.fabs(d) / t1) / 2

    if (t1 != t2):
        t1 = t2
        t2 = (t1 + math.fabs(d) / t1) / 2

    if (t1 != t2):
        t1 = t2
        t2 = (t1 + math.fabs(d) / t1) / 2

    if (t1 != t2):
        t1 = t2
        t2 = (t1 + math.fabs(d) / t1) / 2

    if (t1 != t2):
        t1 = t2
        t2 = (t1 + math.fabs(d) / t1) / 2

    if (t1 != t2):
        t1 = t2
        t2 = (t1 + math.fabs(d) / t1) / 2
        sys.stdout.write("sqrt(d)=")
        sys.stdout.write(math.sqrt(math.fabs(d)))
        print('')
        sys.stdout.write("my_sqrt(d)=")
        sys.stdout.write(t2)
        print('')
    if (t2 - math.sqrt(math.fabs(d)) < 0.000000001):
        sys.stdout.write("my_sqrt(d)-sqrt(d)=")
        sys.stdout.write(0)
        print('')
    else:
        sys.stdout.write("my_sqrt(d)-math.sqrt(d)=")
        sys.stdout.write(t2 - math.sqrt(math.fabs(d)))
        print('')

if (d > 0):
    z[2] = z[0] + z[1]

if (d < 0):
    z[2] = z[0] + z[1]
    c1 = complex(z[2].real, z[0].imag + z[1].imag)
    z[2] = c1

if (d > 0):
    z[3] = z[0] - z[1]

if (d < 0):
    z[3] = z[0] - z[1]
    c1 = complex(z[3].real, z[0].imag - z[1].imag)
    z[3] = c1

if (d > 0):
    z[4] = (z[0]) * (z[1])

if (d < 0):
    z[4] = (z[0].real) * (z[1].real) - (z[0].imag) * (z[1].imag)
    c1 = complex(z[4].real,(z[0].real) * (z[1].imag) + (z[0].real) * (z[1].imag))
    z[4] = c1

if (d > 0):
    if (z[1].real != 0):
        z[5] = (z[0]) / (z[1])

    if (d < 0):
        z[5] = ((z[0].real) * (z[1].real) + (z[0].imag) * (z[1].imag)) / (((z[1].real) * (z[1].real)) + ((z[1].imag) * (z[1].imag)))
        c1 = complex(z[5].real,(z[0].real) * (z[1].imag) - (z[0].imag) * (z[1].imag)) / (((z[1].real) * (z[1].real)) + ((z[1].imag) * (z[1].imag)))
        z[5] = c1

if (dane_we[0] != 0):
    if (d > 0):
        sys.stdout.write("sv=")
        sys.stdout.write(z[2].real)
        print('')
        sys.stdout.write("rv=")
        sys.stdout.write(z[3].real)
        print('')
        sys.stdout.write("ilv=")
        sys.stdout.write(z[4].real)
        print('')
        sys.stdout.write("irv=")
        sys.stdout.write(z[5].real)
        print('')

    if (d < 0):
        sys.stdout.write("sv=")
        sys.stdout.write(z[2].real)
        print('')
        sys.stdout.write("sn=")
        sys.stdout.write(z[2].imag)
        print('')
        sys.stdout.write("rv=")
        sys.stdout.write(z[3].real)
        print('')
        sys.stdout.write("rn=")
        sys.stdout.write(z[3].imag)
        print('')
        sys.stdout.write("ilv=")
        sys.stdout.write(z[4].real)
        print('')
        sys.stdout.write("iln=")
        sys.stdout.write(z[4].imag)
        print('')
        sys.stdout.write("irv=")
        sys.stdout.write(z[5].real)
        print('')
        sys.stdout.write("irn=")
        sys.stdout.write(z[5].imag)
        print('')

md = math.sqrt(math.fabs((z[0].real * z[0].real) + ((z[0].imag) * (z[0].imag))))
sys.stdout.write("md=")
sys.stdout.write(md)
print('')

