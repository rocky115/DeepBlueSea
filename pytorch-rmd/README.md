## Om Sree Sree Ganeshay Namoh
###OM sree Sree Hanumate Namoh

# Pytorch-rmd - Basic Implemetation of Autograd for Pytorch

Thus the new differentaton method has been applied to check the performances.
##  How to run at ide - a sample
```python
import ag as ng
from ag import nn
import numpy as np
from ag.nn.loss import BCE
from ag.nn.optim import Adam
from ag.autograd.utils import grad_check
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, accuracy_score

# load dataset (binary classification problem)
X, y = make_circles(n_samples=1000, noise=0.05, random_state=100)
X_train, X_test, y_train, y_test = train_test_split(X,y)

num_train = 750 # number of train examples
num_test = 250 # number of test examples
num_iter = 50 # number of training iterations

# convert data into tensors
X_train, X_test = ng.tensor(X_train[:num_train,:]), ng.tensor(X_test[:num_test,:])
y_train, y_test = ng.tensor(y_train[:num_train].reshape(num_train,1)), ng.tensor(y_test[:num_test].reshape(num_test,1))

# define the structure of this neural net
class NN(nn.Model):
  def __init__(self):
    self.stack = nn.Sequential(
      nn.Linear(2,100),
      nn.ReLU(),
      nn.Linear(100,1),
      nn.Sigmoid()
    )
  
  def forward(self, inputs):
    return self.stack(inputs)

model = NN() # initialize a model
loss_fn = BCE() # initialize a loss function (Binary Cross Entropy)
optim = Adam(model.parameters(), 0.05) # initialize an optimizer

# training loop
for i in range(num_iter):
  optim.zero_grad() # zero out the gradients in the tensors
  outputs = model(X_train) # get the outputs by passing the training data to your model
  loss = loss_fn(outputs, y_train) # calculate the loss
  loss.backward() # initiate the backward pass to calculate the gradients
  optim.step() # update the parameters
  print(f"iteration for {i+1}/{num_iter}\nloss: {loss}\n")

with model.eval(): # put the model in evaluation mode
  test_outputs = model(X_test) # get the outputs of the model on test data
  preds = np.where(test_outputs.data>=0.5, 1, 0) # make predictions

print(classification_report(y_test.data.astype(int).flatten(), preds.flatten()))
print(accuracy_score(y_test.data.astype(int).flatten(), preds.flatten()))

grad_check(model, X_train, y_train, loss_fn) # perform gradient checking in your model
```

Reference -  Pranav Sastry's autograd model and Karpathy's Autograd model



Copyright (c) 2023, 2024 Radhamadhab Dalai, Odisha, India
Author's email address :  dalai115@gmail.com


