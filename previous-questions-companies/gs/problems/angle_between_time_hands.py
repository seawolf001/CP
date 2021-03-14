

def calc_angle(time):
    h, m = map(int, time.split(":"))
    if h < 0 or m < 0 or h > 24 or m > 60:
        raise Exception('Invalid Input')
    if h > 12:
        h = h % 12
    elif h == 12:
        h = 0
    if m == 60:
        m = 0
    hr_angle = (360 / ( 12 * 60 ) ) * ( h * 60 + m )
    minutes_angle = (360 / 60) * m
    diff = abs(hr_angle - minutes_angle)
    return min(360 - diff, diff)

def tests():
    assert calc_angle('3:10') == 35.0

if __name__ == '__main__':
    tests()
    print(calc_angle('9:30'))
