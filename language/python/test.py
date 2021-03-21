#TensorFlow使用图(Graph)来表示计算任务；并使用会话(Session)来执行图，通过Session.close()来关闭会话（这是一种显式关闭会话的方式）。会话方式有显式和隐式会话之分。
import sys
sys.path.append('C:\\Users\\VonBrank\\.conda\\envs\\tf-test\\lib\\site-packages')
import tensorflow as tf
hello = tf.constant('Hello, TensorFlow!')  #初始化一个TensorFlow的常量
sess = tf.Session()  #启动一个会话
print(sess.run(hello))  