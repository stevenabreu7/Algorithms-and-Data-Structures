from Player import *

class Game:
    def __init__(self, player, opponent):
        """Creates a new Game Object with a fresh Board."""
        self.players = [player, opponent]
        self.board = Board()

    def printExampleBoard(self):
        """This prints the instructions with a sample board."""
        print("\nFor your move, please enter a number between 1 and 9.")
        s = ""
        for i in range(3):
            for j in range(3):
                s += " " + str(i*3+j+1) + " "
                if j != 2:
                    s += "|"
            if i != 2:
                s += "\n-----------\n"
        print("\n" + s + "\n")

    def run(self, printing=False):
        """Run Game. printing determines output on the console."""
        resultDict = {0: "  It's a draw!  ", 1: " Player 1 wins! ", 2: " Player 2 wins! "}
        opponent = {1:2,2:1}
        # print instructions
        if printing:
            self.printExampleBoard()
        # start game loop
        while not(self.board.isOver()):
            current = self.board.getCurrentPlayer()
            (r,c) = self.players[current-1].getMove(self.board)
            # make move
            try:
                self.board.makeMove(r,c)
            except IllegalMove:
                # print illegal move handling, if printing is enabled
                if printing:
                    print("Move: ", r, c)
                    print("\n**********************")
                    print("**   Illegal Move!  **")
                    print("** " + resultDict[opponent[current]] + " **")
                    print("**********************\n")
                break
            # print board after each move, if printing is enabled
            print(self.board if printing else "", end="")
        if self.board.getResult() != -1:
            # print the game result, if printing is enabled
            if printing:
                print("**********************")
                print("** " + resultDict[self.board.getResult()] + " **")
                print("**********************\n")
        return self.board.getResult()

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
        print(won1/times, won2/times, dra/times)
    # Play agains the smart player
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
    # s = SmarterPlayer("smart")
    # r = RandomPlayer("random")
    # won1 = 0
    # won2 = 0
    # dra = 0
    # for i in range(5):
    #     g = Game(r,s)
    #     res = g.run()
    #     if res == 1:
    #         won1 += 1
    #     elif res == 2:
    #         won2 += 1
    #     else:
    #         dra += 1
    #     print("result",res,sep="\n")
    # print(won1, won2, dra)
