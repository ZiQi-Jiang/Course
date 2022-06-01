# search.py
# ---------
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


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util
#在searchAgents里面定义了子类实现这些抽象函数
class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()


def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s, s, w, s, w, w, s, w]

def depthFirstSearch(problem: SearchProblem):
    """
    Search the deepest nodes in the search tree first.

    Your search algorithm needs to return a list of actions that reaches the
    goal. Make sure to implement a graph search algorithm.

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:

    print("Start:", problem.getStartState())
    print("Is the start a goal?", problem.isGoalState(problem.getStartState()))
    print("Start's successors:", problem.getSuccessors(problem.getStartState()))
    """
    "*** YOUR CODE HERE ***"
    closed_list = []
    stack = util.Stack()

    start_state = problem.getStartState() # ( (x,y), Direction, cost)
    closed_list.append(start_state)

    actions = problem.getSuccessors(start_state)
    for action in actions:
        stack.push((action,[])) # (A,B): A is the action you can take at current state, and B is the path to current state.
    ########################### HOW to Stort the Path ########################
    # When DFS is Done, at each depth, the rightest node is on the path.
    #########################################################################
    while not stack.isEmpty():
        action,path = stack.pop() # get an action

        state = action[0] # get the state when apply the action
        if state not in closed_list:
            closed_list.append(state) # add the state to close list
        else:
            continue
        new_path = path[:] # you need to copy the path!!!
        new_path.append(action[1])
        # check the goal
        if problem.isGoalState(state):
            return new_path
        actions = problem.getSuccessors(state) # get the successors
        for action in actions:
            stack.push((action,new_path))
    util.raiseNotDefined()

def breadthFirstSearch(problem: SearchProblem):
    """Search the shallowest nodes in the search tree first."""
    "*** YOUR CODE HERE ***"
    closed_list = []
    queue = util.Queue()
    start_state = problem.getStartState()  # ( (x,y), Direction, cost)
    closed_list.append(start_state)

    actions = problem.getSuccessors(start_state)
    for action in actions:
        queue.push(
            (action, []))  # (A,B): A is the action you can take at current state, and B is the path to current state.
    ########################### HOW to Stort the Path ########################
    # When DFS is Done, at each depth, the rightest node is on the path.
    #########################################################################
    while not queue.isEmpty():
        action, path = queue.pop()  # get an action

        state = action[0]  # get the state when apply the action
        if state not in closed_list:
            closed_list.append(state)  # add the state to close list
        else:
            continue
        new_path = path[:]  # you need to copy the path!!!
        new_path.append(action[1])
        # check the goal
        if problem.isGoalState(state):
            return new_path
        actions = problem.getSuccessors(state)  # get the successors
        for action in actions:
            # if action[0] not in closed_list:
            queue.push((action, new_path))
    util.raiseNotDefined()

def uniformCostSearch(problem: SearchProblem):
    """Search the node of least total cost first."""
    "*** YOUR CODE HERE ***"
    closed_list = []
    queue = util.PriorityQueue()
    start_state = problem.getStartState()  # ( (x,y), Direction, cost)
    closed_list.append(start_state)

    actions = problem.getSuccessors(start_state)
    for action in actions:
        queue.update(
            (action, []),action[2])  #item: (action, path)
    ########################### HOW to Stort the Path ########################
    # When DFS is Done, at each depth, the rightest node is on the path.
    #########################################################################
    while not queue.isEmpty():
        action, path = queue.pop()  # get an action

        state = action[0]  # get the state when apply the action
        if state not in closed_list:
            closed_list.append(state)  # add the state to close list
        else:
            continue
        new_path = path[:]  # you need to copy the path!!!
        new_path.append(action[1])
        # check the goal
        if problem.isGoalState(state):
            return new_path
        actions = problem.getSuccessors(state)  # get the successors
        for new_action in actions:
            # if action[0] not in closed_list:
            cost = new_action[2] + action[2]
            queue.update(((new_action[0],new_action[1],cost), new_path),cost)
    util.raiseNotDefined()

def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0

def aStarSearch(problem: SearchProblem, heuristic=nullHeuristic):
    """Search the node that has the lowest combined cost and heuristic first."""
    "*** YOUR CODE HERE ***"
    util.raiseNotDefined()


# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
