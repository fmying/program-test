'''
Test for python file operation
'''
fp=open(file="d:/test.txt",mode='w+')
context="This is a test.\nTest 2"
fp.write(context)
fp.close()

fp=open(file="d:/test.txt",mode="r+")
content=fp.readline()
while content:
    print(content)
    content=fp.readline()
fp.close()

fp=open("d:/test.txt","r")
content=fp.readlines()
print(content)
print(type(content))
print(len(content))
fp.seek(0,0)
for line in fp:
    print(line)
fp.close()
