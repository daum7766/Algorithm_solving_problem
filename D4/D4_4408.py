#D4 4408 자기방으로 돌아가기

for t in range(1, int(input()) + 1 ):
    check_list = [0] * 201
    for _ in range(int(input())):
        a, b = map(int, input().split())
        if a > b : a, b = b, a
        a = (a + 1) // 2
        b = (b + 1) // 2
        for i in range(a, b+1):
            check_list[i] += 1
    print('#{} {}'.format(t, max(check_list)))