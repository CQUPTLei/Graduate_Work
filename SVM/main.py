from libsvm.svmutil import *

y, x = svm_read_problem('heart_scale.txt')#读取自带数据

m = svm_train(y[:200], x[:200], '-c 5 -g 0.1')

p_label, p_acc, p_val = svm_predict(y[200:], x[200:], m)