#include <testlib.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char **argv)
{
    registerInteraction(argc, argv);

    int n = inf.readInt(), nguess = 0;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = inf.readInt();
    }

    while (true)
    {
        std::string cmd = ouf.readWord();
        if (cmd == "get_num")
        {
            std::cout << n << std::endl << std::flush;
        }
        else if (cmd == "guess")
        {
            nguess++;
            int index = ouf.readInt(), val = ouf.readInt();
			quitif(!(0 <= index && index < n), _pe, "`index` must in [0, n)!");

			if (val < nums[index])
			{
				std::cout << -1 << std::endl << std::flush;
			}
			else if (val > nums[index])
			{
				std::cout << 1 << std::endl << std::flush;
			}
			else
			{
				std::cout << 0 << std::endl << std::flush;
			}
        }
        else if (cmd == "submit")
        {
            bool wrongAnswer = false;
            for (int i = 0; i < n; i++)
            {
                int x = ouf.readInt();
                
                if (x != nums[i] && !wrongAnswer)
				{
                    wrongAnswer = true;
                    quitf(_wa, "First differ on the %d-th number!", i);
                }
            }
            
            if (!wrongAnswer)
            {
				quitp(
                    std::max(std::min(100.0, (950.0 - ((double)nguess / n - 100.0)) / 950.0 * 100.0), 0.0),
                    "nguess = " + std::to_string(nguess)
                );
            }
        }
		else
		{
			quitf(_pe, "Invalid command `%s`!", cmd.c_str());
		}
    }
}
