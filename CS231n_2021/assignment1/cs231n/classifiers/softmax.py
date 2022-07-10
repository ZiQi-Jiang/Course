from builtins import range
import numpy as np
from random import shuffle
from past.builtins import xrange


def softmax_loss_naive(W, X, y, reg):
    """
    Softmax loss function, naive implementation (with loops)

    Inputs have dimension D, there are C classes, and we operate on minibatches
    of N examples.

    Inputs:
    - W: A numpy array of shape (D, C) containing weights.
    - X: A numpy array of shape (N, D) containing a minibatch of data.
    - y: A numpy array of shape (N,) containing training labels; y[i] = c means
      that X[i] has label c, where 0 <= c < C.
    - reg: (float) regularization strength

    Returns a tuple of:
    - loss as single float
    - gradient with respect to weights W; an array of same shape as W
    """
    # Initialize the loss and gradient to zero.
    loss = 0.0
    dW = np.zeros_like(W)
    
    #############################################################################
    # TODO: Compute the softmax loss and its gradient using explicit loops.     #
    # Store the loss in loss and the gradient in dW. If you are not careful     #
    # here, it is easy to run into numeric instability. Don't forget the        #
    # regularization!                                                           #
    #############################################################################
    # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****

    pass

    N = X.shape[0]
    C = W.shape[1]
    for i in range(N):
        import pdb
#         pdb.set_trace()
        res = X[i].dot(W)
        log_c = max(res)
        res = res - log_c
        res = np.exp(res)/np.sum(np.exp(res),keepdims=True)
        loss += -np.log(res[y[i]])
    loss = loss/N
            
    loss += reg*np.sum(W*W)
    
    
    for i in range(N):
        import pdb
#         pdb.set_trace()
        z = X[i].dot(W)
        a = np.exp(z) / np.sum(np.exp(z))
        a[y[i]] -=1
        dL2dZ = a
        dZ2dW = np.expand_dims(X[i],axis=1)
        dW += dL2dZ * dZ2dW

    # *****END OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
    dW /= N
    dW += 2*reg*W
    return loss, dW


def softmax_loss_vectorized(W, X, y, reg):
    """
    Softmax loss function, vectorized version.

    Inputs and outputs are the same as softmax_loss_naive.
    """
    # Initialize the loss and gradient to zero.
    loss = 0.0
    dW = np.zeros_like(W)
    N = X.shape[0]
    C = W.shape[1]
    #############################################################################
    # TODO: Compute the softmax loss and its gradient using no explicit loops.  #
    # Store the loss in loss and the gradient in dW. If you are not careful     #
    # here, it is easy to run into numeric instability. Don't forget the        #
    # regularization!                                                           #
    #############################################################################
    # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****

    pass
    
    res = X.dot(W)  # N X C
    res = np.exp(res) / np.sum(np.exp(res),axis=1,keepdims=True)
    res_tmp = res[range(N),y]
    loss = -np.sum(np.log(res_tmp))
    
    
    # 分块矩阵乘法
    mask = np.zeros((N,C))
    mask[range(N),y] = 1
    tmp = res - mask
    dW += np.dot(X.T,tmp)
    dW /= N
    import pdb
#     pdb.set_trace()
    dW += 2*reg*W
    
    # *****END OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****

    return loss, dW
