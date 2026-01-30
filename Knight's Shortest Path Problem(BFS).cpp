#include<iostream>
using namespace std;

int chessboard[401][401];
int queueArr[401 * 401][3];
int queueHead = 1;
int queueTail = 1;
const int dirX[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int dirY[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int main() {
    int boardN, boardM, startX, startY;
    cin >> boardN >> boardM >> startX >> startY;

    for (int i = 1; i <= boardN; i++) {
        for (int j = 1; j <= boardM; j++) {
            chessboard[i][j] = -1;
        }
    }

    queueArr[1][1] = startX;
    queueArr[1][2] = startY;
    chessboard[startX][startY] = 0;

    int nextX, nextY, curX, curY;
    while (queueHead <= queueTail) {
        int currentTail = queueTail;

        for (int pos = queueHead; pos <= currentTail; pos++) {
            curX = queueArr[pos][1];
            curY = queueArr[pos][2];

            for (int i = 0; i < 8; i++) {
                nextX = curX + dirX[i];
                nextY = curY + dirY[i];

                if (nextX >= 1 && nextX <= boardN && nextY >= 1 && nextY <= boardM && chessboard[nextX][nextY] == -1) {
                    chessboard[nextX][nextY] = chessboard[curX][curY] + 1;
                    queueTail++;
                    queueArr[queueTail][1] = nextX;
                    queueArr[queueTail][2] = nextY;
                }
            }
        }

        queueHead = currentTail + 1;
    }

    for (int i = 1; i <= boardN; i++) {
        for (int j = 1; j <= boardM; j++) {
            cout << chessboard[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}
