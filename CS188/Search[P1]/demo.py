e = 1
import util

def d(a = 1):
    global b
    b = 2
    import pdb; pdb.set_trace()
    print(globals())
    util.raiseNotDefined()
def main():
    c = 3
    f = input('Input')
    d(1)
if __name__ == '__main__':
    dd = 1
    main()