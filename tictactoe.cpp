// This comment is meant to provide scroll to right____^____^____^____^____^____^____^____^____^____^____^____^____^____^____^____^____^____^____^____^____^____^____^____^____^__...
#include <iostream>

/*
  coords are from top left,
  aa represents top left,
  ab for top middle,
  ba for middle left,
  and like that.
*/
/* Board Drawing Test

   X | O | X
   ---------
   O | X | O
   ---------
   X | O | X

*/

/*
   value of integers are:
   0 --> blank  ( )
   1 --> circle (O)
   2 --> cross  (X)
*/

void drawBoard(int aa, int ab, int ac, int ba, int bb, int bc, int ca, int cb, int cc);
char getSymbolByCoord(int box_coord);
void clearScreen();
bool isPlayerWinning(int aa, int ab, int ac, int ba, int bb, int bc, int ca, int cb, int cc);
bool isComputerWinning(int aa, int ab, int ac, int ba, int bb, int bc, int ca, int cb, int cc);
bool isTie(int aa, int ab, int ac, int ba, int bb, int bc, int ca, int cb, int cc);


char getSymbolByCoord(int box_coord)
{
    char symb{};
    if (box_coord == 0)
    {
        symb = ' ';
    }
    else if (box_coord == 1)
    {
        symb = 'O';
    }
    else if (box_coord == 2)
    {
        symb = 'X';
    }
    return symb;
}

void drawBoard(int aa, int ab, int ac, int ba, int bb, int bc, int ca, int cb, int cc)
{
    std::cout << "Board Structure:\n";
    std::cout << "  aa | ab | ac\n";
    std::cout << "  ------------\n";
    std::cout << "  ba | bb | bc\n";
    std::cout << "  ------------\n";
    std::cout << "  ca | cb | cc\n\n";
    std::cout << "You choose X(cross)\n\n";
    std::cout << "\n\n"
              << "  " << getSymbolByCoord(aa) << " | " << getSymbolByCoord(ab) << " | " << getSymbolByCoord(ac) << '\n'
              << "  ---------\n"
              << "  " << getSymbolByCoord(ba) << " | " << getSymbolByCoord(bb) << " | " << getSymbolByCoord(bc) << '\n'
              << "  ---------\n"
              << "  " << getSymbolByCoord(ca) << " | " << getSymbolByCoord(cb) << " | " << getSymbolByCoord(cc) << '\n'
              << '\n';
    std::cout << "Enter coordinate to enter X: ";
}

void clearScreen()
{
    for (int i = 0; i < 1024; i++)
    {
        std::cout << "\n";
    }
}

bool isPlayerWinning(int aa, int ab, int ac, int ba, int bb, int bc, int ca, int cb, int cc)
{
    bool is_winning = false;
    if (aa == ab && ab == ac && ac == 2)
    {
        is_winning = true;
    }
    else if (aa == ba && ba == ca && ca == 2)
    {
        is_winning = true;
    }
    else if (ca == cb && cb == cc && cc == 2)
    {
        is_winning = true;
    }
    else if (ac == bc && bc == cc && cc == 2)
    {
        is_winning = true;
    }
    else if (aa == bb && bb == cc && cc == 2)
    {
        is_winning = true;
    }
    else if (ac == bb && bb == ca && ca == 2)
    {
        is_winning = true;
    }
    else if (ab == bb && bb == cb && cb == 2)
    {
        is_winning = true;
    }
    else if (ba == bb && bb == bc && bc == 2)
    {
        is_winning = true;
    }
    return is_winning;
}

bool isComputerWinning(int aa, int ab, int ac, int ba, int bb, int bc, int ca, int cb, int cc)
{
 bool is_winning = false;
    if (aa == ab && ab == ac && ac == 1)
    {
        is_winning = true;
    }
    else if (aa == ba && ba == ca && ca == 1)
    {
        is_winning = true;
    }
    else if (ca == cb && cb == cc && cc == 1)
    {
        is_winning = true;
    }
    else if (ac == bc && bc == cc && cc == 1)
    {
        is_winning = true;
    }
    else if (aa == bb && bb == cc && cc == 1)
    {
        is_winning = true;
    }
    else if (ac == bb && bb == ca && ca == 1)
    {
        is_winning = true;
    }
    else if (ab == bb && bb == cb && cb == 1)
    {
        is_winning = true;
    }
    else if (ba == bb && bb == bc && bc == 1)
    {
        is_winning = true;
    }
    return is_winning;
}

bool isTie(int aa, int ab, int ac, int ba, int bb, int bc, int ca, int cb, int cc)
{
 bool is_tie = false;
 if(aa != 0 && ab != 0 && ac != 0 && ba != 0 && bb != 0 && bc != 0 && ca != 0 && cb != 0 && cc != 0)
 {
  is_tie = true;
 }
 return is_tie;
}

int main()
{
    int aa{0};
    int ab{0};
    int ac{0};
    int ba{0};
    int bb{0};
    int bc{0};
    int ca{0};
    int cb{0};
    int cc{0};
    std::string coord{};
    bool user_entered = false;
    bool computer_entered = true;
    bool user_enter_invalid = false;

    srand(time(0));

    for (;;)
    {
        clearScreen();
        drawBoard(aa, ab, ac, ba, bb, bc, ca, cb, cc);
        //check if result
        if (isPlayerWinning(aa, ab, ac, ba, bb, bc, ca, cb, cc))
        {
            std::cout << "\nCongrats, You Won\n" << std::endl;
            exit(0);
        }
        else if (isComputerWinning(aa, ab, ac, ba, bb, bc, ca, cb, cc))
        {
            std::cout << "\nYou lost, better luck next time\n" << std::endl;
            exit(0);
        }
        else if (isTie(aa, ab, ac, ba, bb, bc, ca, cb, cc))
        {
         std::cout << "\nIts a tie\n" << std::endl;
         exit(0);
        } else if (user_enter_invalid)
        {
         std::cout << "\nThis box is already filled or not exist(You lost a move)\n";
        }
        user_enter_invalid = false;
        //get input from user and display!
        if (computer_entered)
        {
            user_entered = false;
            std::getline(std::cin, coord);

            if (coord == "aa")
            {
                if (aa == 0)
                {
                    aa = 2;
                    user_entered = true;
                }
                else
                {
                    user_enter_invalid = true;
                }
            }
            else if (coord == "ab")
            {
                if (ab == 0)
                {
                    ab = 2;
                    user_entered = true;
                }
                else
                {
                    user_enter_invalid = true;
                }
            }
            else if (coord == "ac")
            {
                if (ac == 0)
                {
                    ac = 2;
                    user_entered = true;
                }
                else
                {
                    user_enter_invalid = true;
                }
            }
            else if (coord == "ba")
            {
                if (ba == 0)
                {
                    ba = 2;
                    user_entered = true;
                }
                else
                {
                    user_enter_invalid = true;
                }
            }
            else if (coord == "bb")
            {
                if (bb == 0)
                {
                    bb = 2;
                    user_entered = true;
                }
                else
                {
                    user_enter_invalid = true;
                }
            }
            else if (coord == "bc")
            {
                if (bc == 0)
                {
                    bc = 2;
                    user_entered = true;
                }
                else
                {
                    user_enter_invalid = true;
                }
            }
            else if (coord == "ca")
            {
                if (ca == 0)
                {
                    ca = 2;
                    user_entered = true;
                }
                else
                {
                    user_enter_invalid = true;
                }
            }
            else if (coord == "cb")
            {
                if (cb == 0)
                {
                    cb = 2;
                    user_entered = true;
                }
                else
                {
                    user_enter_invalid = true;
                }
            }
            else if (coord == "cc")
            {
                if (cc == 0)
                {
                    cc = 2;
                    user_entered = true;
                }
                else
                {
                    user_enter_invalid = true;
                }
            }
            else
            {
                user_enter_invalid = true;
            }
        }

        //get user input ends

        //if user entered a valid value, play a computer move

        if (user_entered)
            computer_entered = false;
        {
            switch ((rand() % 9) + 1)
            {
            case 1:
                if (aa == 0)
                {
                    aa = 1;
                    computer_entered = true;
                }
                break;
            case 2:
                if (ab == 0)
                {
                    ab = 1;
                    computer_entered = true;
                }
                break;
            case 3:
                if (ac == 0)
                {
                    ac = 1;
                    computer_entered = true;
                }
                break;
            case 4:
                if (ba == 0)
                {
                    ba = 1;
                    computer_entered = true;
                }
                break;
            case 5:
                if (bb == 0)
                {
                    bb = 1;
                    computer_entered = true;
                }
                break;
            case 6:
                if (bc == 0)
                {
                    bc = 1;
                    computer_entered = true;
                }
                break;
            case 7:
                if (ca == 0)
                {
                    ca = 1;
                    computer_entered = true;
                }
                break;
            case 8:
                if (cb == 0)
                {
                    cb = 1;
                    computer_entered = true;
                }
                break;
            case 9:
                if (cc == 0)
                {
                    cc = 1;
                    computer_entered = true;
                }
                break;
            }
        }
        //Computer move ends here
        
    }

    return 0;
}