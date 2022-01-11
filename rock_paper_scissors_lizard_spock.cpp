#include <stdlib.h>
#include <iostream>

static void  displayWeapons() {
  std::cout << std::endl;
  std::cout << "====================================" << std::endl;
  std::cout << "| Rock Paper Scissors Lizard Spock |" << std::endl;
  std::cout << "====================================" << std::endl;
  std::cout << "1) ✊" << std::endl;
  std::cout << "2) ✋" << std::endl;
  std::cout << "3) ✌" << std::endl;
  std::cout << "4) 🦎" << std::endl;
  std::cout << "5) 🖖" << std::endl;
  std::cout << "0) Exit" << std::endl;
  std::cout << std::endl;
}

static int getUserWeapon() {
  int weapon = 0;

  do {
    if (weapon)
      std::cout << "Invalid weapon. Try again: ";
    std::cin >> weapon;
  } while (weapon < 0 || weapon > 5);
  return (weapon);
}

static int getBoteWeapon() {
  srand(time(NULL));
  return (rand() % 5 + 1);
}

static int userWon(int *const user_weapon, int *const bot_weapon) {
  return ((*user_weapon == 1 && (*bot_weapon == 3 || *bot_weapon == 4))
          || (*user_weapon == 2 && (*bot_weapon == 1 || *bot_weapon == 5))
          || (*user_weapon == 3 && (*bot_weapon == 2 || *bot_weapon == 4))
          || (*user_weapon == 4 && (*bot_weapon == 2 || *bot_weapon == 5))
          || (*user_weapon == 5 && (*bot_weapon == 1 || *bot_weapon == 3)));
}

static int compareWeapons(int *const user_weapon, int *const bot_weapon) {
  if (*user_weapon == *bot_weapon)
    return (0);
  else if (userWon(user_weapon, bot_weapon))
    return (1);
  else
    return (-1);
}

static std::string displayResult(int *const user_weapon, int *const bot_weapon) {
  int result = compareWeapons(user_weapon, bot_weapon);

  return (result == 0 ? "TIE! 🤝" :
            result > 0 ? "You WON! 😄" : "You LOST! 😭");
}

int main() {
  const std::string weapons[5] = { "✊", "✋", "✌", "🦎", "🖖" };
  int user_weapon = 0;
  int bot_weapon = 0;

  displayWeapons();
  do {
    std::cout << "Shoot! ";
    user_weapon = getUserWeapon();
    bot_weapon = getBoteWeapon();
    if (user_weapon == 0)
      continue;
    std::cout << "You: " << weapons[user_weapon - 1] << "  ";
    std::cout << "Bot: " << weapons[bot_weapon - 1] << std::endl;
    std::cout << displayResult(&user_weapon, &bot_weapon) << std::endl << std::endl;
  } while (user_weapon != 0);
  return 0;
}
