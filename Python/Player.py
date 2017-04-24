from random import choice
from Board import *

class Player:
    """Abstract Player class."""
    def __init__(self, name):
        """Constructor for a Player Object. Takes only name of Player."""
        self.name = name

    def getName(self):
        """Returns the name of this player."""
        return self.name

    def getMove(self, board, turn):
        """Abstract method."""
        pass

class RandomPlayer(Player):
    def getMove(self, board, turn):
        """Returns a random (possible) move."""
        return choice(board.getPossibleMoves())

class HumanPlayer(Player):
    def getMove(self, board, turn):
        """Returns a move from user-input."""
        m = int(input("Enter move (1-9): "))
        r = (m-1) // 3
        c = (m-1) % 3
        return (r,c)

class SmartPlayer(Player):
    def getMove(self, board, turn):
        """Returns a smart move."""
        noLossMoves = []
        opponent = {1:2, 2:1}
        # check if this is the beginning of the game
        if len(board.getPossibleMoves()) == 9:
            return (1,1)
        elif len(board.getPossibleMoves()) == 8:
            return (0,0)
        # check more complicated game situations
        for (move1, move2) in board.getPossibleMoves():
            # check winning move
            board.simMove(move1, move2, turn)
            if board.hasWon(turn):
                board.simMove(move1, move2, 0)
                return (move1, move2)
            # check prevent loss move
            board.simMove(move1, move2, opponent[turn])
            if board.hasWon(opponent[turn]):
                noLossMoves.append((move1, move2))
            board.simMove(move1, move2, 0)
        # return no loss move // random move
        if len(noLossMoves) > 0:
            return choice(noLossMoves)
        else:
            return choice(board.getPossibleMoves())
