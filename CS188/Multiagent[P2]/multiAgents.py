# multiAgents.py
# --------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent
from pacman import GameState

class ReflexAgent(Agent):
    """
    A reflex agent chooses an action at each choice point by examining
    its alternatives via a state evaluation function.

    The code below is provided as a guide.  You are welcome to change
    it in any way you see fit, so long as you don't touch our method
    headers.
    """


    def getAction(self, gameState: GameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {NORTH, SOUTH, WEST, EAST, STOP}
        """
        # Collect legal moves and successor states
        legalMoves = gameState.getLegalActions()



        # Choose one of the best actions
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices) # Pick randomly among the best

        "Add more of your code here if you want to"
        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState: GameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        newFood = successorGameState.getFood()
        newGhostStates = successorGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

        "*** YOUR CODE HERE ***"
        # print(newGhostStates)
        # Useful information you can extract from a GameState (pacman.py)
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        newFood = successorGameState.getFood()
        newGhostStates = successorGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

        newGhostDists =[manhattanDistance(newPos, ghostState.configuration.pos) for ghostState in newGhostStates]

        dangerScore = 0
        for i in range(len(newScaredTimes)):
            if newScaredTimes[i] == 0:
                score = -1000 if newGhostDists[i] < 2 else 0
            else:
                score = 1000/newGhostDists[i]
            dangerScore +=score
        if len(newFood.asList()) > 0:
            nearestFood = (min([manhattanDistance(newPos, food) for food in newFood.asList()]))
            foodHeuristic =  5/ (nearestFood)
        else:
            foodHeuristic = 0

        # print("Action:",action,"Score:",successorGameState.getScore(),"Danger:",dangerScore,"Food:",foodHeuristic,"Total:",successorGameState.getScore()+foodHeuristic+dangerScore)
        return successorGameState.getScore() + foodHeuristic + dangerScore

def scoreEvaluationFunction(currentGameState: GameState):
    """
    This default evaluation function just returns the score of the state.
    The score is the same one displayed in the Pacman GUI.

    This evaluation function is meant for use with adversarial search agents
    (not reflex agents).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
    This class provides some common elements to all of your
    multi-agent searchers.  Any methods defined here will be available
    to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

    You *do not* need to make any changes here, but you can if you want to
    add functionality to all your adversarial search agents.  Please do not
    remove anything, however.

    Note: this is an abstract class: one that should not be instantiated.  It's
    only partially specified, and designed to be extended.  Agent (game.py)
    is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
    Your minimax agent (question 2)
    """

    def getAction(self, gameState: GameState):
        """
        Returns the minimax action from the current gameState using self.depth
        and self.evaluationFunction.

        Here are some method calls that might be useful when implementing minimax.

        gameState.getLegalActions(agentIndex):
        Returns a list of legal actions for an agent
        agentIndex=0 means Pacman, ghosts are >= 1

        gameState.generateSuccessor(agentIndex, action):
        Returns the successor game state after an agent takes an action

        gameState.getNumAgents():
        Returns the total number of agents in the game

        gameState.isWin():
        Returns whether or not the game state is a winning state

        gameState.isLose():
        Returns whether or not the game state is a losing state
        """
        "*** YOUR CODE HERE ***"
        def max_value(state:GameState,agentIndex,depth):
            v = -float('inf')
            legalMoves = state.getLegalActions(agentIndex)
            for move in legalMoves:
                successorGameState = state.generateSuccessor(agentIndex,move)
                next_agent = (agentIndex+1) % state.getNumAgents()
                next_depth = (agentIndex+1) // state.getNumAgents() + depth
                v = max(v,value(successorGameState,next_agent,next_depth))
            return v
        def min_value(state:GameState, agentIndex, depth):
            v = float('inf')

            legalMoves = state.getLegalActions(agentIndex)
            for move in legalMoves:
                successorGameState = state.generateSuccessor(agentIndex,move)
                next_agent = (agentIndex + 1) % state.getNumAgents()
                next_depth = (agentIndex + 1) // state.getNumAgents() + depth
                v = min(v, value(successorGameState, next_agent, next_depth))
            return v
        def value(state,agentIndex,depth):
            if depth == self.depth or state.isWin() or state.isLose():
                return self.evaluationFunction(state)
            elif agentIndex == 0: #MAX
                return max_value(state,agentIndex,depth)
            else:
                return min_value(state,agentIndex,depth)

        # import pdb;pdb.set_trace()
        legalMoves = gameState.getLegalActions(self.index)
        max_v = -float('inf')
        # best_move = legalMoves[0]
        # import pdb; pdb.set_trace()
        for move in legalMoves:
            successorGameState = gameState.generateSuccessor(self.index,move)
            v = value(successorGameState,self.index+1,0)
            if max_v < v:
                    best_move = move
                    max_v = v
        return best_move

        util.raiseNotDefined()

class AlphaBetaAgent(MultiAgentSearchAgent):
    """
    Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState: GameState):
        """
        Returns the minimax action using self.depth and self.evaluationFunction
        NOTE: ??????alpha,beta???????????????????????????
        """
        "*** YOUR CODE HERE ***"
        def max_value(state: GameState, agentIndex, depth,alpha,beta):

            v = -float('inf')
            legalMoves = state.getLegalActions(agentIndex)
            best_move = None
            for move in legalMoves:
                successorGameState = state.generateSuccessor(agentIndex, move)
                next_agent = (agentIndex + 1) % state.getNumAgents()
                next_depth = (agentIndex + 1) // state.getNumAgents() + depth
                v1,_= value(successorGameState, next_agent, next_depth,alpha,beta)
                if v< v1:
                    v = v1
                    best_move = move
                # v = max(v, value(successorGameState, next_agent, next_depth,alpha,beta))
                if v> beta: return v,move
                alpha = max(alpha, v)
            return v,best_move
        def min_value(state: GameState, agentIndex, depth,alpha,beta):
            v = float('inf')

            legalMoves = state.getLegalActions(agentIndex)
            for move in legalMoves:
                successorGameState = state.generateSuccessor(agentIndex, move)
                next_agent = (agentIndex + 1) % state.getNumAgents()
                next_depth = (agentIndex + 1) // state.getNumAgents() + depth
                v1,_ = value(successorGameState, next_agent, next_depth,alpha,beta)
                if v > v1:
                    v = v1
                    best_move = move
                # v = min(v, value(successorGameState, next_agent, next_depth,alpha,beta))
                if v < alpha:
                    return v,move
                beta = min(beta,v)
            return v,best_move

        def value(state, agentIndex, depth,alpha,beta):
            if depth == self.depth or state.isWin() or state.isLose():
                return self.evaluationFunction(state),None
            elif agentIndex == 0:  # MAX
                return max_value(state, agentIndex, depth,alpha,beta)
            else:
                return min_value(state, agentIndex, depth,alpha,beta)

        import pdb;
        # pdb.set_trace()
        legalMoves = gameState.getLegalActions(self.index)

        # best_move = legalMoves[0]
        # import pdb; pdb.set_trace()
        alpha = -float('inf')
        beta = float('inf')
        best_score,best_move = value(gameState,self.index,0,alpha,beta)
        # for move in legalMoves:
        #     successorGameState = gameState.generateSuccessor(self.index, move)
        #     v = value(successorGameState, self.index + 1, 0)
        #     if alpha < v:
        #         best_move = move
        #         alpha = v
        return best_move
        util.raiseNotDefined()

class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def getAction(self, gameState: GameState):
        """
        Returns the expectimax action using self.depth and self.evaluationFunction

        All ghosts should be modeled as choosing uniformly at random from their
        legal moves.
        """
        "*** YOUR CODE HERE ***"

        def max_value(state: GameState, agentIndex, depth):

            v = -float('inf')
            legalMoves = state.getLegalActions(agentIndex)
            best_move = None
            for move in legalMoves:
                successorGameState = state.generateSuccessor(agentIndex, move)
                next_agent = (agentIndex + 1) % state.getNumAgents()
                next_depth = (agentIndex + 1) // state.getNumAgents() + depth
                v1, _ = value(successorGameState, next_agent, next_depth)
                if v < v1:
                    v = v1
                    best_move = move
                # v = max(v, value(successorGameState, next_agent, next_depth,alpha,beta))
            return v, best_move

        def exp_value(state: GameState, agentIndex, depth):
            v = []

            legalMoves = state.getLegalActions(agentIndex)
            for move in legalMoves:
                successorGameState = state.generateSuccessor(agentIndex, move)
                next_agent = (agentIndex + 1) % state.getNumAgents()
                next_depth = (agentIndex + 1) // state.getNumAgents() + depth
                v1, _ = value(successorGameState, next_agent, next_depth)
                v.append(v1)
                # v = min(v, value(successorGameState, next_agent, next_depth,alpha,beta))
            return sum(v)/len(v), None

        def value(state, agentIndex, depth):
            if depth == self.depth or state.isWin() or state.isLose():
                return self.evaluationFunction(state), None
            elif agentIndex == 0:  # MAX
                return max_value(state, agentIndex, depth)
            else:
                return exp_value(state, agentIndex, depth)

        best_score, best_move = value(gameState, self.index, 0)
        return best_move
        util.raiseNotDefined()

def betterEvaluationFunction(currentGameState: GameState):

    newPos = currentGameState.getPacmanPosition()
    newFood = currentGameState.getFood()
    newGhostStates = currentGameState.getGhostStates()
    newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]
    newGhostDists = [manhattanDistance(newPos, ghostState.configuration.pos) for ghostState in newGhostStates]
    dangerScore = 0
    for i in range(len(newScaredTimes)):
        if newScaredTimes[i] == 0:
            score = -1000 if newGhostDists[i] < 2 else 0
        else:
            score = 500 / newGhostDists[i]
        dangerScore += score
    if len(newFood.asList()) > 0:
        nearestFood = (min([manhattanDistance(newPos, food) for food in newFood.asList()]))
        foodHeuristic = 9 / (nearestFood)
    else:
        foodHeuristic = 0

    # print("Action:",action,"Score:",currentGameState.getScore(),"Danger:",dangerScore,"Food:",foodHeuristic,"Total:",currentGameState.getScore()+foodHeuristic+dangerScore)
    return currentGameState.getScore() + foodHeuristic + dangerScore
    util.raiseNotDefined()

# Abbreviation
better = betterEvaluationFunction
