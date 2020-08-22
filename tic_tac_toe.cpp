#include <iostream>
#include <string>

using namespace std;

void drawBoard(char (&board)[3][3])
{

  for (auto row = 0; row < 3; row++)
  {
    for (auto col = 0; col < 3; col++)
    {
      cout << board[row][col];
      if (row < 2)
      {
        cout << "_";
      }
      else
      {
        cout << " ";
      }
      if (col < 2)
      {
        cout << "|";
      }
    }
    cout << endl;
  }
}

void updateBoard(char &user_input, char (&board)[3][3], char &player)
{
  cout << "user input " << user_input << endl;

  switch (user_input)
  {
  case '1':
    board[0][0] = player;
    break;
  case '2':
    board[0][1] = player;
    break;
  case '3':
    board[0][2] = player;
    break;
  case '4':
    board[1][0] = player;
    break;
  case '5':
    board[1][1] = player;
    break;
  case '6':
    board[1][2] = player;
    break;
  case '7':
    board[2][0] = player;
    break;
  case '8':
    board[2][1] = player;
    break;
  case '9':
    board[2][2] = player;
    break;
  }
}

bool winCheck(char (&board)[3][3])
{
  if (board[0][0] == board[0][1] && board[0][0] == board[0][2])
  {
    cout << "+++++++++" << endl;
    cout << "Winner!!!" << endl;
    cout << "+++++++++" << endl;
    return true;
  }
  if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
  {
    cout << "+++++++++" << endl;
    cout << "Winner!!!" << endl;
    cout << "+++++++++" << endl;
    return true;
  }
  if (board[2][0] == board[2][1] && board[2][0] == board[2][2])
  {
    cout << "+++++++++" << endl;
    cout << "Winner!!!" << endl;
    cout << "+++++++++" << endl;
    return true;
  }
  if (board[0][0] == board[1][0] && board[0][0] == board[2][0])
  {
    cout << "+++++++++" << endl;
    cout << "Winner!!!" << endl;
    cout << "+++++++++" << endl;
    return true;
  }
  if (board[0][1] == board[1][1] && board[0][1] == board[2][1])
  {
    cout << "+++++++++" << endl;
    cout << "Winner!!!" << endl;
    cout << "+++++++++" << endl;
    return true;
  }
  if (board[0][2] == board[1][2] && board[0][2] == board[2][2])
  {
    cout << "+++++++++" << endl;
    cout << "Winner!!!" << endl;
    cout << "+++++++++" << endl;
    return true;
  }
  return false;
}

int main()
{
  char board[3][3] = {
      {'1', '2', '3'},
      {'4', '5', '6'},
      {'7', '8', '9'},
  };

  char input = {};

  char p{};
  bool p_flag = true;
  bool win{};

  do
  {
    if (p_flag == true)
    {
      p = 'x';
      p_flag = false;
    }
    else
    {
      p = 'o';
      p_flag = true;
    }
    updateBoard(input, board, p);
    drawBoard(board);
    win = winCheck(board);
    if (win)
    {
      break;
    }
    cout << "Choose a number or exit with e: ";
    cin >> input;

  } while (input != 'e');

  if (input == 'e' || win == 1)
  {
    cout << "GoodBye" << endl;
  }

  return 0;
}