from Player import *
from Board import *
from Game import *

def main():
    """Main function in Game, starts the game in the console."""
    print("\nCommands:\n" +
            "Test:        Test smart player\n" +
            "Play smart:  Play against smart player\n" +
            "Play random: Play against random player\n")
    # Enter a command
    cmd = input("Enter command: ")
    # Players
    s = SmarterPlayer("smart")
    r = RandomPlayer("random")

    # Test the smart player, with a variable number of games
    if cmd == "Test":
        start = input("Should the smart player start? (y for yes) ")
        times = int(input("How many games to play? "))
        won1 = 0
        won2 = 0
        dra = 0
        for i in range(times):
            g = Game(r,s)
            if start == "y":
                g = Game(s,r)
            res = g.run()
            if res == 1:
                won1 += 1
            elif res == 2:
                won2 += 1
            else:
                dra += 1
        print("Player 1:", won1/times, "Player 2:", won2/times, "Draw:", dra/times)
    # Play against the smart player
    elif cmd == "Play smart":
        start = input("Would you like to start? (y for yes) ")
        name = input("Enter your name: ")
        print("Hello,", name, "\nGood Luck!")
        h = HumanPlayer(name)
        g = Game(s,h)
        if start == "y":
            g = Game(h,s)
        g.run(True)
    # Play against random player
    elif cmd == "Play random":
        start = input("Would you like to start? (y for yes) ")
        name = input("Enter your name: ")
        print("Hello,", name, "\nGood Luck!")
        h = HumanPlayer(name)
        g = Game(r,h)
        if start == "y":
            g = Game(h,r)
        g.run(True)

# run the main function only if this is __main__
if __name__ == "__main__":
    main()
