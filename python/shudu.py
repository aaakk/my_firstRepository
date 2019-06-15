board = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."],
         [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
         ["4", ".", ".", "8", ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
         [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", ".", "5"],
         [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
drow0 = {}
dcol0 = {}
dpart0 = {}
for i in range(9):
    drow0[i] = [p for p in range(1, 10) if str(p) not in board[i][:]]
    dcol0[i] = [p for p in range(1, 10) if str(p) not in board[:][i]]
    index1 = (i // 3) * 3
    index2 = (i - index1) * 3
    pp = []
    for j in range(3):
        pp.extend(board[index1 + j][index2:index2 + 3])
    dpart0[i] = [p for p in range(1, 10) if (str(p) not in pp)]


def find(row, col, bo, drow, dcol, dpart):
    # print(1)
    global board
    row2 = row
    col2 = col
    f = 0
    if row == 8 and col == 8:
        # print(2)
        board = bo
        return True
    if col2 == 8:
        row2 = row2 + 1
        col2 = 0
    else:
        col2 = col2 + 1
    if bo[row2][col2] == '.':
        index = (row2 // 3) * 3 + col2 // 3
        ok = [p for p in range(1, 10) if (p in dpart[index] and p in drow[row2] and p in dcol[col2])]
        if len(ok) > 0:
            for u in ok:
                bo2 = []
                for i in range(9):
                    bo2.append(bo[i].copy())
                bo2[row2][col2] = str(u)
                dpart2 = {}
                for bb in dpart.keys():
                    dpart2[bb] = dpart[bb].copy()
                drow2 = {}
                for bb in drow.keys():
                    drow2[bb] = drow[bb].copy()
                dcol2 = {}
                for bb in dcol.keys():
                    dcol2[bb] = dcol[bb].copy()
                if u in drow2[row2]:
                    drow2[row2].remove(u)
                if u in dcol2[col2]:
                    dcol2[col2].remove(u)
                index = (row2 // 3) * 3 + col2 // 3
                if u in dpart2[index]:
                    dpart2[index].remove(u)
                if find(row2, col2, bo2, drow2, dcol2, dpart2):
                    return True
            return False
        else:
            return False
    else:
        find(row2, col2, bo, drow, dcol, dpart)


y = find(0, -1, board, drow0, dcol0, dpart0)
print(y)
print(board)
