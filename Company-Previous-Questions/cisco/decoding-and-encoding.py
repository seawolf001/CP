

def b32_to_binary(string):
    binary = ""
    for char in string:
        x = ord(char)
        x = bin(x)[-5:]
        print(chr(int(x,2)))
        binary += x
    return binary


def binary_to_b64(binary):
    b64 = ""
    for i in range(len(binary)):
        #  import pdb;pdb.set_trace()
        x = binary[i:i+6]
        x = int(x,2)
        b64 += chr(x)
        i += 6

def b32_to_b64(string):
    binary = b32_to_binary(string)
    return binary_to_b64(binary)

if __name__ == '__main__':
    N = int(input())
    for x in range(N):
        b32 = input()
        print (b32_to_b64(b32))

