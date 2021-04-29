#include <bits/stdc++.h>
using namespace std;

enum { Up, Down, Front, Back, Left, Right };

int tc, N;
vector<char> cube[6];
vector<pair<char, char>> v;

void init() {
  v.clear();
  for (int i = 0; i < 6; i++) {
    cube[i].clear();
  }
  for (int i = 0; i < 9; i++) {
    cube[Up].push_back('w');
    cube[Down].push_back('y');
    cube[Front].push_back('r');
    cube[Back].push_back('o');
    cube[Left].push_back('g');
    cube[Right].push_back('b');
  }
}

void move_front_block(int pos, char dir) {
  int temp[3][3];
  if (dir == '+') {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        temp[j][3 - 1 - i] = cube[pos][3 * i + j];
      }
    }
  } else if (dir == '-') {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        temp[3 - 1 - j][i] = cube[pos][3 * i + j];
      }
    }
  }
  cube[pos].clear();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cube[pos].push_back(temp[i][j]);
    }
  }
}

int convert_pos(char ch) {
  if (ch == 'U') {
    return Up;
  } else if (ch == 'D') {
    return Down;
  } else if (ch == 'F') {
    return Front;
  } else if (ch == 'B') {
    return Back;
  } else if (ch == 'L') {
    return Left;
  } else if (ch == 'R') {
    return Right;
  }
  return -1;
}

void change_cube(int pos, char dir) {
  char temp[5];
  move_front_block(pos, dir);
  if (pos == Up) {
    if (dir == '+') {
      temp[0] = cube[Right][0];
      temp[1] = cube[Right][1];
      temp[2] = cube[Right][2];

      cube[Right][0] = cube[Back][0];
      cube[Right][1] = cube[Back][1];
      cube[Right][2] = cube[Back][2];

      cube[Back][0] = cube[Left][0];
      cube[Back][1] = cube[Left][1];
      cube[Back][2] = cube[Left][2];

      cube[Left][0] = cube[Front][0];
      cube[Left][1] = cube[Front][1];
      cube[Left][2] = cube[Front][2];

      cube[Front][0] = temp[0];
      cube[Front][1] = temp[1];
      cube[Front][2] = temp[2];
    } else if (dir == '-') {
      temp[0] = cube[Left][0];
      temp[1] = cube[Left][1];
      temp[2] = cube[Left][2];

      cube[Left][0] = cube[Back][0];
      cube[Left][1] = cube[Back][1];
      cube[Left][2] = cube[Back][2];

      cube[Back][0] = cube[Right][0];
      cube[Back][1] = cube[Right][1];
      cube[Back][2] = cube[Right][2];

      cube[Right][0] = cube[Front][0];
      cube[Right][1] = cube[Front][1];
      cube[Right][2] = cube[Front][2];

      cube[Front][0] = temp[0];
      cube[Front][1] = temp[1];
      cube[Front][2] = temp[2];
    }
  } else if (pos == Down) {
    if (dir == '+') {
      temp[0] = cube[Left][6];
      temp[1] = cube[Left][7];
      temp[2] = cube[Left][8];

      cube[Left][6] = cube[Back][6];
      cube[Left][7] = cube[Back][7];
      cube[Left][8] = cube[Back][8];

      cube[Back][6] = cube[Right][6];
      cube[Back][7] = cube[Right][7];
      cube[Back][8] = cube[Right][8];

      cube[Right][6] = cube[Front][6];
      cube[Right][7] = cube[Front][7];
      cube[Right][8] = cube[Front][8];

      cube[Front][6] = temp[0];
      cube[Front][7] = temp[1];
      cube[Front][8] = temp[2];
    } else if (dir == '-') {
      temp[0] = cube[Right][6];
      temp[1] = cube[Right][7];
      temp[2] = cube[Right][8];

      cube[Right][6] = cube[Back][6];
      cube[Right][7] = cube[Back][7];
      cube[Right][8] = cube[Back][8];

      cube[Back][6] = cube[Left][6];
      cube[Back][7] = cube[Left][7];
      cube[Back][8] = cube[Left][8];

      cube[Left][6] = cube[Front][6];
      cube[Left][7] = cube[Front][7];
      cube[Left][8] = cube[Front][8];

      cube[Front][6] = temp[0];
      cube[Front][7] = temp[1];
      cube[Front][8] = temp[2];
    }
  } else if (pos == Front) {
    if (dir == '+') {
      temp[0] = cube[Right][0];
      temp[1] = cube[Right][3];
      temp[2] = cube[Right][6];

      cube[Right][0] = cube[Up][6];
      cube[Right][3] = cube[Up][7];
      cube[Right][6] = cube[Up][8];

      cube[Up][6] = cube[Left][8];
      cube[Up][7] = cube[Left][5];
      cube[Up][8] = cube[Left][2];

      cube[Left][2] = cube[Down][0];
      cube[Left][5] = cube[Down][1];
      cube[Left][8] = cube[Down][2];

      cube[Down][2] = temp[0];
      cube[Down][1] = temp[1];
      cube[Down][0] = temp[2];
    } else if (dir == '-') {
      temp[0] = cube[Left][2];
      temp[1] = cube[Left][5];
      temp[2] = cube[Left][8];

      cube[Left][2] = cube[Up][8];
      cube[Left][5] = cube[Up][7];
      cube[Left][8] = cube[Up][6];

      cube[Up][6] = cube[Right][0];
      cube[Up][7] = cube[Right][3];
      cube[Up][8] = cube[Right][6];

      cube[Right][0] = cube[Down][2];
      cube[Right][3] = cube[Down][1];
      cube[Right][6] = cube[Down][0];

      cube[Down][0] = temp[0];
      cube[Down][1] = temp[1];
      cube[Down][2] = temp[2];
    }
  } else if (pos == Back) {
    if (dir == '+') {
      temp[0] = cube[Left][0];
      temp[1] = cube[Left][3];
      temp[2] = cube[Left][6];

      cube[Left][0] = cube[Up][2];
      cube[Left][3] = cube[Up][1];
      cube[Left][6] = cube[Up][0];

      cube[Up][0] = cube[Right][2];
      cube[Up][1] = cube[Right][5];
      cube[Up][2] = cube[Right][8];

      cube[Right][2] = cube[Down][8];
      cube[Right][5] = cube[Down][7];
      cube[Right][8] = cube[Down][6];

      cube[Down][6] = temp[0];
      cube[Down][7] = temp[1];
      cube[Down][8] = temp[2];
    } else if (dir == '-') {
      temp[0] = cube[Right][2];
      temp[1] = cube[Right][5];
      temp[2] = cube[Right][8];

      cube[Right][2] = cube[Up][0];
      cube[Right][5] = cube[Up][1];
      cube[Right][8] = cube[Up][2];

      cube[Up][0] = cube[Left][6];
      cube[Up][1] = cube[Left][3];
      cube[Up][2] = cube[Left][0];

      cube[Left][0] = cube[Down][6];
      cube[Left][3] = cube[Down][7];
      cube[Left][6] = cube[Down][8];

      cube[Down][6] = temp[2];
      cube[Down][7] = temp[1];
      cube[Down][8] = temp[0];
    }
  } else if (pos == Left) {
    if (dir == '+') {
      temp[0] = cube[Front][0];
      temp[1] = cube[Front][3];
      temp[2] = cube[Front][6];

      cube[Front][0] = cube[Up][0];
      cube[Front][3] = cube[Up][3];
      cube[Front][6] = cube[Up][6];

      cube[Up][0] = cube[Back][8];
      cube[Up][3] = cube[Back][5];
      cube[Up][6] = cube[Back][2];

      cube[Back][2] = cube[Down][6];
      cube[Back][5] = cube[Down][3];
      cube[Back][8] = cube[Down][0];

      cube[Down][0] = temp[0];
      cube[Down][3] = temp[1];
      cube[Down][6] = temp[2];
    } else if (dir == '-') {
      temp[0] = cube[Back][2];
      temp[1] = cube[Back][5];
      temp[2] = cube[Back][8];

      cube[Back][2] = cube[Up][6];
      cube[Back][5] = cube[Up][3];
      cube[Back][8] = cube[Up][0];

      cube[Up][0] = cube[Front][0];
      cube[Up][3] = cube[Front][3];
      cube[Up][6] = cube[Front][6];

      cube[Front][0] = cube[Down][0];
      cube[Front][3] = cube[Down][3];
      cube[Front][6] = cube[Down][6];

      cube[Down][0] = temp[2];
      cube[Down][3] = temp[1];
      cube[Down][6] = temp[0];
    }
  } else if (pos == Right) {
    if (dir == '+') {
      temp[0] = cube[Back][0];
      temp[1] = cube[Back][3];
      temp[2] = cube[Back][6];

      cube[Back][0] = cube[Up][8];
      cube[Back][3] = cube[Up][5];
      cube[Back][6] = cube[Up][2];

      cube[Up][2] = cube[Front][2];
      cube[Up][5] = cube[Front][5];
      cube[Up][8] = cube[Front][8];

      cube[Front][2] = cube[Down][2];
      cube[Front][5] = cube[Down][5];
      cube[Front][8] = cube[Down][8];

      cube[Down][2] = temp[2];
      cube[Down][5] = temp[1];
      cube[Down][8] = temp[0];
    } else if (dir == '-') {
      temp[0] = cube[Front][2];
      temp[1] = cube[Front][5];
      temp[2] = cube[Front][8];

      cube[Front][2] = cube[Up][2];
      cube[Front][5] = cube[Up][5];
      cube[Front][8] = cube[Up][8];

      cube[Up][2] = cube[Back][6];
      cube[Up][5] = cube[Back][3];
      cube[Up][8] = cube[Back][0];

      cube[Back][0] = cube[Down][8];
      cube[Back][3] = cube[Down][5];
      cube[Back][6] = cube[Down][2];

      cube[Down][2] = temp[0];
      cube[Down][5] = temp[1];
      cube[Down][8] = temp[2];
    }
  }
}

void print_cube() {
  for (int i = 0; i < 9; i++) {
    if ((i + 1) % 3 == 0) {
      printf("%c\n", cube[Up][i]);
    } else {
      printf("%c", cube[Up][i]);
    }
  }
}

void play_cube() {
  init();
  char temp[5];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", temp);
    int pos = convert_pos(temp[0]);
    change_cube(pos, temp[1]);
    move_front_block(pos, temp[1]);
  }
  print_cube();
}

int main() {
  play_cube();
  //   scanf("%d", &tc);
  //   while (tc-- > 0) {
  //     play_cube();
  //   }
}