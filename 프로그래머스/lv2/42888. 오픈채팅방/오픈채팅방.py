def solution(record):
    answer = []
    user = {}
    for s in record :
        arr = s.split()
        if arr[0] == 'Leave' :
            pass
        else :
            user[arr[1]] = arr[2]
    for s in record :
        arr = s.split()
        if arr[0] == 'Enter' :
            answer.append("{0}님이 들어왔습니다.".format(user[arr[1]]))
        elif arr[0] == 'Leave' :
            answer.append("{0}님이 나갔습니다.".format(user[arr[1]]))

    return answer