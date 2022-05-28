import sys

usr = open("user_out", "r")
code = open("code", "r")

code = code.read()
code = code.replace('\r\n', '\n')

if len(code) < 10:
	print(0)
	sys.exit(0)

outcode = usr.read()
outcode = outcode.replace('\r\n', '\n')

if outcode == code:
	print(100)
else:
	print(0)
